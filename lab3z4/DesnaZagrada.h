#ifndef _DesnaZagrada_h_
#define _DesnaZagrada_h_
#include "Element.h"


class DesnaZagrada :public Element {
public:
	DesnaZagrada() :Element(")") {}
	char dohvOznaku()const override { return ')'; }
};

#endif
