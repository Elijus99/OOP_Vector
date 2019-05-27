#pragma once
#include "student.h"
class StudentDerived : public StudentBase
{
private:
	double galutinis_;
public:
	StudentDerived() : galutinis_(0) {}
	StudentDerived(string GType, std::istream& in);
	StudentDerived(const StudentDerived &x2);
	StudentDerived& operator=(const StudentDerived& other) {
		this->vard = other.vard;
		this->pav = other.pav;
		this->nd_ = other.nd_;
		this->egzaminas_ = other.egzaminas_;
		this->galutinis_ = other.galutinis_;
		return *this;
	};
	~StudentDerived() = default;
	void setGal(double gal) { galutinis_ = gal; }
	inline double galutinis() const { return galutinis_; }
	void printInfo();
	double galBalas(string GType);
};

