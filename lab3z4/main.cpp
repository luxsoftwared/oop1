#include "Izraz.h";
#include "DesnaZagrada.h"
#include "LevaZagrada.h"
#include "Sabiranje.h"
#include "Operand.h"

int main() {
	Izraz izraz;
	izraz += LevaZagrada();
	izraz += Operand("aa");
	izraz += Sabiranje();
	izraz += Operand("bb");
	izraz += DesnaZagrada();
	cout << izraz;

}