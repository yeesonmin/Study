#include<iostream>
using namespace std;

char c = 'a';
char get() {
	return c;
}

//���� ���� => c = get2
char& get2() {
	return c;
}

void main() {
	char a = get();// �Ϲ����� �� ����
	cout << a << endl;
	//get() = 'b';//������ ����

	//���� ���� ���
	char a2 = get2();
	cout << a2 << endl;

	get2() = 'b';
	a2 = get2();
	cout << a2 << endl;
}