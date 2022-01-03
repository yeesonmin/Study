#include<iostream>
using namespace std;

class Test
{
public:
	int radius = 0;
	double getArea();
	Test();
	Test(int a);
private:

};

double Test::getArea()
{
	return 3.14*radius * radius;
}

//持失切
Test::Test() {
	radius = 3;
}

//持失切2
Test::Test(int a) {
	radius = a;
}

void main() {
	Test Cicle;
	Cicle.radius = 5;

	double result = Cicle.getArea();
	cout << result <<endl;

	Test Cicle2;
	Cicle2.radius = 50;

	double result2 = Cicle2.getArea();
	cout << result2 << endl;

	Test Cicle3;

	double result3 = Cicle3.getArea();
	cout << result3 << endl;

	Test Cicle4(10);

	double result4 = Cicle4.getArea();
	cout << result4 << endl;
}