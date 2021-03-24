#ifndef _Datum_h_
#define _Datum_h_

#include "Greska.h"
#include <iostream>
using namespace std;


class Datum
{
	int dan, mesec, godina;
public:
	Datum(int d, int m, int g);

	int operator-(const Datum& d)const;//?????????????????????

	int dohvDan()const { return dan; }
	int dohvMesec()const { return mesec; }
	int dohvGodinu()const { return godina; }

	friend ostream& operator<<(ostream& os, const Datum& d);

};

#endif

