#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include "templates.h"
#include <fstream>
#include <iostream>
#define N 50
using namespace std;

ifstream fin;


struct Element
{
	int day;
	int month;
	int year;
	string firstName;
	string secondName;
	string thirdName;
};

struct Table
{
	Element elements[N];
	int count = 0;
};

void AddTable(Table* table, int day, int month, int year, string firstName, string secondName, string thirdName)
{
	int tableCount = table->count;
	if (tableCount < N)
	{
		int place = tableCount;
		table->elements[place].day = day;
		table->elements[place].month = month;
		table->elements[place].year = year;
		table->elements[place].firstName = firstName;
		table->elements[place].secondName = secondName;
		table->elements[place].thirdName = thirdName;

		table->count++;
	}
}

void ReadFile(Table* table)
{
	char symbol;
	int day, month, year;
	string firstName;
	string secondName;
	string thirdName;


	while (!fin.eof())
	{
		fin >> day >> month >> year;
		fin >> firstName >> secondName >> thirdName;
		AddTable(table, day, month, year, firstName, secondName, thirdName);
	}
}

template <typename T1>

bool IsBigger(T1 firstElement, T1 secondElement, T1 thirdElement, T1 firstElement2, T1 secondElement2, T1 thirdElement2)
{
	
	if (firstElement > firstElement2)
	{
		return true;
	}
	else if (firstElement < firstElement2)
	{
		return false;
	}
	else
	{

		if (secondElement > secondElement2)
		{
			return true;
		}
		else if (secondElement < secondElement2)
		{
			return false;
		}
		else
		{
			if (firstElement > firstElement2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

//bool IsBigger(string firstElement, string secondElement, string thirdElement, string firstElement2, string secondElement2, string thirdElement2)
//{
//
//	if (firstElement > firstElement2)
//	{
//		return true;
//	}
//	else if (firstElement < firstElement2)
//	{
//		return false;
//	}
//	else
//	{
//
//		if (secondElement > secondElement2)
//		{
//			return true;
//		}
//		else if (secondElement < secondElement2)
//		{
//			return false;
//		}
//		else
//		{
//			if (firstElement > firstElement2)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//}
//

void sort(Table* table, int root, int bottom, int code)
{
	int maxChild;
	int done = 0;
	while ((root * 2) <= bottom && (!done))
	{
		if (root * 2 == bottom) {
			maxChild = root * 2;
		}
		else {
			if (code == 0)
			{
				if (IsBigger(table->elements[root * 2 ].firstName, table->elements[root * 2].secondName, table->elements[root * 2 ].thirdName,
					table->elements[root * 2 + 1].firstName,table->elements[root * 2 + 1].secondName, table->elements[root * 2 + 1].thirdName)) {
					maxChild = root * 2;
				}
				else {
					maxChild = root * 2 + 1;
				}
			}
			if (code == 1)
			{
				if (IsBigger(table->elements[root * 2].year, table->elements[root * 2].month, table->elements[root * 2].day,
					table->elements[root * 2+1].year, table->elements[root * 2+1].month, table->elements[root * 2+1].day)) {
					maxChild = root * 2;
				}
				else {
					maxChild = root * 2 + 1;
				}
			}

		}
		if (code == 0)
		{
			if (IsBigger(table->elements[maxChild].firstName, table->elements[maxChild].secondName, table->elements[maxChild].thirdName,
				table->elements[root].firstName, table->elements[root].secondName, table->elements[root].thirdName))
			{
				Element  temp = table->elements[root];
				table->elements[root] = table->elements[maxChild];
				table->elements[maxChild] = temp;
				root = maxChild;
			}
			else done = 1; // пирамида сформирована
		}
		if (code == 1)
		{
			if (IsBigger(table->elements[maxChild].year, table->elements[maxChild].month, table->elements[maxChild].day,
				table->elements[root].year, table->elements[root].month, table->elements[root].day))
			{
				Element  temp = table->elements[root];
				table->elements[root] = table->elements[maxChild];
				table->elements[maxChild] = temp;
				root = maxChild;
			}
			else done = 1; // пирамида сформирована
		}

	}

}

void PiramidSort(Table* table, int code)
{
	int size = table->count;
	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		sort(table, i, size - 1, code);

	}
	for (int i = size - 1; i >= 1; i--)
	{
		Element temp = table->elements[0];
		table->elements[0] = table->elements[i];
		table->elements[i] = temp;
		sort(table, 0, i - 1, code);
	}


}

void Print(Table* Guy)
{
	for (int i = 0; i < Guy->count; i++)
	{
		cout << Guy->elements[i].day << "." << Guy->elements[i].month << "." << Guy->elements[i].year << " ";
		cout << Guy->elements[i].firstName << " " << Guy->elements[i].secondName << " " << Guy->elements[i].thirdName << "\n";
	}
}


void main() {

	Table table;
	setlocale(LC_ALL, "Russian");
	fin.open("input.txt");
	ReadFile(&table);
	fin.close();

	printf_s("Таблица до сортировки выглядит следующим образом:\n");
	Print(&table);
	printf_s("\n");

	printf_s("Таблица после сортировки по Фамилии и имени:\n");
	PiramidSort(&table, 0);
	Print(&table);
	printf_s("\n");

	printf_s("Таблица после сортировки по дате рождения:\n");
	PiramidSort(&table, 1);
	Print(&table);
	printf_s("\n");

	_getch();
}