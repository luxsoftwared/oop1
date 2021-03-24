#ifndef _Bankovniracun_h_
#define _BankovniRacun_h_

#include "Osoba.h"
#include "Greske.h"
class BankovniRacun
{
	Osoba* vlasnik;
	int brRacuna;
	int iznos;
	//string valuta="";//---------------------------------------------
public:
	BankovniRacun(Osoba* vlasn, int brracuna): vlasnik(vlasn),brRacuna(brracuna),iznos(0){}
	BankovniRacun(const BankovniRacun&) = delete;
	BankovniRacun& operator=(const BankovniRacun&) = delete;

	Osoba* dohvVlasnika() const { return vlasnik; }
	int dohvBrRacuna()const  { return brRacuna; }
	int dohvIznos() const { return iznos; }

	bool prenos(int iznos, BankovniRacun& racun);

	BankovniRacun& operator+=(int iznos);
	//string dohvValutu() { return valuta; }//-------------------------------------
	virtual string dohvValutu()const  = 0;//-------------------------------apstraktna

	friend ostream& operator<<(ostream& os, const BankovniRacun& racun);
};

#endif 

