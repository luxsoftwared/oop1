#include "Datum.h"
#include "Greske.h"

Datum::Datum(int d, int m, int g)
{
	/*switch(m){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
		if (d < 1 || d>31) throw GNepostojeciDan();
		break;
	case 4: case 6: case 9: case 11:
		if (d < 1 || d>30) throw GNepostojeciDan();
		break;
	case 2:
		if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) {
			if (d < 1 || d>29) throw GNepostojeciDan();
		}else if (d < 1 || d>29) throw GNepostojeciDan();

	default:throw GNepostojeciMesec();
	}*/

	int dana_u_mesecu=0;
	switch (m) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:	dana_u_mesecu = 31;	break;
	case 4: case 6: case 9: case 11:							dana_u_mesecu = 30;	break;
	case 2:
		if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) { dana_u_mesecu = 29; }
		else dana_u_mesecu = 28;
		break;
	default:throw GNepostojeciMesec();
	}

	if (d<1 || d>dana_u_mesecu) throw GNepostojeciDan();

	dan = d;
	mesec = m;
	godina = g;
}

bool Datum::operator==(const Datum& d)
{
	return (dan == d.dan && mesec == d.mesec && godina == d.godina);
}

ostream& operator<<(ostream& os, const Datum& d)
{
	os << d.dan << "." << d.mesec << "." << d.godina << ".";
	return os;
}
