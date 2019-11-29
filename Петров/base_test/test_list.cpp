#include <gtest.h>
#include "List.h"
#include "List_Metd.cpp"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> testList);
}

TEST(List, can_push_back_in_void)
{
	List<int> testList;
	int testValue = 5;

	ASSERT_NO_THROW(testList.push_back(5));
}

TEST(List, can_get_element)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);

	EXPECT_EQ(3, testList[3]);
}

TEST(List, cant_get_element_with_negative_index)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);

	ASSERT_ANY_THROW(testList[-9]);
}

TEST(List, cant_get_element_with_large_index)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);

	ASSERT_ANY_THROW(testList[5]);
}