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
				throw n;//catch�� �� ����
			}

		}
		catch (const int n)
		{
			cout << "���� �߻�" << endl;
			break;
		}
	}
	
}