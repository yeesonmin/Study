#include <iostream>
#include <string>
using namespace std;

void main() {
	//¿Õ½ÇÀÇ ³ªÀÌÆ®
	string s;
	cin >> s;

	//a~h
	//1~8
	int row = s[0] - 'a' + 1;
	int col = s[1] - '0';
	int result = 0;

	//¿ì2
	if (row + 2 <= 8) {
		//À§1
		if (col - 1 > 0) result++;
		//¾Æ1
		if (col + 1 <= 8) result++;
	}

	//ÁÂ2
	if (row - 2 > 0) {
		//À§1
		if (col - 1 > 0) result++;
		//¾Æ1
		if (col + 1 <= 8) result++;
	}

	//»ó2
	if (col - 2 > 0) {
		//¿Þ1
		if (row - 1 > 0) result++;
		//¿ì1
		if (row + 1 <= 8) result++;
	}

	//ÇÏ2
	if (col + 2 <= 8) {
		//¿Þ1
		if (row - 1 > 0) result++;
		//¿ì1
		if (row + 1 <= 8) result++;
	}

	cout << result;
}