#include<iostream>

using namespace std;

void change(int n);
void main() {
	//�Ž�����
	//ī���� : 500, 100, 50, 10 �� ������
	//�մԿ��� �� �Ž��ҵ��� N�̸� �Ž������� �ּ� ����
	change(2560);

}

void change(int n) {
	int result = 0;
	int t = 0;
	
	result = n / 500;
	t = n % 500;
	result += (t / 100);
	t = t % 100;
	result += (t / 50);
	t = t % 50;
	result += (t / 10);
	t = t % 10;

	cout << result;
}