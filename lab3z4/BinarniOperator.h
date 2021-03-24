#ifndef _BinarniOperator_h_
#define _BinarniOperator_h_


#include "Element.h"


class BinarniOperator :public Element{
public:
	//konstruktor
	BinarniOperator(string natpis) :Element(natpis){}

	virtual int dohvPrioritet()const = 0;

	bool operator>(const BinarniOperator& b) const { return dohvPrioritet() > b.dohvPrioritet(); }
	char dohvOznaku()const override { return 'O'; }

};

#endif

