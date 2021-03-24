#ifndef _Greske_h_
#define _Greske_h_

#include <exception>
using namespace std;

class GPrazna:public exception
{
public:
	GPrazna() :exception("Lista je prazna.\n") {}
};


#endif

