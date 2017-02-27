#include "iostream"
#include "clocale"
using namespace std;

int** a;
{

	a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	return **a;
}

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
	return **a;
}
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
	return **a;
}

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
			count = 0;
		}
	}
}


int main()
{
	setlocale(0, "rus");
	char input[255];
	int n;

  a:cin >> input;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] < '0' || input[i]> '9')
		{
			goto a;
		}
	}
	n = atoi(input);

	creating(n);
	filling(a, n);
	show(a, n);
	sort(a, n);
	show(a, n);
	objective(a, n);
	
	system("pause");
    return 0;
}

