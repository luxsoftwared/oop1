#include "Sastojak.h"

NutritivnaVrednost Sastojak::nutritivnaVrednost() const
{
    return NutritivnaVrednost(namirnica.dohvNutritivnu().dohvUgljene()*kolicina/100,namirnica.dohvNutritivnu().dohvMasti()*kolicina/100,namirnica.dohvNutritivnu().dohvProteine()*kolicina/100);
}

double Sastojak::kalorije() const
{
    return nutritivnaVrednost().kalorije();
}

ostream& operator<<(ostream& os, const Sastojak& s)
{
    os << "[" << s.kalorije() << "kcal]" << s.kolicina << "g x " << s.namirnica;
    return os;
}
