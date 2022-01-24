#include <iostream>
using namespace std;

template <class T>
T Sum(T a, T b);//템플릿으로 제네릭 함수 생성

template <class T>
void print(T a);

void print(char a);//제네릭 함수보다 함수 중복이 우선순위가 높다.

void main() {
	cout << Sum(1, 4) << endl;
	cout << Sum(1.5, 4.1) << endl;

	char a = 1;
	print(1);
	print(1.1);
	print('1');
	print(a);
}

template <class T>
T Sum(T a, T b) {
	return a + b;
}

template <class T>
void print(T a) {
	cout << a << endl;
}

void print(char a) {
	cout << (int)a << endl;
}