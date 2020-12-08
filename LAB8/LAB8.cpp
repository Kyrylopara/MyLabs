#include <iostream>

using namespace std;


template <typename T>
class Number
{
public:
	Number(T a = 0);

	Number<T> operator +(const Number<T>& other) const;

	friend ostream& operator <<(ostream& out, const Number<T>& a);
private:
	T v;
};

template<typename T>
Number<T>::Number(T a)
{
	v = a;
}

template<typename T>
Number<T> Number<T>::operator +(const Number<T>& other) const
{
	return Number(v + other.v);
}

ostream& operator <<(ostream& out, const Number<char>& a)
{
	out << "<char> " << (int)a.v;
	return out;
}

ostream& operator <<(ostream& out, const Number<short>& a)
{
	out << "<short> " << a.v;
	return out;
}

ostream& operator <<(ostream& out, const Number<int>& a)
{
	out << "<int> " << a.v;
	return out;
}

ostream& operator <<(ostream& out, const Number<float>& a)
{
	out << "<float> " << a.v;
	return out;
}

ostream& operator <<(ostream& out, const Number<double>& a)
{
	out << "<double> " << a.v;
	return out;
}

template class Number<int>;
template class Number<float>;

int main()
{
	Number<int> A(1), B(1);

	cout << "A == " << A << endl;
	cout << "B == " << B << endl;

	cout << "C = A + B == " << (A + B) << endl;

	Number<float> Af(1.1), Bf(1.1);

	cout << "A == " << Af << endl;
	cout << "B == " << Bf << endl;

	cout << "C = A + B == " << (Af + Bf) <<endl;

	return 0;
}