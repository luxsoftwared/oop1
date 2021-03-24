#include "Izraz.h"

void Izraz::operator+=(const Element& e)
{
	lista += e;
}

ostream& operator<<(ostream& os, const Izraz& i)
{
	os << i.lista;
	return os;
}
