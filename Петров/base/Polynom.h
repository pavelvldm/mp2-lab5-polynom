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
	//Polynom(const Polynom &polyOut);
	~Polynom();

	void CreatePolynom(string &s);
	string CreateString();

	Polynom& operator+=(const Polynom &polyOut);
	Polynom operator+(const Polynom &polyOut);
	Polynom& MulScalar(const int &scal);
	Polynom operator*(const Polynom &polyOut);
	double ValuePoint(double x, double y, double z);

	Polynom& operator=(const Polynom &polyOut);

	void ClearZero();

	void PrintPolynom();
};

