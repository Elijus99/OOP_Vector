#pragma once
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "libraries.h"

class StudentBase {
protected:
	string vard;
	string pav;
	Vector<int> nd_;
	double egzaminas_;
	StudentBase() : vard(""), pav(""), egzaminas_(0) {} //default constructor
	StudentBase(std::istream& in); //constructor
public:
	StudentBase(const StudentBase &x2); //copy constructor
	StudentBase& operator=(const StudentBase& other) {
		this->vard = other.vard;
		this->pav = other.pav;
		this->nd_ = other.nd_;
		this->egzaminas_ = other.egzaminas_;
		return *this;
	}; //copy assignment operator
	~StudentBase() = default; //default destructor

	void setVardas(string name) { vard = name; }
	void setPav(string surname) { pav = surname; }
	void setEgz(double egzaminas) { egzaminas_ = egzaminas; }
	void setNd(Vector<int> nd) { nd_ = nd; }
	void clearNd() { nd_.clear(); }
	inline string vardas() const { return vard; }
	inline string pavarde() const { return pav; }
	inline double egzaminas() const { return egzaminas_; }
	inline Vector<int> nd() const { return nd_; }
	StudentBase readStudent(std::istream& in);
};

bool compareAlphabet(const StudentBase& a, const StudentBase& b);

#endif
