//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

struct hesh
{
	string id;
	int value;
	int hesh_code;
	bool collision;
	bool unaval;
	bool terminal;
	bool delining;
	hesh* next;
	string data;
};

int alpha(char);
int get_value(string);
int get_hesh(int, int);
void add_el(vector <hesh>&, string, string);
void del_el(vector <hesh>&, string);
void print_search_el(vector <hesh>, string);
void print_table(vector <hesh>);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t\t\t\tВариант 31\n";
	cout << "\t\t\t\t\tМатематика\n\n";
	cout << "\t\t\t\tИспользованные переменные\n";
	vector <hesh> table;
	add_el(table, "Черчение", "Геометрия");
	add_el(table, "Арифметика", "Алгебра");
	add_el(table, "Дифференциал", "Матанализ");
	add_el(table, "Случайность", "Теория вероятности");
	add_el(table, "Предел", "Матанализ");
	add_el(table, "Теория моделей", "Матлогика");
	add_el(table, "Матрица", "Алгебра");
	add_el(table, "Величина шанса", "Теория вероятности");
	add_el(table, "Теория рекурсий", "Матлогика");
	add_el(table, "Общая алгебра", "Алгебра");
	add_el(table, "Интеграл", "Матанализ");
	add_el(table, "Общая логика", "Матлогика");
	add_el(table, "Планиметрия", "Геометрия");
	add_el(table, "Силлогистика", "Матлогика");
	add_el(table, "Нечеткая логика", "Матлогика");
	add_el(table, "Производная", "Матанализ");
	add_el(table, "Теория групп", "Алгебра");
	add_el(table, "Независимость", "Теория вероятности");
	add_el(table, "Стереометрия", "Геометрия");
	add_el(table, "Матожидание", "Теория вероятности");
	add_el(table, "Теория колец", "Алгебра");
	add_el(table, "Исчисление", "Матанализ");
	add_el(table, "Теорема Н — Л", "Матанализ");
	add_el(table, "Топология", "Геометрия");
	print_table(table);
	del_el(table, "Матожидание");
	cout << endl << endl;
	print_table(table);
	cout << endl;
	print_search_el(table, "Планиметрия");
	cout << endl;
	system("pause");
	return 0;
}

int alpha(char symb)
{
	if (symb == 'а' || symb == 'А')
	{
		return 1;
	}
	else if (symb == 'б' || symb == 'Б')
	{
		return 2;
	}
	else if (symb == 'в' || symb == 'В')
	{
		return 3;
	}
	else if (symb == 'г' || symb == 'Г')
	{
		return 4;
	}
	else if (symb == 'д' || symb == 'Д')
	{
		return 5;
	}
	else if (symb == 'е' || symb == 'Е')
	{
		return 6;
	}
	else if (symb == 'ё' || symb == 'Ё')
	{
		return 7;
	}
	else if (symb == 'ж' || symb == 'Ж')
	{
		return 8;
	}
	else if (symb == 'з' || symb == 'З')
	{
		return 9;
	}
	else if (symb == 'и' || symb == 'И')
	{
		return 10;
	}
	else if (symb == 'й' || symb == 'Й')
	{
		return 11;
	}
	else if (symb == 'к' || symb == 'К')
	{
		return 12;
	}
	else if (symb == 'л' || symb == 'Л')
	{
		return 13;
	}
	else if (symb == 'м' || symb == 'М')
	{
		return 14;
	}
	else if (symb == 'н' || symb == 'Н')
	{
		return 15;
	}
	else if (symb == 'о' || symb == 'О')
	{
		return 16;
	}
	else if (symb == 'п' || symb == 'П')
	{
		return 17;
	}
	else if (symb == 'р' || symb == 'Р')
	{
		return 18;
	}
	else if (symb == 'с' || symb == 'С')
	{
		return 19;
	}
	else if (symb == 'т' || symb == 'Т')
	{
		return 20;
	}
	else if (symb == 'у' || symb == 'у')
	{
		return 21;
	}
	else if (symb == 'ф' || symb == 'Ф')
	{
		return 22;
	}
	else if (symb == 'х' || symb == 'Х')
	{
		return 23;
	}
	else if (symb == 'ц' || symb == 'Ц')
	{
		return 24;
	}
	else if (symb == 'ч' || symb == 'Ч')
	{
		return 25;
	}
	else if (symb == 'ш' || symb == 'Ш')
	{
		return 26;
	}
	else if (symb == 'щ' || symb == 'Щ')
	{
		return 27;
	}
	else if (symb == 'ь' || symb == 'Ь')
	{
		return 28;
	}
	else if (symb == 'ъ' || symb == 'Ъ')
	{
		return 29;
	}
	else if (symb == 'ы' || symb == 'Ы')
	{
		return 30;
	}
	else if (symb == 'э' || symb == 'Э')
	{
		return 31;
	}
	else if (symb == 'ю' || symb == 'Ю')
	{
		return 32;
	}
	else if (symb == 'я' || symb == 'Я')
	{
		return 33;
	}
	else
	{
		return -9999999999;
	}
}
int get_value(string str)
{
	int value = 0;
	int range;
	if (str.size() >= 3)
	{
		range = 3;
	}
	else
	{
		range = str.size();
	}
	for (size_t i = 0; i < range; i++)
	{
		value += 33 * alpha(str[i]);
	}
	return value;
}
int get_hesh(int V, int B)
{
	int val = V % 10 + B;
	return val;
}
void add_el(vector <hesh>& ref, string id, string data)
{
	int val = get_value(id);
	int hsh = get_hesh(val, ref.size());
	hesh boof;
	bool is = false;

	for (size_t i = 0; i < ref.size(); i++)
	{
		if (hsh == ref[i].hesh_code)
		{
			ref[i].collision = true;
			hesh* ptr = &ref[i];
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new hesh;
			ptr = ptr->next;
			ptr->data = data;
			ptr->next = NULL;
			ptr->id = id;
			ptr->value = val;
			ptr->hesh_code = hsh;
			ptr->collision = true;
			ptr->unaval = true;
			ptr->terminal = 0;
			ptr->delining = false;
			is = true;
		}
	}
	if (!is)
	{
		boof.data = data;
		boof.next = NULL;
		boof.id = id;
		boof.value = val;
		boof.hesh_code = hsh;
		boof.collision = false;
		boof.unaval = true;
		boof.terminal = 0;
		boof.delining = false;
		ref.push_back(boof);
	}
}
void del_el(vector <hesh>& ref, string id)
{
	for (int i = 0; i < ref.size(); i++)
	{
		if (ref[i].collision == 1)
		{
			hesh* ptr = &ref[i];
			while (ptr->next != NULL)
			{
				if (ptr->next->id == id && ptr->next->next == NULL)
				{
					ptr->next = NULL;
				}
				else if (ptr->next->id == id && ptr->next->next != NULL)
				{
					ptr->next = ptr->next->next;
				}
				else
				{
					ptr = ptr->next;
				}
			}
		}
		else if (ref[i].id == id)
		{
			ref.erase(ref.begin() + i);
		}
	}
}
void print_search_el(vector <hesh> ref, string id)
{
	hesh srch;
	for (int i = 0; i < ref.size(); i++)
	{
		if (ref[i].collision == 1)
		{
			hesh* ptr = &ref[i];
			while (id != ptr->id && ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			if (id == ptr->id)
			{
				cout << "\tИскомое слово принадлежит разделу - ";
				cout << ptr->data;
				cout << "\n\n";
			}
		}
		else if (ref[i].id == id)
		{
			cout << "\tИскомое слово принадлежит разделу - ";
			cout << ref[i].data;
			cout << "\n\n";
		}
	}
}
void print_table(vector <hesh> ref)
{
	cout << "\tid" <<
		", " << "value" <<
		", " << "hesh_code" <<
		", " << "collision" <<
		", " << "unaval" <<
		", " << "terminal" <<
		", " << "delining" <<
		", " << "next" <<
		", " << "data" << endl << endl;
	for (size_t i = 0; i < ref.size(); i++)
	{
		cout << ref[i].id <<
			'\t' << ref[i].value <<
			'\t' << ref[i].hesh_code <<
			'\t' << ref[i].collision <<
			'\t' << ref[i].unaval <<
			'\t' << ref[i].terminal <<
			'\t' << ref[i].delining <<
			'\t' << ref[i].next <<
			'\t' << ref[i].data << endl;
		if (ref[i].next != NULL)
		{
			cout << endl <<
				"-----------------------------------------------КОЛЛИЗИЯ----------------------------------------------" << endl;
			hesh* ptr;
			ptr = ref[i].next;
			while (ptr != NULL)
			{
				cout << ptr->id <<
					'\t' << ptr->value <<
					'\t' << ptr->hesh_code <<
					'\t' << ptr->collision <<
					'\t' << ptr->unaval <<
					'\t' << ptr->terminal <<
					'\t' << ptr->delining <<
					'\t' << ptr->next <<
					'\t' << ptr->data << endl;
				ptr = ptr->next;
			}
			cout << endl <<
				"------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}

