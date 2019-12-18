#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>

#include "List.h"
#include "Polynom.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	setlocale(LC_NUMERIC, "C");
	int k = 1;
	int Choice;
	string s1;
	string s2;

	cout << "\tДемонстрационная программа" << endl;
	cout << "В коэффициентах целую и дробную часть можно разделять как запятой, так и точкой" << endl;
	cout << "Степени вводятся следующим образом: x^2y^3z^4" << endl;
	cout << "Пример: 3,75x^2 + y^2 - 7xz +x^2y + 1,5z^2y - 0,75" << endl;

	cout << endl;

	cout << "Введите первый многочлен: ";
	getline(cin, s1);

	cout << "Введите второй многочлен: ";
	getline(cin, s2);

	system("cls");

	Polynom P1;
	Polynom P2;

	try
	{
		P1.CreatePolynom(s1);
	}
	catch (int a)
	{
		if (a == 3)
			cout << "Степень первого многочлена должна быть меньше 10" << endl;
		return;
	}

	try
	{
		P2.CreatePolynom(s2);
	}
	catch (int a)
	{
		if (a == 3)
			cout << "Степень второго многочлена должна быть меньше 10" << endl;
		return;
	}

	Polynom Result;

	while (k < 5)
	{
		cout << P1 << endl;
		cout << P2 << endl;
		cout << endl;
		cout << "\tВыберите операцию:" << endl;
		cout << "(1) Сложение двух полиномов" << endl;
		cout << "(2) Умножение двух полиномов" << endl;
		cout << "(3) Умножение полинома на скаляр" << endl;
		cout << "(4) Вычисление значения полинома в точке" << endl;
		cout << "(5) Завершить" << endl;

		cout << "-> ";
		cin >> k;

		switch (k)
		{
		case 1:
			system("cls");
			Result = P1 + P2;
			cout << "Результат: ";
			cout << Result;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			try
			{
				Result = P1 * P2;
			}
			catch (int a)
			{
				if (a == 2)
				{
					cout << "Перемножать нельзя, слишком большая степень" << endl;
					break;
				}
			}
			cout << "Результат: ";
			cout << Result << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			double sc;
			cout << "Введите константу: ";
			cin >> sc;
			cout << "Какой из двух полиномов хотите умножить? 1 или 2? -> ";
			cin >> Choice;
			if (Choice == 1)
			{
				Result = P1;
				P1 = P1 * sc;
				cout << "Результат: ";
				cout << P1 << endl;
				P1 = Result;
				system("pause");
				system("cls");
			}
			else if (Choice == 2)
			{
				Result = P2 * sc;
				cout << "Результат: ";
				cout << Result << endl;
				system("pause");
				system("cls");
			}
			else cout << "Неверно введено значение";
			break;
		case 4:
			double x, y, z;
			double Res;
			cout << "Введите точку (x, y, z): ";
			cin >> x;
			cin >> y;
			cin >> z;
			cout << "Значение какого полинома хотите вычислить? 1 или 2? -> ";
			cin >> Choice;
			if (Choice == 1)
			{
				Res = P1.ValuePoint(x, y, z);
				cout << "Результат: ";
				cout << Res << endl;
				system("pause");
				system("cls");
			}
			else if (Choice == 2)
			{
				Res = P2.ValuePoint(x, y, z);
				cout << "Результат: ";
				cout << Res << endl;
				system("pause");
				system("cls");
			}
			else cout << "Неверно введено значение";
			break;
		}
	}

	system("pause");
	return;
} 