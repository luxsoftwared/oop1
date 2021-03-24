#include "Sastojak.h"
#include "Lista.h"
int main() {
	try {
		//verzija kad sastpjak sadrzi referencu na namirnicu
		Namirnica n1("Hleb", NutritivnaVrednost(50, 20, 10), true);
		Namirnica n2("MLeko", NutritivnaVrednost(40, 20, 20), true);
		Namirnica n3("Kajmak", NutritivnaVrednost(25, 40, 25), true);
		Sastojak s1(n1, 200);
		Sastojak s2(n2, 150);
		Sastojak s3(n3, 100);
		//verzija kad sastojak sadrzi objekat namirnicu
		/*
		Sastojak s1(Namirnica("Hleb", NutritivnaVrednost(50, 20, 10), true), 200);
		Sastojak s2(Namirnica("MLeko", NutritivnaVrednost(40, 20, 20), true), 150);
		Sastojak s3(Namirnica("Kajmak", NutritivnaVrednost(25, 40, 25), true), 100);
		*/

		//cout << s;

		Lista<Sastojak> recept;
		recept.dodaj(s1).dodaj(s2).dodaj(s3);
		
		for (recept.naPrvi(); recept.postojiTekuci(); recept.naSledeci()) { cout << recept.dohvTekuciPodatak() << endl; }

		Lista<Sastojak> fejk;
		//Sastojak probni = fejk.dohvTekuciPodatak();

	}
	catch (exception e) {//---------------------------IZBACI OVO
		cout << e.what();
	}
	catch (GNepostojeciTekuci n) {
		cout << n;
	}

}