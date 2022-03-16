#include<iostream>

using namespace std;

void change(int n);
void main() {
	//거스름돈
	//카운터 : 500, 100, 50, 10 이 무제한
	//손님에게 줄 거스롬돈이 N이면 거스름돈의 최소 갯수
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