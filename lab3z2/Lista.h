#ifndef _Lista_h_
#define _Lista_h_

#include <iostream>
using namespace std;

class GNepostojeciTekuci {
public:
	friend ostream& operator<<(ostream& os, const GNepostojeciTekuci& n) { return os << "Tekuci element ne postoji."; }
};

template<typename T>
class Lista
{
	struct Elem {
		T data;
		Elem* next;
		Elem(const T& d,Elem* n=nullptr):data(d),next(n) {}
	};
	Elem* prvi,*posl;
	Elem* tek, *preth;

	void isprazni();

public:
	Lista() { prvi = posl = tek = preth = nullptr; }

	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;

	~Lista() { isprazni(); }

	Lista<T>& dodaj(const T& data);

	Lista& naPrvi();
	const Lista& naPrvi() const;
	Lista& naSledeci();
	const Lista& naSledeci() const;
	bool postojiTekuci() const { return tek != nullptr; }
	const T& dohvTekuciPodatak() const;


};

template<typename T>
void Lista<T>::isprazni()
{
	for (Elem* i = prvi; i;) {
		Elem* stari = i;
		i = i->next;
		delete stari;
	}
	prvi = posl = tek = preth = nullptr;
}

template<typename T>
Lista<T>& Lista<T>::dodaj(const T& data)
{
	posl = (prvi ? posl->next : prvi) = new Elem(data);
	return *this;
}

template<typename T>
Lista<T>& Lista<T>::naPrvi()
{
	tek = prvi;
	preth = nullptr;
	return *this;
}

template<typename T>
const Lista<T>& Lista<T>::naPrvi() const
{
	tek = prvi;
	preth = nullptr;
	return *this;
}

template<typename T>
Lista<T>& Lista<T>::naSledeci()
{
	preth = tek;
	if (tek) tek = tek->next;
	return *this;
}

template<typename T>
const Lista<T>& Lista<T>::naSledeci() const
{
	preth = tek;
	if (tek) tek = tek->next;
	return *this;
}

template<typename T>
const T& Lista<T>::dohvTekuciPodatak() const
{
	if (!tek) throw GNepostojeciTekuci();
	return tek->data;
}

#endif



