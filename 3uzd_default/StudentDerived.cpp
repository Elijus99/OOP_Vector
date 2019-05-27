#include "StudentDerived.h"
#include "functions.h"
#include "libraries.h"
#include <algorithm>

StudentDerived::StudentDerived(string GType, std::istream& in) : galutinis_(0), StudentBase(in)
{
	galutinis_ = galBalas(GType);
}

StudentDerived::StudentDerived(const StudentDerived &x2)
{
	vard = x2.vard;
	pav = x2.pav;
	nd_ = x2.nd_;
	egzaminas_ = x2.egzaminas_;
	galutinis_ = x2.galutinis_;
}

void StudentDerived::printInfo()
{
	cout << endl;
	cout << vard << " " << pav << endl;
	cout << "Namu darbu rezultatai: ";
	for (int i = 0; i < nd_.size(); i++) {
		cout << nd_[i] << " ";
	}
	cout << endl;
	cout << "Egzamino rezultatas: " << std::defaultfloat << egzaminas_ << endl;
	cout << "Galutinis balas: " << std::fixed << setprecision(2) << galutinis_ << endl;
	cout << endl;
}

double StudentDerived::galBalas(string GType)
{
	double vidurkis = 0;
	for (int j = 0; j < nd_.size(); j++)
	{
		vidurkis += nd_[j];
	}
	vidurkis = division(vidurkis, nd_.size());
	std::sort(nd_.begin(), nd_.end());
	double mediana;
	if (nd_.size() > 0) {
		if (nd_.size() % 2 == 1) {
			mediana = nd_[nd_.size() / 2];
		}
		else {
			mediana = (double)(nd_[nd_.size() / 2 - 1] + nd_[nd_.size() / 2]) / 2;
		}
	}
	else {
		mediana = 0;
	}
	double galutinis;
	if (GType == "v" || GType == "V") {
		galutinis = 0.4 * vidurkis + 0.6 * egzaminas_;
	}
	else if (GType == "m" || GType == "M") {
		galutinis = 0.4 * mediana + 0.6 * egzaminas_;
	}
	return galutinis;
}