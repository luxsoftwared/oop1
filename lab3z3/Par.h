#ifndef _Par_h_
#define _Par_h_

#include <iostream>
using namespace std;

template<typename T,typename P>
class Par
{
	T* podatak1;
	P* podatak2;
public:
	Par(const T& p1,const P& p2) :podatak1((T*)&p1), podatak2((P*)&p2) {}

	T& dohvPodatak1() const{ return *podatak1; }
	P& dohvPodatak2()const { return *podatak2; }
	T& postaviPodatak1(const T& p1) { *podatak1 = p1; return *podatak1; }
	P& postaviPodatak2(const P& p2) { *podatak2 = p2; return *podatak1; }

	bool operator==(const Par& p)const { return (*podatak1 == *(p.podatak1) && *podatak2 == *(p.podatak2)); }

	friend ostream& operator<<(ostream& os, const Par& p) { return os << "[" << *(p.podatak1) << "-" << *(p.podatak2) << "]"; }

};

#endif
