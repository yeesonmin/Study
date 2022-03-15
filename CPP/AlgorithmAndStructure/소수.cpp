#include<iostream>
#include<vector>
using namespace std;

void Eratosthenes(int a);
void main() {

	Eratosthenes(30);
}

void Eratosthenes(int a)
{
	vector<int> arr(a + 1, 1);

	arr[1] = 0;

	for (size_t i = 2; i <= a; i++)
	{
		if (arr[i] == 0) continue;
		for (size_t j = i*2; j <= a; j+=i)
		{
			arr[j] = 0;
		}
	}

	for (size_t i = 2; i <= a; i++)
	{
		if (arr[i] == 1) {
			cout << i << " ";
		}
	}
}
