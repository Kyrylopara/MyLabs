#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>


using namespace std;

class work
{
public:

	friend ostream& operator<<(ostream& stream, work& o1);
	friend istream& operator>>(istream& stream, work& o1);
	friend void shapka();
	friend void linebuild();

	work();
	work(const char* a, unsigned int b, double c, double d);
	void set(const char* a, unsigned int b, double c, double d);
	void get(char* a, unsigned int b, double c, double d);
	void show();
	char* ret_name();
private:
	char* name;
	unsigned int lines;
	double time1;
	double time2;
};

class DB
{
	char title[30];
	work* rows[12];
	int col;
	int sorted;
public:
	DB(const char* q);
	~DB();
	void add_rec(const char* a, unsigned int b, double c, double d);
	void del_rec();
	void sort_DB();
	friend ostream& operator<<(ostream& stream, DB& temp);
};

DB::DB(const char* q)
	: col(0), sorted(0)
{
	strcpy(title, q);
}

DB::~DB()
{
	if (col)
	{
		for (int i = 0; i < col; i++)
			delete rows[i];
	}
}

void DB::add_rec(const char* a, unsigned int b, double c, double d)
{
	if (col >= 12)
		return;
	else col++;
	rows[col - 1] = new work(a, b, c, d);
	sorted = 0;
}

void DB::del_rec()
{
	if (col <= 0)
		return;
	delete rows[col - 1];
	col--;
}

void DB::sort_DB()
{
	char* s1;
	char* s2;
	if (col < 2)
		return;
	work* temp;

	for (int i = 0; i < col; i++)
	{
		for (int j = i + 1; j < col; j++)
		{
			s1 = rows[i]->ret_name();
			s2 = rows[j]->ret_name();
			if (strcmp(s1, s2) > 0)
			{
				temp = rows[i];
				rows[i] = rows[j];
				rows[j] = temp;
			}
		}
	}
	sorted = 1;
}

void shapka()
{
	cout << "________________________________________________________________________________________________________________\n";
	cout << "|                Время выполнения некоторых программ, которые применяют параллельные алгоритмы                  |\n";
	cout << "|---------------------------------------------------------------------------------------------------------------|\n";
	cout << "|  Название прграммы  | Количество строк кода | Время исп. на SGI Callenge (cек) | Время исп. на SGI Indy (cек) |\n";
	cout << "|---------------------------------------------------------------------------------------------------------------|\n";
}

void linebuild()
{
	cout << "\n|-------------------------------------------------------------------------------------------------------------|\n";
}

ostream& operator<<(ostream& stream, DB& o1)
{
	stream << o1.title << endl;
	if (o1.sorted == 0)
		stream << "Таблица не отсортирована.\n";
	else
		stream << "Таблица отсортирована.\n";
	shapka();
	if (!o1.col)
		stream << "Таблица пуста.";
	else
	{
		for (int i = 0; i < o1.col; i++)
			stream << *o1.rows[i];
	}
	return stream;
}

ostream& operator<<(ostream& stream, work& o1)
{
	stream << "|" << setw(19) << o1.name << "  |  ";
	stream << setw(5) << o1.lines << "       |";
	stream << setw() << o1.time1 << "             |";
	stream << setw(19) << o1.time2 << "           |";
	linebuild();
	return stream;
}

work::work()
	: time1(0), time2(0)
{

}

work::work(const char* a, unsigned int b, double c, double d)
	: lines(b), time1(c), time2(d)
{
	name = new char[strlen(a) + 1];
	strcpy(name, a);
}

void work::set(const char* a, unsigned int b, double c, double d)
{
	strcpy(name, a);
	lines = b;
	time1 = c;
	time2 = d;
}

void work::show()
{
	cout << name << " ";
	cout << lines << " ";
	cout << time1 << " ";
	cout << time2 << " ";
}

void work::get(char* a, unsigned int b, double c, double d)
{
	strcpy(a, name);
	b = lines;
	c = time1;
	d = time2;
}

char* work::ret_name()
{
	return name;
}

int main()
{
	setlocale(LC_ALL,"rus");
	char* n;
	char t;
	unsigned int s;
	float h;
	short i;
	short q, q1;

	DB* tmp = new DB("\nБАЗА ДАННЫХ ╧1\n");

	for (int a = 0; !a;)
	{
		cout << "1. Добавить запись\n";
		cout << "2. Удалить запись\n";
		cout << "3. Сортировать базу\n";
		cout << "4. Вывести базу\n";
		cout << "5. Выход\n";
		cout << "> ";
		int p;
		cin >> p;
		switch (p)
		{
		case 1:
			cout << "Название, Кол-во строк, Время исп. на SGI Callenge (cек), Время исп. на SGI Indy (cек) \n";


			/*n = new char[32]; // Закомментированные строки отвечают за чтение значений
			cin >> n;         // переменных с клавиатуры и записи их в поля объекта.
			cin >> t;         // Для удобства работы используется инициализация через
			cin >> s;         // конструктор 3-х объектов.
			cin >> h;
			tmp->add_rec(n,t,s,h);
			delete[] n;*/


			tmp->add_rec("OCEAN", 1917, 8.70, 18.2);
			tmp->add_rec("DYFESM", 3386, 6.95, 22.0);
			tmp->add_rec("TRFD", 417, 1.05, 2.98);
			break;
		case 2:
			tmp->del_rec();
			break;
		case 3:
			tmp->sort_DB();
			break;
		case 4:
			cout << *tmp;
			cout << "\nНажмите клавишу для продолжения...";
			getchar();
			break;
		case 5:
			a = 1;
			break;
		default:
			cout << "Неверный вызов";
			getchar();
			break;
		}
	}
	return 0;
}