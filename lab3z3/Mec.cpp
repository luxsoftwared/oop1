#include "Mec.h"

void Mec::odigraj()
{

	int razlika = timovi.dohvPodatak1().dohvVrednostTima() - timovi.dohvPodatak2().dohvVrednostTima();
	if (razlika > 0) ishod = POBEDA_DOMACIN;
	else if (razlika == 0) ishod = NERESENO;
	else ishod = POBEDA_GOST;

	/*if (!proveraOdigran()) {
		poeni.postaviPodatak1(*(new int(0)));
		poeni.postaviPodatak2();
	}*/
	int pr1, pr2;
	switch (ishod) {
	case POBEDA_DOMACIN: 
		pr1 = 10; 
		pr2 = -10; 
		poeni.postaviPodatak1(poeni.dohvPodatak1() + 3);

		break;
	case NERESENO: 
		pr1 = pr2 = 0; 
		poeni.postaviPodatak1(poeni.dohvPodatak1() + 1);
		poeni.postaviPodatak2(poeni.dohvPodatak2() + 1);

		break;
	case POBEDA_GOST:
		pr1 = -10; 
		pr2 = 10; 
		poeni.postaviPodatak2(poeni.dohvPodatak2() + 3);
		break;
	}


	if (ishod!=NERESENO) {
		for (int i = 0, b = 0; b < timovi.dohvPodatak1().dohvBrIgraca(); i++)
			try{
				timovi.dohvPodatak1()[i].izmeniVrednost(pr1);//dodati skup ubacenih igraca, proveravati da li je i element skupa----------IZMENI
				b++;
			}
			catch(GNepostojiIgrac){}
		
		for (int i = 0, b = 0; b < timovi.dohvPodatak2().dohvBrIgraca(); i++)
			try {
				timovi.dohvPodatak2()[i].izmeniVrednost(pr2);//dodati skup ubacenih igraca, proveravati da li je i element skupa----------IZMENI
				b++;
			}
			catch (GNepostojiIgrac) {}
	}


}

Par<int, int> Mec::dohvatiPoene() const
{
	if (!proveraOdigran()) throw GNeodigranMec();
	return poeni;
}

extern string tekstIshoda[4]= { "POBEDA_DOMACIN","NERESENO","POBEDA_GOST","NEODIGRAN" };

ostream& operator<<(ostream& os, const Mec& m)
{
	os << m.timovi << tekstIshoda[m.ishod];
	return os;
}
