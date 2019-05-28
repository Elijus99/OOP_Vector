#pragma once
#include "student.h"
class StudentDerived : public StudentBase
{
private:
	double galutinis_;
public:
	StudentDerived() : galutinis_(0) {}
	StudentDerived(const string &GType, std::istream& in);
	StudentDerived(const StudentDerived& x2);
    StudentDerived(StudentDerived&& x2);
	StudentDerived& operator=(const StudentDerived& other) {
		this->vard = other.vard;
		this->pav = other.pav;
		this->nd_ = other.nd_;
		this->egzaminas_ = other.egzaminas_;
		this->galutinis_ = other.galutinis_;
		return *this;
	};
    bool operator==(const StudentDerived& other) {
        if (nd_.size() == other.nd_.size()) {
            for (int i = 0; i < nd_.size(); i++) {
                if (nd_[i] != other.nd_[i]) return false;
            }
            if (egzaminas_ != other.egzaminas_) return false;
            if (galutinis_ != other.galutinis_) return false;
            if (vard != other.vard) return false;
            if (pav != other.pav) return false;
            return true;
        }
        return false;
    };
    bool operator!= (const StudentDerived& other) {
        return !operator==(other);
    }
    bool operator< (const StudentDerived& rhs) {
        if (this->galutinis_ < rhs.galutinis_) return true;
        else return false;
    }
    bool operator> (const StudentDerived& rhs) {
        if (this->galutinis_ > rhs.galutinis_) return true;
        else return false;
    }
    bool operator<= (const StudentDerived& rhs) {
        if (this->galutinis_ <= rhs.galutinis_) return true;
        else return false;
    }
    bool operator>= (const StudentDerived& rhs) {
        if (this->galutinis_ >= rhs.galutinis_) return true;
        else return false;
    }

	~StudentDerived() = default;
	void setGal(double gal) { galutinis_ = gal; }
	inline double galutinis() const { return galutinis_; }
	void printInfo();
	double galBalas(const string& GType);
};

