#include "Datum.h"
//#include <cmath>

Datum::Datum(int d, int m, int g)
{
	int gornja_granica = 0;
	switch (m) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: gornja_granica = 31; break;
	case 4: case 6: case 9: case 11: gornja_granica = 30;	break;
	case 2:
		if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) gornja_granica = 29;
		else gornja_granica = 28;
		break;
	default:
		throw GNepostojeciMesec();
	}

	if (d<1 || d>gornja_granica) throw GNeposotjeciDan();
	dan = d;
	mesec = m;
	godina = g;
}

int Datum::operator-(const Datum& d) const
{
	 int dani1, dani2;
	dani1 = (godina - 1) * 365 + (godina - 1) / 4 - (godina - 1) / 100 + (godina - 1) / 400;
	dani2 = (d.godina - 1) * 365 + (d.godina - 1) / 4 - (d.godina - 1) / 100 + (d.godina - 1) / 400;
	
	int inc1 = 0;
	switch (mesec - 1)
	{
	case 11:inc1 += 30;
	case 10:inc1 += 31;
	case 9:inc1 += 30;
	case 8:inc1 += 31;
	case 7:inc1 += 31;
	case 6:inc1 += 30;
	case 5:inc1 += 31;
	case 4:inc1 += 30;
	case 3:inc1 += 31;
	case 2:
		if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) inc1 += 29;
		else inc1 += 28;
	case 1:inc1 += 31;
	}

	int inc2 = 0;
	switch (d.mesec - 1)
	{
	case 11:inc2 += 30;
	case 10:inc2 += 31;
	case 9:inc2 += 30;
	case 8:inc2 += 31;
	case 7:inc2 += 31;
	case 6:inc2 += 30;
	case 5:inc2 += 31;
	case 4:inc2 += 30;
	case 3:inc2 += 31;
	case 2:
		if (d.godina % 4 == 0 && d.godina % 100 != 0 || d.godina % 400 == 0) inc2 += 29;
		else inc2 += 28;
	case 1:inc2 += 31;
	}

	dani1 += inc1;
	dani2 += inc2;
	dani1 += dan;
	dani2 += d.dan;

	return abs(dani1 - dani2);
}

ostream& operator<<(ostream& os, const Datum& d)
{
	os << d.dan << "." << d.mesec << "." << d.godina << ".";
	return os;
}
