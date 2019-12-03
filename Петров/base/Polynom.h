#pragma once

#include "List.h"
#include <string>

using namespace std;

const int MAX_POLYNOM_POW = 10;

class Polynom
{
	List<double> coef;
public:
	Polynom();
	~Polynom();

	void CreatePolynom(string &s);

	void PrintPolynom();
};

