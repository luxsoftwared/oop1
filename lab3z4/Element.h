#ifndef _Element_h_
#define _Element_h_

#include <string>
using namespace std;

class Element
{
protected:
	string natpis;
public:
	Element(string natpis):natpis(natpis){}
	//polimorfna kopija??------------------------------------

	string dohvNatpis()const { return natpis; }
	virtual char dohvOznaku() const = 0;

	friend ostream& operator<<(ostream& os, const Element& e);
};

#endif

