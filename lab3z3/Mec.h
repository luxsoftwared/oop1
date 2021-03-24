#ifndef _Mec_h_
#define _Mec_h_

#include "Par.h"
#include "PrivilegovaniTim.h"

enum Ishod{POBEDA_DOMACIN=0,NERESENO,POBEDA_GOST,NEODIGRAN};
extern string tekstIshoda[4];

class GNeodigranMec {
public:
	friend ostream& operator<<(ostream& os, const GNeodigranMec& n) { return os << "Mec nije odigran.\n"; }
};

class Mec
{
	Par<Tim, Tim> timovi;
	Par<int, int> poeni;
	Ishod ishod = NEODIGRAN;
	int poeni1 = 0, poeni2 = 0;//poeni bi mogli da bduu polje tima, da se prosledjuju ovde, tako bi  moglo za turnir sa vise meceva da se na kraju znaju konacni poeni
public:
	Mec( Tim& t1, Tim& t2) :timovi(t1, t2),poeni(poeni1,poeni2) {}//MEMORY LEAK
	//

	void odigraj();

	bool proveraOdigran() const { return (ishod != NEODIGRAN); }

	Par<int, int> dohvatiPoene()const;

	friend ostream& operator<<(ostream& os, const Mec& m);
};

#endif

