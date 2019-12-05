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

TEST(List, can_find_element_in_list)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);
	
	EXPECT_EQ(3, (testList.FindElem(3))->data);
}

TEST(List, cant_find_element_with_negative_index)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);

	ASSERT_ANY_THROW(testList.FindElem(-9));
}

TEST(List, cant_find_element_with_large_index)
{
	List<int> testList;

	for (int i = 0; i < 5; i++)
		testList.push_back(i);

	ASSERT_ANY_THROW(testList.FindElem(7));
}

TEST(List, compare_equal_lists)
{
	List<int> testList1;
	List<int> testList2;

	srand(time(0));

	for (int i = 4; i > -1; i--)
		testList1.push_back(rand() % 100 - 1);

	testList2 = testList1;

	EXPECT_EQ(testList1, testList2);
}

TEST(List, can_sort_list)
{
	List<int> testList;

	srand(time(0));

	for (int i = 4; i > -1; i--)
		testList.push_back(rand() % 100 - 1);

	testList.Sort();

	bool f = true;
	int i = 0;

	while ((!f) && (i < testList.GetAmount()))
	{
		if (testList[i] > testList[i + 1])
			f = false;
		i++;
	}

	EXPECT_EQ(true, f);
}