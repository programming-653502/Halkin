// 1.2 (5).  Найти все натуральные числа, не превосходящие заданного n,
//          десятичная запись которых есть строго возрастающая или строго
//          убывающая последовательность цифр.

#include "stdafx.h"
#include "iostream"
#include "clocale"
using namespace std;

int search(int x) // функция для возрастающей последовательности чисел
{                 // для убывающей достаточно изменить знак неравенства в 19 строке
	
	int a,b,c;    
	bool f=1;
	a = x % 10; // последний разряд числа
	b = x / 10;
	while (b > 0)
	{
		c = b % 10; // последующие разряды числа
		if (c >= a)
		{
			f = 0;
		}
		a = c; 
		b /= 10;
	}
	return f;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int  i,ch;
	char n[255];
	a:cout << "Введите натуральное n: ";
	cin >> n;
	for (int i = 0; n[i] != '\0'; i++)
	{
		if (n[i] < '0' || n[i]> '9')
		{
			cout << "Ошибка ввода, введите еще раз" << endl;
			goto a;
		}
	}
	ch = atoi(n);
	cout << endl << "Ответ: " << endl;

	for (int i = 1; i < ch; i++)
	{
		if (search(i) == 1) cout << i << ' ';
	}

	cout << endl;
	system("pause");
	return 0;
}

