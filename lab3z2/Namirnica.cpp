#include "Namirnica.h"

bool Namirnica::operator==(Namirnica n) const
{
    return naziv==n.naziv;
}

ostream& operator<<(ostream& os, const Namirnica& n)
{
    os << n.naziv << " - " << n.nutritivna;
    return os;
}
