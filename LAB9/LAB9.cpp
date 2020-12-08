#include <iostream>
#include <vector>
using namespace std;

class Sum
{
public:
	Sum()
		: a(0), b(0), S(0)
	{ }

	Sum(int _a, int _b)
		: a(_a), b(_b)
	{
		S = a + b;
	}

	int get() const
	{
		return S;
	}

	bool operator <(const Sum& other) const
	{
		return (S < other.S);
	}

	bool operator ==(const Sum& other) const
	{
		return (S == other.S);
	}


private:
	int a, b, S;
};

int main()
{
	setlocale(LC_ALL, "rus");
	
	vector<Sum> A = { Sum(1,0),Sum(0,1)};
	vector<Sum> B = { Sum(0,0),Sum(0,0)};
	
	int FS;

	cout << "vector A: ";
	FS = 0;
	for (const Sum& s : A)
	{
		cout << s.get() << " ";
		FS += s.get();
	}
	cout << endl << "Full sum: " << FS << endl;
	try {
		if (FS == 0)
			throw "Вектор А не существует";
	}
	catch (const char* exeption) {

		cout << "Error:" << exeption << endl;
	}
	FS = 0;

	cout << "vector B: ";
	for (const Sum& s : B)
	{
		cout << s.get() << " ";
		FS += s.get();
	}
	cout << endl << "Full sum: " << FS << endl;

	try {
		if (FS == 0)
			throw "Вектор В не существует";
	}
	catch (const char* exeption) {

		cout << "Error:" << exeption << endl;
	}

	cout << "A < B:  " << (A < B) << endl;
	cout << "A > B:  " << (A > B) << endl;
	cout << "A == B: " << (A == B) << endl;

	return 0;
}