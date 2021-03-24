#ifndef _Datum_h_
#define _Datum_h_

#include <iostream>
using namespace std;

class Datum{
	int dan, mesec, godina;

public:
	Datum(int d = 1, int m = 1, int g = 2021);

	bool operator==(const Datum& d);

	friend ostream& operator<<(ostream& os, const Datum& d);

};

#endif

