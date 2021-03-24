#ifndef _Operand_h_
#define _Operand_h_

#include "Element.h"


class Operand :public Element{
public:
	Operand(string natpis):Element(natpis){}

	char dohvOznaku()const override { return 'D'; }

};

#endif

