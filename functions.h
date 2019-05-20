#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iomanip>
#include <iostream>
#include <chrono>
#include <vector>
#include "vector.h"
using std::cout;
using std::endl;

void runPushback(std::vector<int> A, size_t n, int& loc);
void runPushback(Vector<int> A, size_t n, int& loc);
#endif
