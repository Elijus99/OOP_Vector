#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "student.h"
#include "StudentDerived.h"
void ivedimas(string &GType, Vector<StudentDerived> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
void isvedimas(const Vector<StudentDerived>& ls, const Vector<StudentDerived>& vargs, int VSize, int PSize, const string &GType);
bool exist(const string &fileName);
double division(int a, int b);
int RandomNumber();
void generate(int n, const string &OutputFileName, const string &GType, Vector<StudentDerived> &ls);
void SortToGroups(Vector<StudentDerived> &ls, Vector<StudentDerived> &vargs);
void InputFromFiles(const string &fileName, int &VSize, int &PSize, Vector<StudentDerived> &ls, const string &GType);
void OutputToFiles(Vector<StudentDerived> &ls, const Vector<StudentDerived>& vargs, const string& GType, int VSize, int PSize);

#endif
