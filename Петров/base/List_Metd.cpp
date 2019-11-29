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
void List<T>::push_back(const T &val)
{
	if (Head == nullptr)
	{
		Head = new Node;
		Head->pNext = nullptr;
		Head->data = val;

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

	while (i != ind)
	{
		p = p->pNext;
		i++;
	}

	return p->data;
}

/* template<typename T>
List<T>::Node* List<T>::FindVal(const T &val)
{
	Node *p = Head;
	Node *pp = nullptr;

	if (p == nullptr) return p;
	if (p->data == val)
		pp = p;

	while (p->pNext != nullptr)
	{
		p = p->pNext;
		if (p->data == val)
		{
			pp = p;
			break;
		}
	}

	return pp;
} */

template<typename T>
List<T>::Node* FindElem(const T &ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node *p = Head;

	while (i != ind)
	{
		p = p->pNext;
		i++;
	}

	return p;
} 

template<typename T>
void List<T>::Sort()
{
	T x;

	for (int i = 1; i < Amount; i++)
	{
		x = this[i];
		int j = i - 1;

		while ((j > -1) && (x < this[j]))
		{
			Node *tmp, *p, *pp;
			p = FindElem(j);
			pp = FindElem(i);

			tmp = pp->pNext;
			pp->pNext = p;
			p->pNext = tmp;

			j--;
		}

		Head = FindElem(j + 1);
	}
}

template<typename T>
void List<T>::PrintList()
{

}