#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;
class strana
{
public:
	strana()
		: nazvanie(nullptr), stolitsa(nullptr), ploshad(0), naselenie(0)
	{
	}

	void change(const char* _nazv, const char* _stol, double _plosh, long _nasel);

	void setNazvanie(const char* _nazv);

	const char* getNazvanie() const;
	const char* getStolitsa() const;
	double      getPloshad() const;
	long        getNaselenie() const;
private:
	char*  nazvanie;
	char*  stolitsa;
	double ploshad;
	long   naselenie;
};

void strana::change(const char* _nazv, const char* _stol, double _plosh, long _nasel)
{
	ploshad = _plosh;
	naselenie = _nasel;
	if (nazvanie)
		free(nazvanie);
	nazvanie = new char[strlen(_nazv) + 1];
	strcpy(nazvanie, _nazv);
	if (stolitsa)
		free(stolitsa);
	stolitsa = new char[strlen(_stol) + 1];
	strcpy(stolitsa, _stol);
}

void strana::setNazvanie(const char* _nazv)
{
	if (nazvanie)
		free(nazvanie);
	nazvanie = new char[strlen(_nazv) + 1];
	strcpy(nazvanie, _nazv);
}

const char* strana::getNazvanie() const
{
	return nazvanie;
}

const char* strana::getStolitsa() const
{
	return stolitsa;
}

double strana::getPloshad() const
{
	return ploshad;
}

long strana::getNaselenie() const
{
	return naselenie;
}

void sort(strana* objs, size_t count)
{
	strana t;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i + 1; j < count; j++)
		{
			if (objs[i].getPloshad() > objs[j].getPloshad())
			{
				t = objs[i];
				objs[i] = objs[j];
				objs[j] = t;
			}
		}
	}
}

void show(strana* objs, size_t count)
{
	cout << "                            СТРАНА: \n";
	cout << "----------------------------------------------------------------\n";
	cout << "  Название      Столица           Площадь              Население\n";
	cout << "----------------------------------------------------------------\n";

	for (size_t i = 0; i < count; i++)
	{
	cout << setw(10) << objs[i].getNazvanie();
	cout << setw(13) << objs[i].getStolitsa();
	cout << setw(18) << objs[i].getPloshad();
	cout << setw(23) << objs[i].getNaselenie() << endl;
	}
	cout << "----------------------------------------------------------------\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	int r = 0;

	strana objs[7];

	for (int a = 0; !a;)
	{
		cout << "1. Добавить страну\n";
		cout << "2. Сортировка стран\n";
		cout << "3. Печать стран\n";
		cout << "4. Выйти\n";
		cout << "> ";
		int p;
		cin >> p;
		switch (p)
		{
		case 1:
		{
			objs[0].change("Украина","Киев",266.345,123456789);
			objs[1].change("Англия", "Лондон", 200.345, 123456789);
			objs[2].change("Германия", "Брлин", 234.345, 123456789);
			objs[3].change("Чехия", "Прага", 100.345, 123456789);
			objs[4].change("Ирландия", "Дублин", 125.345, 123456789);
			objs[5].change("Франция", "Париж", 230.345, 123456789);
			objs[6].change("Норвегия", "Осло", 250.345, 123456789);
			r = 1;
			break;
		}
		case 2:
		{
			if (r == 0)
			{
				cout << "В базе нет записей.";
				getchar();
			}
			else if (r == 1)
				sort(objs, 7);
			break;
		}

		case 3:
		{
			if (r == 0)
				cout << "В базе нет записей.";
			else if (r == 1)
				show(objs, 7);
			getchar();
			break;
		}
		case 4:
		{
			a = 1;
			break;
		}
		default:
		{
			cout << "Неверный вызов!";
			getchar();
			break;
		}
		}
	}
	return 0;
}