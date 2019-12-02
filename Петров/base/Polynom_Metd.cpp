#include "Polynom.h"

void TransformStr(string &s)
{
	int i;

	while ((i = s.find(' ')) != string::npos)
	{
		s.erase(i, 1);
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
		return 1;

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
		return 1;

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
		return 1;

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
		int j;
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

		// выделяем степени
		if ((s[num] == 'x') && (num < end))
		{
			powx = RetPowX(s, num, end);

			if ((num < end) && (s[num] == 'y'))
			{
				powy = RetPowY(s, num, end);
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z'))
			{
				powz = RetPowZ(s, num, end);
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((s[num] == 'y') && (num < end))
		{
			powy = RetPowY(s, num, end);

			if ((num < end) && (s[num] == 'x'))
			{
				powx = RetPowX(s, num, end);
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z'))
			{
				powz = RetPowZ(s, num, end);
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}
		}

		if ((s[num] == 'z') && (num < end))
		{
			powz = RetPowZ(s, num, end);

			if ((num < end) && (s[num] == 'y'))
			{
				powy = RetPowY(s, num, end);
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}

			if ((num < end) && (s[num] == 'x'))
			{
				powx = RetPowX(s, num, end);
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((powx >= MAX_POLYNOM_POW) || (powy >= MAX_POLYNOM_POW) || (powz >= MAX_POLYNOM_POW))
			throw exception("Wrong powers");

		degree = powx * 100 + powy * 10 + powz;

		coef.push_back(coeff, degree);

		// удаляем обработанный моном
		s.erase(st, end - st);
	}

	coef.Sort();
}