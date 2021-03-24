#ifndef _Destinacija_h_
#define _Destinacija_h_

#include <iostream>
#include <string>
using namespace std;

class Destinacija
{
	string ime;
	string opis;
	double prosecna_ocena = 0;
	int br_ocena = 0;

public:
	Destinacija(string ime,string opis):ime(ime),opis(opis) {}

	void oceni(unsigned int ocena);

	string dohvNaziv()const { return ime; }
	string dohvOpis()const { return opis; }
	double dohvProsecnuOcenu() const { return prosecna_ocena; }

	bool operator>(const Destinacija& d)const;
	friend ostream& operator<<(ostream& os, const Destinacija& d);

};

#endif

