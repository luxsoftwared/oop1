#ifndef _Sabiranje_h_
#define _Sabiranje_h_
#include "BinarniOperator.h"


class Sabiranje :public BinarniOperator{
public:
	Sabiranje():BinarniOperator("+") {}
	int dohvPrioritet()const override { return 1; }
};

#endif

