//4.1.(4). Дано n матриц.В каждой строке каждой матрицы записано одно
//         слово.Если в слове нет повторяющихся символов – преобразовать
//		   все буквы слова в прописные, в противном случае – в строчные
//         буквы.Полученные матрицы вывести.

#include "stdafx.h"
#include "iostream"
using namespace std;

void output(char **a,int str)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j != '\n'; j++)
		{
			if (a[i][j] < 65 || a[i][j] > 122) break;
			else cout << a[i][j];
		}
		cout << endl;
	}
}
void objective(char **a, int str)
{
	for (int i = 0; i < str; i++)               // поиск повторяющихся символов
	{											// буквы отличающиеся регистром не являются повторяющимися
		int count = 0;
		for (int j = 0; j < 255; j++)
		{
			for (int k = j + 1; k < 255; k++)
			{
				if (a[i][j] < 65 || a[i][j] > 122) break;
				if (a[i][j] == a[i][k]) count++;
			}
		}
		for (int j = 0; j < 255; j++)           // замена 
		{
			if (count >= 1)
			{
				if (a[i][j] <= 122 && a[i][j] >= 97) continue;
				else a[i][j] = a[i][j] + 32;
			}
			if (count == 0)
			{
				if (a[i][j] <= 90 && a[i][j] >= 65) continue;
				else a[i][j] = a[i][j] - 32;
			}
		}
		count = 0;
	}
}

int main()
{
	int n = 0, str = 0;
    cout << "Enter the number of matrices : ";
	cin >> n;

	for (int f = 0; f < n; f++)
	{
		system("cls");
		cout << "Matrix " << f + 1 << ": " << endl;
		cout << "Enter the number of lines in this matrix : ";
		cin >> str;

		cout << "Enter the lines: " << endl;
		char **a = new char*[str];
		for (int i = 0; i < str; i++)
		{
			a[i] = new char[255];
			cin >> a[i];
			cin.clear();
		}

		objective(a, str);

		cout << endl << "The result:" << endl << endl;
		output(a,str);

		system("pause");

	}
	
    return 0;
}

