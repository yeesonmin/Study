#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void main() {

	//1�� �� ������
	int n, k;
	int result = 0;
	cin >> n >> k;

	while (n != 1)
	{
		if (n % k != 0) {
			n--;
			result++;
		}
		else
		{
			n /= k;
			result++;
		}
	}

	cout << result;
}

