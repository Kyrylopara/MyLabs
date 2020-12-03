#include <iostream>
#include <conio.h>
using namespace std;

class B1 {
	int b1;
public:
	B1() : b1(0) { };
	B1(int x) { b1 = x; }
	void show_B1() { cout << "B1=  " << b1 << "\n"; }
};

class B2 {
	int b2;
public:
	B2() : b2(0) { };
	B2(int x) { b2 = x; };
	void show_B2() { cout << "B2=  " << b2 << "\n"; }
};

class D1 : public  B1 {
	int d1;
public:
	D1(int x, int y) : B1(y) { d1 = x; };
	void show_D1() { cout << "D1=  " << d1 << "\n"; show_B1(); }
};

class D2 : private  B1 {
	int d2;
public:
	D2(int x, int y) : B1(y) { d2 = x; }
	void show_D2() { cout << "D2=  " << d2 << "\n"; show_B1(); }
};

class D4 :public D1, public D2, private B2 {
	int d4;
public:
	D4(int x, int y, int z, int f, int e, int i) : D1(y, z), D2(f, e), B2(i) { d4 = x; }
	void show_D4() { cout << "D4=  " << d4 << "\n"; show_D1(); show_D2(); show_B2(); }
};


int main() {
	setlocale(LC_ALL, "Ukrainian");
	system("cls");

	D4 temp1(1, 2, 3, 4, 5, 6);
	cout << "D4 temp1(1,2,3,4,5,6);\n";
	cout << "\nСледуя иерархии класса D4\n";
	temp1.show_D4();

	return 0;
}