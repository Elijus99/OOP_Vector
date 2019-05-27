#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "student.h"
#include "StudentDerived.h"
void ivedimas(string &GType, std::vector<StudentDerived> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
void isvedimas(std::vector<StudentDerived> ls, std::vector<StudentDerived> vargs, int VSize, int PSize, string GType);
bool exist(string fileName);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::vector<StudentDerived> &ls);
void SortToGroups(std::vector<StudentDerived> &ls, std::vector<StudentDerived> &vargs);
void InputFromFiles(string fileName, int &VSize, int &PSize, std::vector<StudentDerived> &ls, string GType);
void OutputToFiles(std::vector<StudentDerived> &ls, std::vector<StudentDerived> vargs,string GType, int VSize, int PSize);

#endif