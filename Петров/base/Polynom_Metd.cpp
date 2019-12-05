#include "Polynom.h"
#include "List.h"

void TransformStr(string &s)
{
	int i;

	while ((i = s.find(' ')) != string::npos)
	{
		s.erase(i, 1);
	}

	while ((i = s.find(',')) != string::npos)
	{
		s.replace(i, 1, ".");
	}

	if (s[0] != '-')
		s = '+' + s;

	s = s + '+';
}

int RetPowX(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'y') || (s[j] == 'z'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'y') && (s[j] != 'z'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

int RetPowY(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'x') || (s[j] == 'z'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'x') && (s[j] != 'z'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

int RetPowZ(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'x') || (s[j] == 'y'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'x') && (s[j] != 'y'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

Polynom::Polynom()
{
}


Polynom::~Polynom()
{
}

void Polynom::CreatePolynom(string &s)
{
	if (s.size() == 0)
		throw exception("void");

	TransformStr(s);

	while (s.size() != 1)
	{
		int st, end, num = -1;
		double coeff;
		int degree;
		int powx = 0, powy = 0, powz = 0;

		// выделяем моном
		for (int i = 0; i < s.size(); i++)
			if ((s[i] == '+') || (s[i] == '-'))
			{
				st = i;
				break;
			}

		for (int i = st + 1; i < s.size(); i++)
			if ((s[i] == '+') || (s[i] == '-'))
			{
				end = i;
				break;
			}

		// выделяем коэффициент
		for (int i = st; i < end; i++)
			if ((s[i] == 'x') || (s[i] == 'y') || (s[i] == 'z'))
			{
				num = i;
				break;
			}

		if (num == -1)
		{
			string c = s.substr(st + 1, end - st - 1);
			coeff = stof(c);
		}
		else
			if (num - st == 1)
				coeff = 1;
			else
			{
				string c = s.substr(st + 1, num - st - 1);
				coeff = stof(c);
			}

		if (num == -1)
		{
			coef.push_back(coeff);
			s.erase(st, end - st);
			continue; 
		}

		bool f1 = false, f2 = false;

		// выделяем степени
		if ((s[num] == 'x') && (num < end) && (!f1))
		{
			powx = RetPowX(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'y') && (!f2))
			{
				powy = RetPowY(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z') && (!f2))
			{
				powz = RetPowZ(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((s[num] == 'y') && (num < end) && (!f1))
		{
			powy = RetPowY(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'x') && (!f2))
			{
				powx = RetPowX(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z') && (!f2))
			{
				powz = RetPowZ(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}
		}

		if ((s[num] == 'z') && (num < end) && (!f1))
		{
			powz = RetPowZ(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'y') && (!f2))
			{
				powy = RetPowY(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}

			if ((num < end) && (s[num] == 'x') && (!f2))
			{
				powx = RetPowX(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((powx >= MAX_POLYNOM_POW) || (powy >= MAX_POLYNOM_POW) || (powz >= MAX_POLYNOM_POW))
			throw exception("Wrong powers");

		degree = powx * 100 + powy * 10 + powz;

		if (s[st] == '-')
			coeff = -1 * coeff;

		coef.push_back(coeff, degree);

		// удаляем обработанный моном
		s.erase(st, end - st);
	}


	coef.Sort();
}

void CreateString()
{
}

Polynom Polynom::operator+(const Polynom &polyOut)
{
	Polynom Result;

	Result.coef = polyOut.coef;

	Node<double> *p = coef.GetHead();
	Node<double> *pp;

	pp = Result.coef.FindDegr(p->degr);

	if (pp != nullptr)
		pp->data += p->data;
	else
		Result.coef.push_back(p->data, p->degr);

	while (p->pNext != nullptr)
	{
		p = p->pNext;

		pp = Result.coef.FindDegr(p->degr);

		if (pp != nullptr)
			pp->data += p->data;
		else
			Result.coef.push_back(p->data, p->degr);
	}

	// чистить нулевые и сортировать !!!
	return *this;
}

Polynom& Polynom::MulScalar(const int &scal)
{
	Node<double> *p = coef.GetHead();

	if (p != nullptr)
	{
		p->data = scal * p->data;

		while (p->pNext != nullptr)
		{
			p = p->pNext;
			p->data = scal * p->data;
		}
	}

	return *this;
}

void Polynom::PrintPolynom()
{
	coef.PrintList();
}