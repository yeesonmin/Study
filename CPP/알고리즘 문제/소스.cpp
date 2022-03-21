#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



void main() {

	//»óÇÏÁÂ¿ì
	int n;
	int c = 1, r = 1;
	int result = 0;
	char s;

	cin>> n;
	cin.ignore();
	do
	{
		cin.get(s);
		switch (s)
		{
		case 'R':
			if (r + 1 <= n) r++;
			break;
		case 'L':
			if (r - 1 > 0) r--;
			break;
		case 'U':
			if (c - 1 > 0) c--;
			break;
		case 'D':
			if (c + 1 <= n) c++; 
			break;
		default:
			break;
		}
	} while (s != '\n');
	
	cout << c << " " << r;
}

