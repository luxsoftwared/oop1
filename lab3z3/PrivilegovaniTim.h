#ifndef _PrivilegovaniTim_h_
#define _PrivilegovaniTim_h_


#include "Tim.h"

class GNedovoljnaVrednost {
public:
	friend ostream& operator<<(ostream& os, const GNedovoljnaVrednost& g) { return os << "Igrac nema dovoljnu vrednost za dodavanje u tim."; }
};

class PrivilegovaniTim :public Tim{
	int minVrednost;
	ostream& ispis(ostream& os) const override;
public:
	PrivilegovaniTim(string ime, int maxIgraca, int minimalna) :Tim(ime,maxIgraca),minVrednost(minimalna) {}

	//PrivilegovaniTim(const PrivilegovaniTim& p) :Tim(p), minVrednost(p.minVrednost) {}

	Tim& dodajIgraca(const Igrac& i, int pozicija) override;


};

#endif

