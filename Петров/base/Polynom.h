#pragma once

#include "List.h"
#include <string>

using namespace std;

class Polynom
{
	List<double> coef;
public:
	Polynom();
	~Polynom();

	void CreatePolynom(string &s);
	
};

