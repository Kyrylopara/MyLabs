#include <iostream>
#include <fstream>
#include <time.h>
#define GEN_LEN (32)
using namespace std;

string Gen()
{
	string data;
	char c;
	for (int i = 0; i < GEN_LEN; i++)
	{
		int r = (rand() % 100);
	
		if (r >= 48 and r <= 52)
			c = ' ';
		else if (r > 52)
		{
			c = rand() % 26 + 65;
			c = ((rand() % 100 > 50) ? c : tolower(c));
		}
		else
			c = rand() % 10 + '0';
		data += c;
		
	}
	
	try {
		if (c >= 'A' and c <= 'Z' or c >= '0' and c <= '9')
			throw "В файле не будут указаны цифры и большие буквы.";
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception << '\n';
	}

		
	
	return data;
}

class OL
{
public:
	OL(const string& s): data(s)
	{

	}
	const string& GetData() const;
	friend ostream& operator <<(ostream& out, const OL& a);
private:
	string data;
};

const string& OL::GetData() const
{
	return data;
}

ostream& operator <<(ostream& out, const OL& a)
{
	for (char c : a.data)
	{
		if (c >= '0' and c <= '9')
			continue;
		if (c >= 'A' and c <= 'Z')
			continue;
		out << c;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));

	OL a(Gen());

	cout << "Source string: " << a.GetData() << endl;


	ofstream fout;

	fout.open("out");
	fout << a;
	fout.close();

	return 0;
}