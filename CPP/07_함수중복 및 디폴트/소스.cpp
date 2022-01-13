#include <iostream> 
using namespace std;

//함수 중복 및 디폴트
int big(int a, int b, int c);
int big(int a, int b, int c = 100);

void main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60,50);
	cout << x << " " << y << " " << z;
}

int big(int a, int b, int c)
{
	int r = a > b ? a : b;
	int re = r > c ? c : r;
	return re;
}
