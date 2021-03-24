
#include "Igrac.h"
#include "Mec.h"

int main() {
	try {
		Igrac i1("Luka Djokic", 900);
		Igrac i2("Luka Tanasic", 1200);
		Igrac i3("Lazar Vukovic");
		Igrac i4("Mika");
		Igrac i5("Zika");
		Igrac i6("Pera");
		Igrac i7("Izbacen", 100);

		Tim t1("Pozezani", 5);
		PrivilegovaniTim t2("Rendom", 3, 500);

		t1.dodajIgraca(i1, 1).dodajIgraca(i2, 3).dodajIgraca(i3, 2);
		//t2.dodajIgraca(i7, 0);
		t2.dodajIgraca(i4, 0).dodajIgraca(i5, 1).dodajIgraca(i6, 2);
		Mec mec(t1, t2);
		//cout<<mec.dohvatiPoene();
		mec.odigraj();

		cout << mec << endl;
		cout << mec.dohvatiPoene();
	}catch(GNedovoljnaVrednost g1){
		cout << g1;
	}
	catch (GNeodigranMec g2) { cout << g2; }
	catch (GNepostojiIgrac g3) { cout << g3; }
	
}