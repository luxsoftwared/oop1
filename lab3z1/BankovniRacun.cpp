#include "BankovniRacun.h"

bool BankovniRacun::prenos(int iznos, BankovniRacun& racun)try
{
	if (iznos > this->iznos) throw GNeuspesanPrenos();
	this->iznos -= iznos;
	racun.iznos += iznos;
	return true;
}
catch (std::exception e)
{
	cout << e.what();
	return false;
}


BankovniRacun& BankovniRacun::operator+=(int iznos)
{
	this->iznos += iznos;
	return *this;
}

ostream& operator<<(ostream& os, const BankovniRacun& racun)
{
	os << "R:" << racun.brRacuna << ":=:" << racun.iznos << "-" << racun.dohvValutu();//-----------------------
	return os;
}
