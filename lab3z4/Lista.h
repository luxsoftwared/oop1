#ifndef _Lista_h_
#define _Lista_h_

#include "Greske.h"
#include <iostream>
using namespace std;

template<typename T>
class Lista
{
	struct Elem {
		T* data;
		Elem* next;
		Elem(T* data,Elem* next=nullptr):data(data),next(next){}
	};
	Elem* prvi, *poslednji;
	int br_podataka = 0;
public:
	Lista():prvi(nullptr),poslednji(nullptr){}

	void operator+=(const T& t);
	T operator-();
	T operator*();

	int dohvBrPodataka()const { return br_podataka; }
	friend ostream& operator<<(ostream& os, const Lista& l);

};

#endif

template<typename T>
inline void Lista<T>::operator+=(const T& t)
{
	poslednji=(prvi?poslednji->next:prvi)=new Elem(new T(t));//dinamicki za elem, pa dinamicki za kopiju od t
	br_podataka++;
}

template<typename T>
inline T Lista<T>::operator-()
{
	if (!prvi) throw GPrazna();
	Elem* i = prvi;
	for (; i->next && i->next != poslednji; i = i->next);
	i->next = nullptr;
	if (prvi == poslednji) prvi = i=nullptr;
	T t = *(poslednji->data);
	delete poslednji->data;
	delete poslednji;
	poslednji = i;
	br_podataka--;
	return t;
}

template<typename T>
inline T Lista<T>::operator*()
{
	if (!prvi) throw GPrazna();
	Elem* stari = prvi;
	prvi = prvi->next;
	T t = *(stari->data);
	delete stari;
	br_podataka--;
	return t;
}

template<typename T>
ostream& operator<<(ostream& os, const Lista<T>& l) {
	Lista<T>::Elem* j = l.prvi;
	for (; j; j = j->next) {
		os << *(j->data) << " ";
	}
	return os;
}
