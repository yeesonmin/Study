#include <iostream>
using namespace std;

class Calculator
{
public:
	virtual int add(int a, int b) = 0;//순수 가상 함수 => 순수 가상함수가 1개라도 있으면 추상클래스
	virtual int sub(int a, int b) = 0;
	virtual double avg(int a[], int size) = 0;
};

class GoodCal : Calculator
{
public:
	virtual int add(int a, int b) { return a + b; }
	int sub(int a, int b) { return a - b; }
	double avg(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += a[i];
		}
		return sum / size;
	}

};


void main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	GoodCal b, *pb;
	pb = &b;

	cout << pb->add(1, 2) << endl;
	cout << pb->sub(1, 2) << endl;
	cout << pb->avg(a, sizeof(a)/sizeof(a[0])) << endl;

}

