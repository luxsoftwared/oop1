#ifndef _Tim_h
#define _Tim_h

#include "Igrac.h"


class GNepostojiIgrac {
public:
	friend ostream& operator<<(ostream& os, const GNepostojiIgrac& n) { return os << "Ne postoji igrac."; }
};

class Tim
{
protected:
	string ime;
	int maksIgraca;
	int brIgraca = 0;
	int UkupnavrednostTima = 0;
	Igrac * *igraci = nullptr;

	void kopiraj(const Tim& t);
	void premesti(Tim&);
	void izbrisi();
	virtual ostream& ispis(ostream& os)const;

public:
	Tim(string ime,int maxIgraca):ime(ime),maksIgraca(maxIgraca){
		igraci = new Igrac *[maxIgraca];//da li su null pointeri
		for (int i = 0; i < maksIgraca; i++) igraci[i] = nullptr;
	}

	Tim(const Tim& t) { kopiraj(t); }
	Tim(Tim&& t) { premesti(t); }
	~Tim() { izbrisi(); }
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);

	virtual Tim& dodajIgraca(const Igrac& i, int pozicija);

	int dohvBrIgraca()const { return brIgraca; }
	const Igrac& operator[](int pozicija) const;
	Igrac& operator[](int pozicija);

	int dohvVrednostTima()const { return (double)UkupnavrednostTima / brIgraca; }
	bool operator==(const Tim& t)const;

	friend ostream& operator<<(ostream& os, const Tim& t);

};

#endif

