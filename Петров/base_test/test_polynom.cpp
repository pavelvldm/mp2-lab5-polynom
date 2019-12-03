#include <gtest.h>

#include "Polynom.h"
#include "List_Metd.cpp"
#include "Polynom_Metd.cpp"

TEST(Polynom, correct_transform)
{
	string s = "   2x2 girje -3292 kgodg    ";

	TransformStr(s);

	cout << s << endl;

	SUCCEED();
}

TEST(Polynom, can_transform_string_to_polynom)
{
	string s = "5 x - 74 ,9 7y + 2, 75 z - 9 7 x^3y + 1, 9 9 9y^7x^3z - 11,7 zx^5 + 11";

	Polynom testP;
	testP.CreatePolynom(s);
	testP.PrintPolynom();

	SUCCEED();
}

TEST(Polynom, mul_scal)
{
	string s = "5 x - 74 ,9 7y + 2, 75 z - 9 7 x^3y + 1, 9 9 9y^7x^3z - 11,7 zx^5 + 11";

	Polynom testP;
	testP.CreatePolynom(s);
	testP.MulScalar(2);
	testP.PrintPolynom();

	SUCCEED();
}