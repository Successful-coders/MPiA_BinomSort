#include "pch.h"
#include "CppUnitTest.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include <fstream>
#include <iostream>
#include <chrono>
unsigned long int M = 10;
ifstream fin;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	private:

		
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

		int sorts(Table* table, int root, int bottom, int code)
		{
			if (table->count != 0)
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
							if (IsBigger(table->elements[root * 2].firstName, table->elements[root * 2 + 1].firstName)) {
								maxChild = root * 2;
							}
							else {
								maxChild = root * 2 + 1;
							}
						}
						if (code == 1)
						{
							if (IsBigger(table->elements[root * 2].year, table->elements[root * 2 + 1].year))
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
				return 1;
			}
			else
				return 0;

		}

		int PiramidSort(Table* table, int code)
		{
			if (table->count != 0)
			{
				int size = table->count;
				for (int i = (size / 2) - 1; i >= 0; i--)
				{

					if (!sorts(table, i, size - 1, code))
						return 0;

				}
				for (int i = size - 1; i >= 1; i--)
				{
					Element temp = table->elements[0];
					table->elements[0] = table->elements[i];
					table->elements[i] = temp;
					if (!sorts(table, 0, i - 1, code))
						return 0;
				}
				return 1;
			}
			return 0;
		}
		

public:
	// test for IsBigger method
	TEST_METHOD(TestClass_Check_IsBigger_firstEl)
	{
		int firstEl = 2;
		int secondEl = 0;
		int result = 1;//ferst element bigger
		Assert::AreEqual(result, IsBigger(firstEl, secondEl));
	}
	TEST_METHOD(TestClass_Check_IsBigger_secondEl)
	{
		int firstEl = 0;
		int secondEl = 2;
		int result = 0;//secondEl bigger
		Assert::AreEqual(result, IsBigger(firstEl, secondEl));
	}
	TEST_METHOD(TestClass_Check_IsBigger_sameEl)
	{
		int firstEl = 2;
		int secondEl = 2;
		int result = 0;// same number
		Assert::AreEqual(result, IsBigger(firstEl, secondEl));
	}

	// test for PiramidSort method
	TEST_METHOD(TestClass_Check_PiramidSort_FullTable)
	{
		Table table;
		table.count = 2;
		table.elements[0].firstName = "Anna";
		table.elements[1].firstName = "Ioanna";
		table.elements[0].secondName = "Voron";
		table.elements[1].secondName = "Bom";
		table.elements[0].year = 1900;
		table.elements[1].year = 2000;

		int result = 1;//sucsessfull ending
		Assert::AreEqual(result, PiramidSort(&table, 1));
	}
	TEST_METHOD(TestClass_Check_PiramidSort_EmptyTable)
	{
		Table table;
		table.count = 0;

		int result = 0;//bad ending
		Assert::AreEqual(result, PiramidSort(&table, 1));
	}
	//test for sorts method
	TEST_METHOD(TestClass_Check_Sort_FullTable)
	{
		Table table;
		table.count = 2;
		table.elements[0].firstName = "Anna";
		table.elements[1].firstName = "Ioanna";
		table.elements[0].secondName = "Voron";
		table.elements[1].secondName = "Bom";
		table.elements[0].year = 1900;
		table.elements[1].year = 2000;

		int result = 1;// sucsessfull ending
		Assert::AreEqual(result, sorts(&table, 2,3,0));
	}

	TEST_METHOD(TestClass_Check_Sort_EmptyTable)
	{
		Table table;
		table.count = 0;

		int result = 0;//bad ending
		Assert::AreEqual(result, sorts(&table, 1,2,0));
	}
	};
}
