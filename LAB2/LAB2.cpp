#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <ostream>
#include <iostream>

using namespace std;

#define N 3             

class work {
	string name;
	unsigned int lines;
	double time1;
	double time2;
	friend ostream& operator<<(ostream& stream, work& o1);
	friend istream& operator>>(istream& stream, work& o1);
	friend void shapka(void);
	friend void linebuild(void);
	friend int isvalid(int a, int b);
public:
	work() { time1 = 0; time2 = 0; }
	work(string a, unsigned int b, double c, double d);
	void setall(string a, unsigned int b, double, double);
	void getall(string a, unsigned int b, double& c, double& d);
	void showall(void);
	work& operator = (work& o1);
	int    operator == (work& o1);
	work operator + (work& o1);
};

void shapka(void)
{
	std::cout << "_________________________________________________________________________________________________\n";
	std::cout << "|                |\n";
	std::cout << "|-----------------------------------------------------------------------------------------------|\n";
	std::cout << "|   |  |  SGI Indy() | SGI Indy()|\n";
	std::cout << "|-----------------------------------------------------------------------------------------------|\n";
}

void linebuild(void) {
	std::cout << "|-----------------------------------------------------------------------------------------------|\n";
}

ostream& operator<<(ostream& stream, work& o1) {
	shapka();
	stream << "|" << setw(10) << o1.name << "  |  ";
	stream << setw(9) << o1.lines << "       |";
	stream << setw(18) << o1.time1 << "              |";
	stream << setw(19) << o1.time2 << "           |" << endl;
	linebuild();
	return stream;
}

istream& operator>>(istream& stream, work& o1) {
	std::cout << " \n";
	stream >> o1.name;
	stream >> o1.lines;
	stream >> o1.time1;
	stream >> o1.time2;
	return stream;
}

int isvalid(int a, int b) {
	if (((a > N - 1) || (a < 0)) || ((b > N - 1) || (b < 0)))
	{
		std::cout << ".\n";
		_getch();
		return -1;
	}
	else if (a == b)
	{
		std::cout << ".\n";
		_getch();
		return -2;
	}
	return 0;
}

work work::operator + (work& o1) {
	work tr;
	tr.name = name + o1.name;
	tr.lines = lines + o1.lines;
	tr.time1 = time1 + o1.time1;
	tr.time2 = time2 + o1.time2;
	return tr;
}

int work::operator == (work& o1) {
	if (ceil(time1) != ceil(o1.time1)) { std::cout << "."; _getch(); }
	else if (ceil(time2) != ceil(o1.time2)) { std::cout << "."; _getch(); }
	else if (name != o1.name) { std::cout << "."; _getch(); }
	else if (lines != o1.lines) { std::cout << "."; _getch(); }
	else std::cout << "."; _getch();
	return 0;
}



work& work::operator = (work& o1) {
	name = o1.name;
	lines = o1.lines;
	time1 = o1.time1;
	time2 = o1.time2;
	return *this;
}

work::work(string a, unsigned int b, double c, double d) {
	name = a;
	lines = b;
	time1 = c;
	time2 = d;
}

void work::setall(string a, unsigned int b, double c, double d) {
	name = a;
	lines = b;
	time1 = c;
	time2 = d;
}

void work::showall(void) {
	cout << name << " ";
	cout << lines << " ";
	cout << time1 << " ";
	cout << time2 << " ";
}

void work::getall(string a, unsigned int b, double& c, double& d)
{
	a = name;
	b = lines;
	c = time1;
	d = time2;
	cout << a << " ";
	cout << b << " ";
	cout << c << " ";
	cout << d << " ";
	cout << "\n";
}


int main(void) {
	setlocale(LC_ALL, "Ukrainian");

	string n;
	unsigned int t = 0;
	double s;
	double h;
	short i, k;
	unsigned int s1;
	short q, q1;

	work obj[N]
	{
		work("OCEAN",1917, 8.70, 18.2),
		work("DYFESM",3386, 6.95, 22.0),
		work("TRFD", 417, 1.05, 2.98)
	};

	system("cls");
	cout.precision(2);
	cout << " \n";
	for (i = 0; i < N; i++) {
		obj[i].showall();
		cout << "\n";
	}

	cout << "\n.\n";
	cout << ">\n";
	cin >> q;
	cin >> q1;
	if (isvalid(q, q1) != 0) exit(-1);
	obj[q] = obj[q1];

	cout << " \n";
	for (i = 0; i < N; i++) {
		obj[i].showall();
		cout << "\n";
	}

	cout << "\n '=='.\n";
	cout << ">\n";
	cin >> q;
	cin >> q1;
	if (isvalid(q, q1) != 0) exit(-1);
	obj[q] == obj[q1];

	cout << "\n'+'.\n";
	cout << ">\n";
	cin >> q;
	cin >> q1;
	if (isvalid(q, q1) != 0) exit(-1);
	work temp = obj[q] + obj[q1];
	cout << " \n";
	temp.getall(n, t, s, h);

	cout << "\n'>>'.";
	cout << "\n ";
	cin >> q;
	if ((q > N - 1) || (q < 0)) { cout << "."; _getch(); exit(-1); }
	cin >> obj[q];

	cout << "\n '<<'.";
	cout << "\n: ";
	cin >> q;
	if ((q > N - 1) || (q < 0)) { cout << "."; _getch(); exit(-1); }
	cout << obj[q];

	_getch();
	return 0;
}