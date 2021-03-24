#ifndef _Greske_h_
#define _Greske_h

#include <exception>
using namespace std;

class GNepostojeceNutritivneVr:public exception
{
public:
	GNepostojeceNutritivneVr():exception("Uneta negativna tezina nutritivnih vrednosti.\n"){}
};

#endif

