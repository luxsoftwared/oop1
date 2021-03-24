#include "Aranzman.h"


void Aranzman::dodajSmestaj(Smestaj& s)
{
	if (s.dohvDestinaciju() != destinacija) throw GPogresnaDestinacija();
	smestaj = &s;
}

void Aranzman::dodajPrevoz(Prevoz& p)
{
	if (p.dohvDestinaciju() != destinacija) throw GPogresnaDestinacija();
	prevoz = &p;
}

double Aranzman::cenaAranzmana() const
{
	if (smestaj == nullptr || prevoz == nullptr) throw GNedodeljeniSmestajPrevoz();
	return trajanjeAranzmana() * (smestaj->dohvCenu()) + prevoz->dohvCenuPrevoza();;
}

ostream& operator<<(ostream& os, const Aranzman& a)
{
	os << *a.destinacija << endl;
	os << *a.smestaj << endl;
	os << a.cenaAranzmana();
	return os;
}
