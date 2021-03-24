#include "Tim.h"

void Tim::kopiraj(const Tim& t)
{
    ime=t.ime;
    maksIgraca=t.maksIgraca;
    brIgraca = t.brIgraca;
    UkupnavrednostTima = t.UkupnavrednostTima;
    igraci = new Igrac * [maksIgraca];
    for (int i = 0; i < maksIgraca;i++) {
        igraci[i] = t.igraci[i];
    }
}

void Tim::premesti(Tim& t)
{
    ime = t.ime;
    maksIgraca = t.maksIgraca;
    brIgraca = t.brIgraca;
    UkupnavrednostTima = t.UkupnavrednostTima;
    igraci = t.igraci;
    t.igraci = nullptr;
    maksIgraca = brIgraca = UkupnavrednostTima=0;
}

void Tim::izbrisi()
{
    delete[] igraci;
}

ostream& Tim::ispis(ostream& os) const
{
    os << ime << "[";
    int i, br;
    //sa zarezima
    for (i = 0, br = 0; i < maksIgraca && br < brIgraca - 1; i++) {
        if (igraci[i]) {
            os << *(igraci[i]) << ",";
            br++;
        }
    }
    //poslednji bez zareza
    for (; i < maksIgraca; i++) {
        if (igraci[i]) {
            os << *(igraci[i]) << "]";
            break;
        }
    }
    return os;
}

Tim& Tim::operator=(const Tim& t)
{
    if (this != &t) {
        izbrisi();
        kopiraj(t);
    }
    return *this;
}

Tim& Tim::operator=(Tim&& t)
{
    if (this != &t) {
        izbrisi();
        premesti(t);
    }
    return *this;
}

Tim& Tim::dodajIgraca(const Igrac& i, int pozicija)
{
    //ako na toj poziciji vec ima igrac
    if (igraci[pozicija]) {
        UkupnavrednostTima -= igraci[pozicija]->dohvVrednost();
    }
    else{brIgraca++;}

    UkupnavrednostTima += i.dohvVrednost();
    igraci[pozicija] = (Igrac*)&i;//da li je okej???---------------------------------------------------
    return *this;

}

const Igrac& Tim::operator[](int pozicija) const
{
    if (igraci[pozicija]) return *(igraci[pozicija]);
    else throw GNepostojiIgrac();
}

Igrac& Tim::operator[](int pozicija)
{
    if (igraci[pozicija]) return *(igraci[pozicija]);
    else throw GNepostojiIgrac();
}

bool Tim::operator==(const Tim& t) const
{
    if (ime == t.ime && maksIgraca == t.maksIgraca) {
        bool igraciJednaki = true;
        for (int i = 0; i < maksIgraca; i++) {
            if (igraci[i] != t.igraci[i]) {
                igraciJednaki = false;
                break;
            }
        }
        return igraciJednaki;
    }
    else return false;
}

ostream& operator<<(ostream& os, const Tim& t)
{
    return t.ispis(os);
}
