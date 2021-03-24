#include "DinarskiRacun.h"
using namespace std;

int main() {
	try {
		Osoba o("Luka", "0211000710025", Datum(02, 11, 2000));
		DinarskiRacun racun(&o, 5);
		DinarskiRacun racun2(&o, 6);
		racun += 200;
		racun.prenos(50, racun2);
		racun.prenos(200, racun2);
		cout << o << endl;
		cout << racun << endl;
		cout << racun2 << endl;
		Osoba o2("as", "5456", Datum(30, 2, 2000));
	}
	catch (exception e)
	{
		cout << e.what();
	}

	return 0;
}