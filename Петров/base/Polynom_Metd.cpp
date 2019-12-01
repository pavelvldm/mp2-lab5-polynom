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

	while (s.size() != 0)
	{
		int st, end, num = -1;
		double coef;
		int degree;

		// выделяем моном
		for (int i = 0; i < s.size(); i++)
			if ((s[i] == '+') || (s[i] == '-'))
			{
				st = i;
				break;
			}

		for (int i = st; i < s.size(); i++)
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
			}

		if (num == -1)
		{
			string c = s.substr(st + 1, end - st - 1);
			coef = stof(c);
		}
		else
			if (num - st == 1)
				coef = 1;
			else
			{
				string c = s.substr(st + 1, num - st - 1);
				coef = stof(c);
			}
	}
}