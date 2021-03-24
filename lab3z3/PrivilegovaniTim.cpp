#include "PrivilegovaniTim.h"

ostream& PrivilegovaniTim::ispis(ostream& os) const
{
    os << ime <<"("<<minVrednost<<")"<< "[";
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

Tim& PrivilegovaniTim::dodajIgraca(const Igrac& i, int pozicija)
{
    if (i.dohvVrednost() < minVrednost) throw GNedovoljnaVrednost();
    Tim::dodajIgraca(i, pozicija);
    return *this;
}
