#include "Osoba.h"

ostream& operator<<(ostream& os, const Osoba& o)
{
    os << "O(" << o.ime << "," << o.maticni << "," << o.datum << ")";
    return os;
}
