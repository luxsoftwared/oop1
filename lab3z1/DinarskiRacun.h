#ifndef _DinarskiRacun_h_
#define _DianrskiRacun_h_

#include "BankovniRacun.h"

class DinarskiRacun :public BankovniRacun
{
public:
	DinarskiRacun(Osoba* vlasn, int brracuna) :BankovniRacun(vlasn, brracuna) {}
	string dohvValutu()const override { return "RSD"; }
};

#endif

