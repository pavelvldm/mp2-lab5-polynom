#include <gtest.h>

#include "Polynom.h"
#include "List_Metd.cpp"
#include "Polynom_Metd.cpp"

TEST(Polynom, can_transform_string_to_polynom)
{
	string s = "5 x - 74 ,9 7y + 2, 75 z - 9 7 x^3y + 1, 9 9 9y^7x^3z - 11,7 zx^5 + 11";

	Polynom testP;
	ASSERT_NO_THROW(testP.CreatePolynom(s));
}

TEST(Polynom, can_multiply_polynom_on_scalar)
{
	string s1 = "2x - 7 + 1,7z^5x + x^2y^5 - 0,6yz^4x^3";
	string s2 = "4x - 14 + 3,4z^5x + 2x^2y^5 - 1,2yz^4x^3";

	Polynom testP(s1);
	Polynom testResult(s2);
	testP = testP * 2;

	EXPECT_EQ(testResult, testP);
}

TEST(Polynom, can_add_polynoms)
{
	string s1 = "3,75x^2 + y^2 - 7xz +x^2y + 1,5z^2y - 0,75";
	string s2 = "-3,75x^2 + 7xz + x^2y + 1,5z^2y + 0,75";
	string s3 = "y^2 +2x^2y + 3z^2y";

	Polynom testP1(s1);
	Polynom testP2(s2);

	Polynom testResult(s3);
	testP1 += testP2;
	
	EXPECT_EQ(testResult, testP1);
}

TEST(Polynom, can_compute_value_in_point)
{
	string s1 = "2x - 7,4 + 1,7z^5x + x^2y^3";
	Polynom testP(s1);

	double testResult = testP.ValuePoint(2, 3, 1);

	EXPECT_EQ(108, testResult);
}