#ifndef _Sastojak_h_
#define _Sastojak_h_

#include "Namirnica.h"
#include <iostream>
using namespace std;

class Sastojak
{
	Namirnica& namirnica;//-------ubacio sam da bude referenca,umesto kopije objekta||ukoliko ima vise recepata sa istim namirnicama u razlicitim kolicinama,nema suvisnih kopija
	double kolicina;
public:
	Sastojak(Namirnica& namirnica_,double kol_):namirnica(namirnica_),kolicina(kol_){}//referenca namirnica,umesto objekta

	const Namirnica& dohvNamirnicu() const{ return namirnica; }
	double dohvKolicinu()const { return kolicina; }

	NutritivnaVrednost nutritivnaVrednost() const;
	double kalorije()const;

	friend ostream& operator<<(ostream& os, const Sastojak& s);
};

#endif

