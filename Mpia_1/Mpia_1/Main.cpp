#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>
#define N 50
using namespace std;
unsigned int M = 0;
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

void AddTable(Table* table, int day, int month, int year, string firstName, string secondName)
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
		table->count++;
	}
}

void ReadFile(Table* table)
{
	char symbol;
	int day, month, year;
	string firstName;
	string secondName;


	while (!fin.eof() && table->count<N)
	{
		fin >> day >> month >> year;
		fin >> firstName >> secondName;
		AddTable(table, day, month, year, firstName, secondName);
	}
}

template <typename T1>

int IsBigger(T1 firstElement, T1 firstElement2)
{
	
	if (firstElement > firstElement2)
	{
		return 1;
	}
	else 
		return 0;
	
}

void sorts(Table* table, int root, int bottom, int code)
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
				if (IsBigger(table->elements[root * 2 ].firstName, table->elements[root * 2 + 1].firstName)) {
					maxChild = root * 2;
				}
				else {
					maxChild = root * 2 + 1;
				}
			}
			if (code == 1)
			{
				if (IsBigger(table->elements[root * 2].year, table->elements[root * 2+1].year ))
				{
					maxChild = root * 2;
				}
				else {
					maxChild = root * 2 + 1;
				}
			}

		}
		if (code == 0)
		{
			if (IsBigger(table->elements[maxChild].firstName, table->elements[root].firstName))
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
			if (IsBigger(table->elements[maxChild].year, table->elements[root].year))
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
		sorts(table, i, size - 1, code);

	}
	for (int i = size - 1; i >= 1; i--)
	{
		Element temp = table->elements[0];
		table->elements[0] = table->elements[i];
		table->elements[i] = temp;
		sorts(table, 0, i - 1, code);
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

bool isempty(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

void main() {

	Table table;
	setlocale(LC_ALL, "Russian");
	fin.open("input.txt");

	if (!fin)
	{
		cout << "file not open" << endl;
	}

	if (isempty(fin))
	{
		cout << "Table is empty" << endl;
	}
	else
	{
		ReadFile(&table);
		fin.close();


		cout << "Таблица до сортировки выглядит следующим образом:\n";
		//Print(&table);
		printf_s("\n");

		cout << "Таблица после сортировки по Фамилии и имени:\n";
		auto start = std::chrono::high_resolution_clock::now();
		PiramidSort(&table, 0);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		//Print(&table);
		cout << "Time PiramidSortName " << diff.count() << endl;
		printf_s("\n");

		cout << "Таблица после сортировки по дате рождения:\n";
		auto start1 = std::chrono::high_resolution_clock::now();
		PiramidSort(&table, 1);
		auto end1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff1 = end1 - start1;
		//Print(&table);
		cout << "Time PiramidSortDate " << diff1.count() << endl;
		printf_s("\n");

		auto start2 = std::chrono::high_resolution_clock::now();

		qsort(&(table.elements[0].month), table.count, sizeof(Element), IsBigger);

		auto end2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff2 = end2 - start2;
		Print(&table);
		cout << "Time Qsort " << diff2.count() << endl;
		system("pause");
		//qsort_s()
	}
}