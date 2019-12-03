#pragma once

const int MAX_LIST_SIZE = 1000;

template<typename T>
class List
{
	struct Node
	{
		T data;
		unsigned int degr;
		Node *pNext;
	};

	Node *Head;
	int Amount;

public:
	List();
	~List();

	void push_back(const T &val, const int &d = 0);
	void pop_front();

	unsigned int& operator[](const int ind);
	int GetAmount() { return Amount; }

	Node* GetHead() { return Head; }

	// возвращает адрес элемента по индексу
	Node* FindElem(const T &ind)
	{
		if ((ind < 0) || (ind > Amount - 1))
			throw std::exception("Wrong ind");

		int i = 0;
		Node *p = Head;

		if (ind == 0)
			return p;

		while ((p->pNext != nullptr) && (i != ind))
		{
			p = p->pNext;
			i++;
		}

		return p;
	}

	void Sort();
	void PrintList();
};

