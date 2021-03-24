#include "Destinacija.h"

void Destinacija::oceni(unsigned int ocena)
{
	if (ocena <= 5) {
		prosecna_ocena = ((prosecna_ocena * br_ocena + ocena) / (br_ocena+1));
		br_ocena++;
	}
}

bool Destinacija::operator>(const Destinacija& d) const
{
	return prosecna_ocena>d.prosecna_ocena;
}

ostream& operator<<(ostream& os, const Destinacija& d)
{
	os << "[" << d.prosecna_ocena << "]" << d.ime << "(" << d.opis << ")";
	return os;
}
