#ifndef _Osoba_h_
#define _Osoba_h_

#include "Datum.h"
#include <string>
using namespace std;
class Osoba
{
	string ime;
	string maticni;
	Datum datum;
public:

	Osoba(string i,string m,Datum d):ime(i),maticni(m),datum(d){}
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba&) = delete;

	string dohvIme()const { return ime; }
	string dohvMaticni()const { return maticni; }
	Datum dohvDatum() const{ return datum; }

	friend ostream& operator<<(ostream& os, const Osoba& o);

};

#endif

