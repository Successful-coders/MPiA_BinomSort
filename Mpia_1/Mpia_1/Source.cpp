//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <conio.h>
//#include <string>
//#include <locale.h>
//#include <fstream>
//#include <iostream>
//#include <chrono>
//#include <stdlib.h>
//#include <algorithm>
//#define N 50
//using namespace std;
//ifstream fin;
//int code = 0;
//int sizeElements = 0;
//
//struct Element
//{
//	int day;
//	int month;
//	int year;
//	string firstName;
//	string secondName;
//	Element *next;
//};
//
//
//void ReadFile(Element* elements)
//{
//	int day, month, year;
//	string firstName;
//	string secondName;
//	int i = 0;
//
//	while (!fin.eof())
//	{
//		fin >> day >> month >> year;
//		fin >> firstName >> secondName;
//		elements[i].day = day;
//		elements[i].month = month;
//		elements[i].year = year;
//		elements[i].firstName = firstName;
//		elements[i].secondName = secondName;
//		i++;
//	}
//}
//
//template <typename T1>
////
////int IsBigger(T1 firstElement, T1 secondElement)
////{
////	if (firstElement > secondElement)
////	{
////		return 1;
////	}
////	else if (firstElement < secondElement)
////	{
////		return 0;
////	}
////}
////
////int ChooseType(int root1, int root2, Element* table)
////{
////	int Is;
////	switch (code)
////	{
////	case 0:
////	{
////		Is = (IsBigger(table->elements[root1].firstName, table->elements[root2].firstName));
////		break;
////	}
////	case 1:
////	{
////		Is = (IsBigger(table->elements[root1].secondName, table->elements[root2].secondName));
////		break;
////	}
////	case 2:
////	{
////		Is = (IsBigger(table->elements[root1].thirdName, table->elements[root2].thirdName));
////		break;
////	}
////	case 3:
////	{
////		Is = (IsBigger(table->elements[root1].day, table->elements[root2].day));
////		break;
////	}
////	case 4:
////	{
////		Is = (IsBigger(table->elements[root1].month, table->elements[root2].month));
////		break;
////	}
////	case 5:
////	{
////		Is = (IsBigger(table->elements[root1].year, table->elements[root2].year));
////		break;
////	}
////	}
////	return Is;
////}
////
////void sorts(Element* table, int root, int bottom)
////{
////	int maxChild;
////	int done = 0;
////	while ((root * 2) <= bottom && (!done))
////	{
////		if (root * 2 == bottom) {
////			maxChild = root * 2;
////		}
////		else {
////
////			if (ChooseType(root * 2, root * 2 + 1, table))
////			{
////				maxChild = root * 2;
////			}
////			else {
////				maxChild = root * 2 + 1;
////			}
////
////
////
////		}
////
////		if (ChooseType(maxChild, root, table))
////		{
////			Element  temp = table->elements[root];
////			table->elements[root] = table->elements[maxChild];
////			table->elements[maxChild] = temp;
////			root = maxChild;
////		}
////		else done = 1;
////
////
////
////	}
////
////}
////
////void PiramidSort(Element* elements)
////{
////	int size = sizeElements;
////	for (int i = (size / 2) - 1; i >= 0; i--)
////	{
////		sorts(elements, i, size - 1);
////
////	}
////	for (int i = size - 1; i >= 1; i--)
////	{
////		Element temp = table->elements[0];
////		table->elements[0] = table->elements[i];
////		table->elements[i] = temp;
////		sorts(table, 0, i - 1);
////	}
////
////
////}
//
////void Print(Element* Guy)
////{
////	for (int i = 0; i < Guy->count; i++)
////	{
////		cout << Guy->elements[i].day << "." << Guy->elements[i].month << "." << Guy->elements[i].year << " ";
////		cout << Guy->elements[i].firstName << " " << Guy->elements[i].secondName << " " << Guy->elements[i].thirdName << "\n";
////	}
////}
//
//bool isempty(ifstream& pFile)
//{
//	return pFile.peek() == ifstream::traits_type::eof();
//}
//
//
//void main() {
//
//	Element *elements = (Element*) malloc (N*sizeof(Element));
//	setlocale(LC_ALL, "Russian");
//	fin.open("input.txt");
//
//	if (!fin)
//	{
//		cout << "file not open" << endl;
//	}
//
//	//if (isempty(fin))
//	//{
//	//	cout << "Table is empty" << endl;
//	//}
//	else
//	{
//		cout << "Тип сортировки:\n 1: Сортировка по Фамилии\n 2: Сортировка по Отчеству\n 3: Сортировка по Имени\n 4: Сортировка по дню рождения\n 5: Сортировка по месяцу рождения\n 6: Сортировка по году рождения\n";
//		cin >> code;
//		code = code - 1;
//
//		ReadFile(elements);
//
//		elements = NULL;
//		
//	}
//}