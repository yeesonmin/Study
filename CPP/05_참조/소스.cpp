#include<iostream>
using namespace std;

char c = 'a';
char get() {
	return c;
}

//참조 리턴 => c = get2
char& get2() {
	return c;
}

void main() {
	char a = get();// 일반적인 값 리턴
	cout << a << endl;
	//get() = 'b';//컴파일 오류

	//참조 리턴 결과
	char a2 = get2();
	cout << a2 << endl;

	get2() = 'b';
	a2 = get2();
	cout << a2 << endl;
}