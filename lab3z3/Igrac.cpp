#include "Igrac.h"

const Igrac& Igrac::izmeniVrednost(double procenat)const
{
    vrednost += procenat / 100 * vrednost;
    return *this;
}

bool Igrac::operator==(const Igrac& i) const
{
    return (ime == i.ime && vrednost == i.vrednost);
}

ostream& operator<<(ostream& os, const Igrac& i)
{
    os << i.ime << "#" << i.vrednost;
    return os;
}
