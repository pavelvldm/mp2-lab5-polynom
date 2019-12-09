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
	Polynom(string &s);
	Polynom(const Polynom &polyOut);
	~Polynom();

	void CreatePolynom(string &s);
	string CreateString();

	Polynom& operator+=(const Polynom &polyOut);
	Polynom operator+(const Polynom &polyOut);
	Polynom& operator*(const int &scal);
	Polynom& operator*=(const Polynom &polyOut);
	Polynom operator*(const Polynom &polyOut);
	double ValuePoint(const double &x, const double &y, const double &z);

	Polynom& operator=(const Polynom &polyOut);
	bool operator==(const Polynom &polyOut) const;
	bool operator!=(const Polynom &polyOut) const;

	void ClearZero();

	friend istream& operator>>(istream &in, Polynom &polyOut);
	friend ostream& operator<<(ostream &out, Polynom &polyOut);
};

