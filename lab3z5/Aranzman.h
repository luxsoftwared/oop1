#ifndef _Aranzman_h_
#define _Aranzman_h_

#include "Destinacija.h"
#include "Datum.h"
#include "Smestaj.h"
#include "Prevoz.h"

class Aranzman
{
	Destinacija* destinacija;
	Datum pocetak;
	Datum kraj;
	Smestaj* smestaj = nullptr;;
	Prevoz* prevoz=nullptr;

public:
	Aranzman(Destinacija& destinacija, Datum pocetak, Datum kraj) :destinacija(&destinacija), pocetak(pocetak), kraj(kraj) {}

	void dodajSmestaj(Smestaj& s);
	void dodajPrevoz(Prevoz& p);

	const Destinacija* dohvDestinaciju()const { return destinacija; }
	const Datum& dohvDatumPocetka() const{ return pocetak; }
	const Datum& dohvDatumKraja() const{ return kraj; }

	int trajanjeAranzmana()const { return kraj - pocetak; }
	double cenaAranzmana()const;

	friend ostream& operator<<(ostream& os, const Aranzman& a);


};

#endif

