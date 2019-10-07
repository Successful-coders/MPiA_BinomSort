#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include <fstream>
#include <iostream>
#include <chrono>
using namespace std;
unsigned long int M = 10;
ifstream fin;
struct Element
{
	int year;
	string firstName;
	string secondName;
};

struct Table
{
	Element* elements = new Element[M];
	int count = 0;
};

int AddTable(Table* table, int year, string firstName, string secondName);
int ReadFile(Table* table);
int sorts(Table* table, int root, int bottom, int code);
int PiramidSort(Table* table, int code);
int getName(int name);