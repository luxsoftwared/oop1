#ifndef _Igrac_h_
#define _Igrac_h_

#include <iostream>
#include <string>
using namespace std;

class Igrac
{
	string ime;
	mutable int vrednost;

public:
	Igrac(string ime,int vrednost=1000):ime(ime),vrednost(vrednost){}


	string dohvIme() const { return ime; }
	int dohvVrednost() const { return vrednost; }

	const Igrac& izmeniVrednost(double procenat)const;

	bool operator==(const Igrac& i) const;
	friend ostream& operator<<(ostream& os, const Igrac& i);

};

#endif

