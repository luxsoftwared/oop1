#include "Element.h"

ostream& operator<<(ostream& os, const Element& e)
{
    os << e.natpis;
    return os;
}
