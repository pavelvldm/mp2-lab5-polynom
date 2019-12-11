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
	int k = 1;
	int Choice;
	string s1;
	string s2;

	cout << "\t���������������� ���������" << endl;
	cout << "� ������������� ����� � ������� ����� ����� ��������� ��� �������, ��� � ������" << endl;
	cout << "������� �������� ��������� �������: x^2y^3z^4" << endl;
	cout << "������: 3,75x^2 + y^2 - 7xz +x^2y + 1,5z^2y - 0,75" << endl;

	cout << endl;

	cout << "������� ������ ���������: ";
	getline(cin, s1);

	cout << "������� ������ ���������: ";
	getline(cin, s2);

	system("cls");

	Polynom P1(s1);
	Polynom P2(s2);
	Polynom Result;

	while (k < 5)
	{
		cout << P1 << endl;
		cout << P2 << endl;
		cout << endl;
		cout << "\t�������� ��������:" << endl;
		cout << "(1) �������� ���� ���������" << endl;
		cout << "(2) ��������� ���� ���������" << endl;
		cout << "(3) ��������� �������� �� ������" << endl;
		cout << "(4) ���������� �������� �������� � �����" << endl;
		cout << "(5) ���������" << endl;

		cout << "-> ";
		cin >> k;

		switch (k)
		{
		case 1:
			system("cls");
			Result = P1 + P2;
			cout << "���������: ";
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
					cout << "����������� ������, ������� ������� �������";
					break;
				}
			}
			cout << "���������: ";
			cout << Result << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			double sc;
			cout << "������� ���������: ";
			cin >> sc;
			cout << "����� �� ���� ��������� ������ ��������? 1 ��� 2? -> ";
			cin >> Choice;
			if (Choice == 1)
			{
				Result = P1 * sc;
				cout << "���������: ";
				cout << Result << endl;
				system("pause");
				system("cls");
			}
			else if (Choice == 2)
			{
				Result = P2 * sc;
				cout << "���������: ";
				cout << Result << endl;
				system("pause");
				system("cls");
			}
			else cout << "������� ������� ��������";
			break;
		case 4:
			double x, y, z;
			double Res;
			cout << "������� ����� (x, y, z): ";
			cin >> x;
			cin >> y;
			cin >> z;
			cout << "�������� ������ �������� ������ ���������? 1 ��� 2? -> ";
			cin >> Choice;
			if (Choice == 1)
			{
				Res = P1.ValuePoint(x, y, z);
				cout << "���������: ";
				cout << Res << endl;
				system("pause");
				system("cls");
			}
			else if (Choice == 2)
			{
				Res = P2.ValuePoint(x, y, z);
				cout << "���������: ";
				cout << Res << endl;
				system("pause");
				system("cls");
			}
			else cout << "������� ������� ��������";
			break;
		}
	}

	system("pause");
	return;
} 