#include <iostream>
using namespace std;

void main() {

	int n = 0;
	while (true)
	{
		try
		{
			cin >> n;

			if (n == -1) {
				throw n;//catch로 값 전달
			}

		}
		catch (const int n)
		{
			cout << "오류 발생" << endl;
			break;
		}
	}
	
}