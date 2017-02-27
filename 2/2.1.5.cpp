#include "stdafx.h"
#include "iostream"
#include "clocale"
#include "conio.h"
#include "cstdlib"
using namespace std;

double count_p = 0; // счетчик кол-ва картофеля
double count_с = 0; // счетчик кол-ва моркови
double count_b = 0; // счетчик кол-ва свеклы


void shop_info() // информация о магазине
{
	system("cls");
	int ch;
	cout << "eVegetables inc." << endl;
	cout << "Минск: ул.Богдановича 8" << endl;
	cout << "Доставка по всему Минску с 8:00 до 21:00" << endl;
	cout << "Работаем в любой день кроме воскресенья" << endl;
	cout << "Контактный номер: +375 29 112-95-55(vel)" << endl;
	cout << "E-mail: zakaz@latuk.by" << endl << endl;
	cout << "1.Выход в меню 2.Выход с программы: ";
  w:cin >> ch;
	switch (ch)
	{
		case 1: break;
		case 2: exit(0);
		default:
		{
			cout << "Введите еще раз: ";
			goto w;
		}
	}
}

void cost_info() // информация о ценах
{
	system("cls");
	int ch;
	cout << "Уважаемый посетитель , прямо сейчас проходит акция: " << endl;
	cout << "При покупке более 10кг овощей вы получаете 10% скидку! " << endl;
	cout << "При покупке более 25кг овощей вы получаете 20% скидку! " << endl;
	cout << "При покупке более 50кг овощей вы получаете 25% скидку! " << endl << endl;
	cout << "Информация о ценах: " << endl;
	cout << "Картофель - 500р за кг" << endl;
	cout << "Морковь - 1000р за кг" << endl;
	cout << "Свекла - 700 р за кг" << endl << endl;
	cout << "1.Выход в меню 2.Выход с программы: ";
w:cin >> ch;
	switch (ch)
	{
		case 1: break;
		case 2: exit(0);
		default:
		{
			cout << "Введите еще раз: ";
			goto w;
		}
	}
}

double potato(double count_p) // заказ картофеля
{
	system("cls");
	int ch;
	double kg_potato;
	char kg_p[255];
	cout << "Вы попали в меню заказа картофеля" << endl;
	cout << "Картофель - 500р за кг" << endl;
	for (int i = 0; i != 1;)
	{
		cout << "Сколько кг картофеля вы хотите заказать?" << endl;
	  a:cin >> kg_p;
		for (int j = 0; kg_p[j] != '\0'; j++)
		{
			if (kg_p[j] < '0' || kg_p[j]> '9')
			{
				cout << "Ошибка ввода, введите еще раз" << endl;
				goto a;
			}
		}
		kg_potato = atof(kg_p);
		count_p += kg_potato;

		cout << endl << endl << "1.Выход в меню  2.Продолжить заказ картофеля: ";
	w:cin >> ch;
		switch (ch)
		{
			case 1: i=1;
			case 2: break;
			default:
			{
				cout << "Введите еще раз: ";
				goto w;
			}
		}
		
	}
		
		return count_p;
}



double carrot(double count_с) // заказ моркови
{
	system("cls");
	int ch;
	double kg_carrot;
	char kg_c[255];
	cout << "Вы попали в меню заказа моркови" << endl;
	cout << "Морковь - 1000р за кг" << endl;
	for (int i = 0; i != 1;)
	{
		cout << "Сколько кг моркови вы хотите заказать?" << endl;
	a:cin >> kg_c;
		for (int j = 0; kg_c[j] != '\0'; j++)
		{
			if (kg_c[j] < '0' || kg_c[j]> '9')
			{
				cout << "Ошибка ввода, введите еще раз" << endl;
				goto a;
			}
		}
		kg_carrot = atof(kg_c);
		count_с += kg_carrot;

		cout << endl << endl << "1.Выход в меню 2.Продолжить заказ моркови: ";
	w:cin >> ch;
		switch (ch)
		{
		case 1: i = 1;
		case 2: break;
		default:
		{
			cout << "Введите еще раз: ";
			goto w;
		}
		}

	}

	return count_с;
}



double beet(double count_b) // заказ свеклы
{
	system("cls");
	int ch;
	double kg_beet;
	char kg_b[255];
	cout << "Вы попали в меню заказа свеклы" << endl;
	cout << "Свекла - 700 р за кг" << endl;
	for (int i = 0; i != 1;)
	{
		cout << "Сколько кг свеклы вы хотите заказать?" << endl;
	a:cin >> kg_b;
		for (int j = 0; kg_b[j] != '\0'; j++)
		{
			if (kg_b[j] < '0' || kg_b[j]> '9')
			{
				cout << "Ошибка ввода, введите еще раз" << endl;
				goto a;
			}
		}
		kg_beet = atof(kg_b);
		count_b += kg_beet;

		cout << endl << endl << "1.Выход в меню 2.Продолжить заказ свеклы: ";
	w:cin >> ch;
		switch (ch)
		{
		case 1: i = 1;
		case 2: break;
		default:
		{
			cout << "Введите еще раз: ";
			goto w;
		}
		}

	}

	return count_b;
}

void bin(double a, double b, double c) // корзина
{
	system("cls");
	cout << "На данный момент вы заказали:" << endl;
	cout << a << "кг картофеля" << endl;
	cout << b << "кг моркови" << endl;
	cout << c << "кг свеклы" << endl << endl;
	cout << "Нажмите любую клавишу для выхода в меню";
	_getch();

}

void cost(double a, double b, double c) // оформление заказа
{
	system("cls");
	int ch,ch2;
	int del;
	char address[1024];
	cout << "На данный момент вы заказали:" << endl;
	cout << a << "кг картофеля" << endl;
	cout << b << "кг моркови" << endl;
	cout << c << "кг свеклы" << endl << endl;
	cout << "Требуется ли вам доставка?";
	cout << "1.Да (15000 руб.)  2.Нет: ";
  w:cin >> ch;
	switch (ch)
	{
		case 1:
		{
			del = 15000;
			break;
		}
		case 2:
		{
			del = 0;
			break;
		} 
		default:
		{
			cout << "Введите еще раз: ";
			goto w;
		}
	}
	if (a + b + c >= 10 && a + b + c < 25)
	{
		cout << "По условиям акции вы получаете 10% скидку!" << endl;
		cout << "Таким образом ваша цена :" << ((a * 500 + b * 1000 + c * 700) - ((a * 500 + b * 1000 + c * 700) / 10)+del) << " рублей";
	}
	if (a + b + c >= 25 && a + b + c < 50)
	{
		cout << "По условиям акции вы получаете 20% скидку!" << endl;
		cout << "Таким образом ваша цена :" << ((a * 500 + b * 1000 + c * 700) - ((a * 500 + b * 1000 + c * 700) / 100 * 20)+del) << " рублей";
	}
	if (a + b + c >= 50 )
	{
		cout << "По условиям акции вы получаете 30% скидку!" << endl;
		cout << "Таким образом ваша цена :" << ((a * 500 + b * 1000 + c * 700) - ((a * 500 + b * 1000 + c * 700) / 100 *30)+del) << " рублей";
	}
	if (a + b + c <= 10)
	{
		cout << "Ваша цена :" << a * 500 + b * 1000 + c * 700 +del << " рублей";
	}
	cout << endl << "Вы готовы подтвердить заказ ?" << endl;
	cout << "1.Ввод адреса   2.Выход в меню: ";
  q:cin >> ch2;
	switch (ch2)
	{
		case 1: 
		{
			cout << "Ваш адрес:";
			cin >> address;
			cout << "Спасибо за заказ, ожидайте доставку в течении 2 часов" << endl;
			cout << "Нажмите любую клавишу для выхода в меню";
			_getch();
			break;
		}
		case 2: break;
		default:
		{
			cout << "Введите еще раз: ";
			goto q;
		}
	}
}



void ex() // выход
{
	exit(1);
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int choice2;
	char choice[255];
	double a=0, b=0, c=0;
	cout << "Добро пожаловать в центр заказов интернет-магазина eVegetables." << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (int i = 0; i != 1;)
	{
		cin.clear();
		system("cls");
		cout << endl;
		cout << "Меню:" << endl;
		cout << "1.Информация о магазине" << endl;
		cout << "2.Информация о ценах" << endl;
		cout << "3.Заказ картофеля(кг)" << endl;
		cout << "4.Заказ моркови(кг)" << endl;
		cout << "5.Заказ свеклы(кг)" << endl;
		cout << "6.Просмотр корзины" << endl;
		cout << "7.Подтверждение заказа" << endl;
		cout << "8.Обнуление заказа" << endl;
		cout << "9.Выход с магазина" << endl;
		cout << endl;
	  v:cin >> choice;
		for (int j = 0; choice[j] != '\0'; j++)
		{
			if (choice[j] < '0' || choice[j]> '9')
			{
				cout << "Ошибка ввода, введите еще раз" << endl;
				goto v;
			}
		}
		choice2 = atoi(choice);
		switch (choice2)
		{
			case 1:
			{
				shop_info();
				break;
			}
			case 2:
			{
				cost_info();
				break;
			}
			case 3:
			{
				a+=potato(count_p);
				break;
			}
			case 4:
			{
				b+=carrot(count_с);
				break;
			}
			case 5:
			{
				c+=beet(count_b);
				break;
			}
			case 6:
			{
				bin(a,b,c);
				break;
			}
			case 7:
			{
				cost(a, b, c);
				break;
			}
			case 8:
			{
				a = 0;
				b = 0;
				c = 0;
				cout << "Ваш заказ был успешно обнулен" << endl;
				break;
			}
			case 9:
			{
				ex();
			}
			default:
			{
				cout << "Повторите ввод" << endl;
				break;
			}
		}
	}

	system("pause");
    return 0;
}

