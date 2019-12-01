#include <gtest.h>

#include "Polynom.h"
#include "List_Metd.cpp"
#include "Polynom_Metd.cpp"

TEST(Polynom, correct_transform)
{
	string s = "   2x2 girje -3292 kgodg    ";

	TransformStr(s);

	cout << s << endl;

	ADD_FAILURE();
}