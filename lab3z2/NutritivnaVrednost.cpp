#include "NutritivnaVrednost.h"
#include "Greske.h"

NutritivnaVrednost::NutritivnaVrednost(double ugljeni_hidrati, double mast, double proteini) {
	if (ugljeni_hidrati < 0 || mast < 0 || proteini < 0) throw GNepostojeceNutritivneVr();
	ugljenih = ugljeni_hidrati;
	masti = mast;
	protein = proteini;
}

NutritivnaVrednost NutritivnaVrednost::operator+(NutritivnaVrednost n)
{
	return NutritivnaVrednost{ ugljenih + n.ugljenih,masti + n.masti,protein + n.protein };
}

double NutritivnaVrednost::kalorije()
{
	return (ugljenih + protein) * 4 + masti * 9;
}

ostream& operator<<(ostream& os, const NutritivnaVrednost& n)
{
	os << "[uh:" << n.ugljenih << ", ma:" << n.masti << ", pr:" << n.protein << "]";
	return os;
}
