#ifndef _LevaZagrada_h_
#define _LevaZagrada_h_
#include "Element.h"


class LevaZagrada :public Element{
public:
	LevaZagrada():Element("("){}
	char dohvOznaku()const override { return '('; }
};

#endif

