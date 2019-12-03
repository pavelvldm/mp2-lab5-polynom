#include "List.h"

template<typename T>
List<T>::List() : Head(nullptr), Amount(0)
{
}

template<typename T>
List<T>::~List()
{
	if (Head != nullptr)
	{
		while (Head->pNext != nullptr)
		{
			Node<T> *p = Head;
			Head = Head->pNext;
			delete p;
		}

		Node<T> *p = Head;
		delete p;
	}
}

template<typename T>
void List<T>::push_back(const T &val, const int &d = 0)
{
	if (Amount == MAX_LIST_SIZE)
		throw std::exception("Is Full");

	if (Head == nullptr)
	{
		Head = new Node<T>;
		Head->pNext = nullptr;
		Head->data = val;
		Head->degr = d;

		Amount++;
	}
	else
	{
		Node<T> *p = this->Head;

		while (p->pNext != nullptr)
			p = p->pNext;

		p->pNext = new Node<T>;
		p->pNext->pNext = nullptr;
		p->pNext->data = val;
		p->pNext->degr = d;

		Amount++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (Head != nullptr)
	{
		Node<T> *p = Head;
		Head = Head->pNext;
		delete p;
		Amount--;
	}
}

template<typename T>
T& List<T>::operator[](const int ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node<T> *p = Head;

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
unsigned int List<T>::GetDegree(const int ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node<T> *p = Head;

	if (ind == 0)
		return p->degr;

	while ((p->pNext != nullptr) && (i != ind))
	{
		p = p->pNext;
		i++;
	}

	return p->degr;
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &listOut)
{
	if (this != &listOut)
	{
		delete this;

		Node<T> *p = listOut.GetHead();
		
		if (p != nullptr)
		{
			push_back(p->data, p->degr);

			while (p->pNext != nullptr)
			{
				p = p->pNext;
				push_back(p->data, p->degr);
			}
		}
	}

	return *this;
}

template<typename T>
void List<T>::Sort()
{
	for (int i = 1; i < Amount; i++)
	{
		Node<T> *Current = FindElem(i);
		int j = i - 1;

		while ((j > -1) && (Current->degr < GetDegree(j)))
		{
			Node<T> *tmp, *p, *pp, *pr;

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

		if (Current->degr < Head->degr)
			Head = Current;
	}
}

template<typename T>
void List<T>::PrintList()
{
	Node<T> *p = Head;

	if (p == nullptr)
		return;

	std::cout << p->data << ' ';
	std::cout << p->degr << std::endl;

	while (p->pNext != nullptr)
	{
		p = p->pNext;
		std::cout << p->data << ' ';
		std::cout << p->degr << std::endl;
	}
}