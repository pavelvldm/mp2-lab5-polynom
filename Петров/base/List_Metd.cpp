#include "List.h"

template<typename T>
List<T>::List() : Head(nullptr), Amount(0)
{
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(const T &val, const int &d = 0)
{
	if (Amount == MAX_LIST_SIZE)
		throw std::exception("Is Full");

	if (Head == nullptr)
	{
		Head = new Node;
		Head->pNext = nullptr;
		Head->data = val;
		Head->degr = d;

		Amount++;
	}
	else
	{
		Node *p = this->Head;

		while (p->pNext != nullptr)
			p = p->pNext;

		p->pNext = new Node;
		p->pNext->pNext = nullptr;
		p->pNext->data = val;
		p->pNext->degr = d;

		Amount++;
	}
}

template<typename T>
T& List<T>::operator[](const int ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node *p = Head;

	if (ind == 0)
		return p->data;

	while ((p->pNext != nullptr) && (i != ind))
	{
		p = p->pNext;
		i++;
	}

	return p->data;
}

template<typename T>
void List<T>::Sort()
{
	T x;

	for (int i = 1; i < Amount; i++)
	{
		Node *Current = FindElem(i);
		int j = i - 1;

		while ((j > -1) && (Current->data < this->operator[](j)))
		{
			Node *tmp, *p, *pp, *pr;

			if (j > 0)
			{
				p = FindElem(j);
				pr = FindElem(j - 1);
				pp = Current;

				pr->pNext = pp;
				tmp = pp->pNext;
				pp->pNext = p;
				p->pNext = tmp;

				j--;
			}
			else
			{
				p = FindElem(j);
				pp = Current;

				tmp = pp->pNext;
				pp->pNext = p;
				p->pNext = tmp;

				j--;
			}
		}

		if (Current->data < Head->data)
			Head = Current;
	}
}

template<typename T>
void List<T>::PrintList()
{
	Node *p = Head;

	if (p == nullptr)
		return;

	std::cout << p->data << ' ';

	while (p->pNext != nullptr)
	{
		p = p->pNext;
		std::cout << p->data << ' ';
	}
}