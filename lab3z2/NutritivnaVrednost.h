#ifndef _NutritivnaVrednost_h_
#define _NutritivnaVrednost_h_

#include <iostream>
using namespace std;

class NutritivnaVrednost
{
	double ugljenih, masti, protein;
public:
	NutritivnaVrednost(double ugljeni_hidrati, double mast, double proteini);

	double dohvUgljene() const { return ugljenih; }
	double dohvMasti() const { return masti; }
	double dohvProteine() const { return protein; }

	NutritivnaVrednost operator+(NutritivnaVrednost n);

	double kalorije();

	friend ostream& operator<<(ostream& os, const NutritivnaVrednost& n);

};

#endif

