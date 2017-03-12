// 4.2 (4). Длина строк текстового файла не превышает 80 символов.
// Разработать программу центрирования строк : короткие строки дополняются пробелами и размещаются по центру.

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
using namespace std;

ofstream fout("cpp.txt");
ifstream fin("cpp.txt");

int max_length(char **a, int n)
{
	int max_len = 0;
	for (int i = 0; i < n; i++)
	{
		int len = 0;
		for (int j = 0; a[i][j] != '\0'; j++)
		{
			len++;
		}
		if (len > max_len)max_len = len;
	}
	return max_len;
}

int main()
{
	int n;
	cout << "Enter the number of lines: ";
	cin >> n;

	char **a = new char*[n];
	for (int i = 0; i < n; i++)
		a[i] = new char[80];

	fout << "Before: " << endl << endl;
	cout << "Enter the lines: ";
	cin.get();
	for (int i = 0; i < n; i++)
	{
		cin.getline(a[i],80);
		fout << a[i] << "\n";
	}
	int max_len = max_length(a,n);
	
	fout << endl << "After: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		int space;
		int len = 0;
		for (int j = 0; a[i][j] != '\0'; j++)
		{
			len++;
		}
		space = (max_len - len) / 2;
		for (int j = 0; j < space; j++) fout << " ";
		for (int j = 0; a[i][j] != '\0'; j++)
		{
			fout << a[i][j];
		}
		fout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;


	fin.close(); 
	fout.close();



	system("pause");
	return 0;
}

