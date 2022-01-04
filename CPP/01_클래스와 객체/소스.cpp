#include<iostream>
#include"Test.h"
using namespace std;



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