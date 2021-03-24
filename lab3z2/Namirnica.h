#ifndef _Namirinica_h_
#define _Namirnica_h_

#include "NutritivnaVrednost.h"
#include <string>
#include <iostream>
using namespace std;

class Namirnica
{
	string naziv;
	NutritivnaVrednost nutritivna;
	bool posna;
public:
	Namirnica(string ime, NutritivnaVrednost nutritivnaVr, bool posna_):naziv(ime), nutritivna(nutritivnaVr),posna(posna_){}//proveri prekoracuje li 100g

	string dohvIme()const { return naziv; }
	NutritivnaVrednost dohvNutritivnu() const { return nutritivna; }
	bool dohvPosn() { return posna; }

	bool operator==(Namirnica n)const; //proveri ovo-------------------
	friend ostream& operator<<(ostream& os, const Namirnica& n);
};

#endif

