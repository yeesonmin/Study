#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
using namespace std;

int main() {
	Shape *pStart = NULL;
	Shape* pLast;

	pStart = new Circle();
	pLast = pStart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Rect());


	Shape* ptemp = pStart;
	while (ptemp != NULL)
	{
		ptemp->paint();
		ptemp = ptemp->getNext();

	}

	ptemp = pStart;
	while (ptemp != NULL)
	{
		Shape* ptemp2 = ptemp->getNext();
		delete ptemp;
		ptemp = ptemp2;

	}
}