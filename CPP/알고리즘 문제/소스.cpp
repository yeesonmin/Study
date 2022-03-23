#include <iostream>
#include <string>
using namespace std;

void main() {
	//½Ã°¢
	int n = 0;
	int result = 0;
	cin >> n;

	
	for (size_t i = 0; i <= n; i++)
	{
		
		if ((to_string(i).find("3") != string::npos)) {
			result += 60*60;
			continue;
		}

		for (int j = 0; j < 60; j++)
		{
			if ((to_string(j).find("3") != string::npos)) {
				result += 60;
				continue;
			}

			for (size_t k = 0; k < 60; k++)
			{
				if (to_string(k).find("3") != string::npos) result++;
			}
			
		}
		
	}

	

	cout << result;
}