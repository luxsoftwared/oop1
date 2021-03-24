#ifndef _Izraz_h_
#define _Izraz_h_
#include "Lista.h"
#include "Element.h"
class Izraz
{
	Lista<Element> lista;
public:
	Izraz() = default;
	//Izraz(const Izraz& i);//polimorfna kopija???

	void operator+=(const Element&);

	friend ostream& operator<<(ostream& os, const Izraz& i);
};

#endif

