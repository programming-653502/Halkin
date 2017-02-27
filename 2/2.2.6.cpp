#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "clocale"
#include "conio.h"

using namespace std;


bool int_check(char x[])
{
	for (int i = 0; x[i] != '\0'; i++)
	{
		if (x[i] < '0' || x[i]> '9')
		{
			cout << "Ошибка ввода, введите еще раз" << endl;
			return 0;
		}
	}
	return 1;
}

int factorial(int k)
{                                                  
	int fact=1;                                    
	for (int i = 2; i <= k; i++)
	{
		fact *= i;
	}
	return fact;
}

double iter(double x, int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		 result += pow((-1), i - 1) * pow(x, 2 * i - 1) / factorial(2 * i - 1);
	}
	return result;
}

int main()
{
	setlocale(0, "rus");
	long double left, right_iter=0;
	double x,e;
	char input[255];

  a:cout << endl << "Введите x: ";
	cin >> input;
	if (int_check(input) == 0) goto a;
	else x = atof(input);
	cin.clear();
	
  b:cout << "Введите e: ";
	cin >> e;
	if (e <= 0.0 )
	{
		cout << endl << "e должно быть > 0" << endl;
		goto b;
		cin.clear();
	}


	left = sin(x);
	for (int i = 1; i < 1000; i++)
	{
		right_iter = iter(x, i);
		if (abs(left - right_iter) < e)
		{
			cout << "Выражение сходится при заданном x, когда n= " << i;
			break;
		}
	}
	

	cout << endl << "Левая часть : " << left << endl;
	cout << "Правая часть : " << right_iter << endl;



	system("pause");
    return 0;
}

