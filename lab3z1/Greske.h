#ifndef _Greske_h_
#define _Greske_h_

#include <exception>
using namespace std;//----------------------------

class GNepostojeciMesec:public exception{
public:
	GNepostojeciMesec():exception("Unet nepostojeci mesec.\n"){}
};

class GNepostojeciDan :public exception {
public:
	GNepostojeciDan() :exception("Unet nepostojeci dan.\n") {}
};

class GNeuspesanPrenos :public exception {
public:
	GNeuspesanPrenos() :exception("Nedovoljno sredstava na racunu.\n") {}
};

#endif

