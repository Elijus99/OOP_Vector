#include "StudentDerived.h"
#include "functions.h"
#include "libraries.h"
#include <algorithm>

StudentDerived::StudentDerived(const string &GType, std::istream& in) : StudentBase(in), galutinis_(0)
{
	galutinis_ = galBalas(GType);
}

StudentDerived::StudentDerived(const StudentDerived &x2)
    : StudentBase(x2)
{
	galutinis_ = x2.galutinis_;
}
StudentDerived::StudentDerived(StudentDerived&& x2)
    : StudentBase(std::move(x2)), galutinis_(std::move(x2.galutinis_))
{
};

void StudentDerived::printInfo()
{
	cout << endl;
	cout << vard << " " << pav << endl;
	cout << "Namu darbu rezultatai: ";
	for (int i : nd_)
    {
		cout << i << " ";
	}
	cout << endl;
	cout << "Egzamino rezultatas: " << std::defaultfloat << egzaminas_ << endl;
	cout << "Galutinis balas: " << std::fixed << setprecision(2) << galutinis_ << endl;
	cout << endl;
}

double StudentDerived::galBalas(const string& GType)
{
	double vidurkis = 0;
	for (int j : nd_)
    {
		vidurkis += j;
	}
	vidurkis = division(vidurkis, nd_.size());
	std::sort(nd_.begin(), nd_.end());
	double mediana;
	if (!nd_.empty()) {
		if (nd_.size() % 2 == 1) {
			mediana = nd_[nd_.size() / 2];
		}
		else {
			mediana = double(nd_[nd_.size() / 2 - 1] + nd_[nd_.size() / 2]) / 2;
		}
	}
	else {
		mediana = 0;
	}
	double galutinis = 0;
	if (GType == "v" || GType == "V") {
		galutinis = 0.4 * vidurkis + 0.6 * egzaminas_;
	}
	else if (GType == "m" || GType == "M") {
		galutinis = 0.4 * mediana + 0.6 * egzaminas_;
	}
	return galutinis;
}
