#include "stdafx.h"
#include "iostream"
#include "clocale"
using namespace std;

int** a;
void creating(int n)  //выделение дин.памяти для матрицы
{

	a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	
}

void filling(int **a,int n)  //заполнение матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> a[i][j];
		}
	}
	system("cls");
	
}
void show(int **a, int n)  //вывод матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
void sort(int **a, int n)    //сортируем столбцы для наглядности
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (a[i][j] < a[k][j])
				{
					double rezerv = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = rezerv;
				}
			}
		}
	}
	
}

void objective(int **a, int n)  //поиск похожих столбцов
{
	cout << endl;
	int count = 0;
	for (int j = 0; j < n - 1; j++)
	{
		for (int k = j + 1; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i][j] == a[i][k])
					count++;
			}
			if (count == n) cout << "Столбцы " << j + 1 << " и " << k + 1 << " похожие" << endl;
			count = 0;
		}
	}
}


int main()
{
	setlocale(0, "rus");
	char input[255];
	int n;
	cout << "Введите размер матрицы: ";

  a:cin >> input;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] < '0' || input[i]> '9')
		{
			cout << "Ошибка ввода, введите еще раз" << endl;
			goto a;
		}
	}
	n = atoi(input);

	creating(n);
	filling(a, n);
	cout << "Введенная матрица: " << endl;
	show(a, n);
	sort(a, n);
	cout << endl << endl << "Упорядоченная матрица: " << endl;
	show(a, n);
	objective(a, n);

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	system("pause");
    return 0;
}

