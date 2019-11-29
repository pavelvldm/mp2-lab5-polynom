#pragma once

template<typename T>
class List
{
	struct Node
	{
		T data;
		Node *pNext;
	};

	Node *Head;
	int Amount;

public:
	List();
	~List();

	void push_back(const T &val);

	T& operator[](const int ind);
	Node* FindElem(const T &val);
	void Sort();
	void PrintList();
};

