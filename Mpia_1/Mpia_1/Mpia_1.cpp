#include "Header.h"

int AddTable(Table* table, int year, string firstName, string secondName)
{
	int tableCount = table->count;
	if (tableCount < M)
	{
		int place = tableCount;
		table->elements[place].year = year;
		table->elements[place].firstName = firstName;
		table->elements[place].secondName = secondName;
		table->count++;
	}
	return 1;
}

int ReadFile(Table* table)
{
	int year;
	string firstName;
	string secondName;


	while (!fin.eof() && table->count < M)
	{
		fin >> year >> firstName >> secondName;
		if (!AddTable(table, year, firstName, secondName))
			return 0;

	}
	return 1;
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

void Print(Table* Guy)
{
	for (int i = 0; i < Guy->count; i++)
	{
		cout << Guy->elements[i].year << " ";
		cout << Guy->elements[i].firstName << " " << Guy->elements[i].secondName << "\n";
	}
}

bool isempty(ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}

//int getName(int name)
//{
//	return name;
//}


void main() {

	Table table;
	
	setlocale(LC_ALL, "Russian");
	fin.open("input.txt");

	if (!fin)
	{
		cout << "file not open" << endl;
	}

	//if (isempty(fin))
	//{
	//	cout << "Table is empty" << endl;
	//}
	else
	{
		cout << "Введите размер массива записей\n";
		cin >> M;
		if (!ReadFile(&table))
		{
			cout << "Ошибка чтения файла";
		}
	
		fin.close();


		cout << "Таблица до сортировки выглядит следующим образом:\n";
		//Print(&table);
		printf_s("\n");

		cout << "Таблица после сортировки по Фамилии:\n";
		auto start = std::chrono::high_resolution_clock::now();

		PiramidSort(&table, 0);

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		//Print(&table);
		cout << "Time PiramidSortName " << diff.count() << endl;
		printf_s("\n");

		cout << "Таблица после сортировки по году рождения:\n";
		auto start1 = std::chrono::high_resolution_clock::now();

		PiramidSort(&table, 1);

		auto end1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff1 = end1 - start1;
		//Print(&table);
		cout << "Time PiramidSortDate " << diff1.count() << endl;
		printf_s("\n");

		system("pause");
	}
}