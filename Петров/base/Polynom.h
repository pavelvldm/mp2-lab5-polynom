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
	void CreateString();

	Polynom operator+(const Polynom &polyOut);
	Polynom& MulScalar(const int &scal);
	Polynom operator*(const Polynom &polyOut);
	double ValuePoint(double x, double y, double z);

	void ClearZero();

	void PrintPolynom();
};

