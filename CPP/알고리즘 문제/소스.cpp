#include <iostream>
#include <string>
using namespace std;

void main() {
	//�ս��� ����Ʈ
	string s;
	cin >> s;

	//a~h
	//1~8
	int row = s[0] - 'a' + 1;
	int col = s[1] - '0';
	int result = 0;

	//��2
	if (row + 2 <= 8) {
		//��1
		if (col - 1 > 0) result++;
		//��1
		if (col + 1 <= 8) result++;
	}

	//��2
	if (row - 2 > 0) {
		//��1
		if (col - 1 > 0) result++;
		//��1
		if (col + 1 <= 8) result++;
	}

	//��2
	if (col - 2 > 0) {
		//��1
		if (row - 1 > 0) result++;
		//��1
		if (row + 1 <= 8) result++;
	}

	//��2
	if (col + 2 <= 8) {
		//��1
		if (row - 1 > 0) result++;
		//��1
		if (row + 1 <= 8) result++;
	}

	cout << result;
}