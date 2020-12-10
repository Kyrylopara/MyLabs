#include <iostream>
#include <cassert>

using namespace std;

namespace HF
{
	template <typename T>
	T sum(T* a, size_t len)
	{
		T S = (T)0;
		for (size_t i = 0; i < len; i++)
			//if (a[i] > 0)
				S += a[i];
		return S;
	}

	template <typename T>
	void sort(T* a, size_t len)
	{
		bool sorted = true;
		for (size_t i = 1; i < len; i++)
		{
			if (a[i] < a[i - 1])
			{
				sorted = false;
				break;
			}
		}
		if (sorted)
			return;

		do
		{
			for (size_t i = 1; i < len; i++)
			{
				if (a[i] < a[i - 1])
					std::swap(a[i], a[i - 1]);
			}
			sorted = true;
			for (size_t i = 1; i < len; i++)
			{
				if (a[i] < a[i - 1])
				{
					sorted = false;
					break;
				}
			}
		} while (!sorted);
	}

	template <typename T>
	T min(T a, T b)
	{
		return (a > b ? b : a);
	}
}

int main()
{
	const int n_count = 8;
	float arr[n_count] = { 0.5f, -1.5f, 2.3f, 0.1f, -3.6f, 1.f, 0.9f, 1.f };

	HF::sort(arr, n_count);
	bool sorted = true;
	for (int i = 1; i < n_count; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			sorted = false;
			break;
		}
	}
	assert(sorted && "Incorrect SORT function");
	for (int i = 0; i < n_count; i++)
	{
		cout << arr[i];
		if (i < n_count - 1)
			cout << ", ";
	}
	cout << endl;

	int a = 1, b = 11;
	
	const int expected1 = 1;
	int M = HF::min(a, b);
	assert(expected1 == M && "Incorrect MIN function");
	cout << "MIN(" << a << ", " << b << "): " << M << endl;

	
	float expected2 = (-3.6f-1.5f + 0.1f + 0.5f + 0.9f + 1.f + 1.f + 2.3f);
	float S = HF::sum(arr, n_count);
	assert(expected2 == S && "Incorrect SUM function");
	cout << "SUM(arr): " << S << endl;

	return 0;
}