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

TEST(Polynom, can_transform_string_to_polynom)
{
	string s = "2x^2y^4z - 2.74xyz^6 + 36 - 14y - 81z^2";

	Polynom testP;
	testP.CreatePolynom(s);
}