#include<iostream>
#include"Test.h"
using namespace std;



void main() {
	//������ ����
	Test t1;
	Test *pt1 = &t1;

	cout << t1.getArea() <<endl;
	cout << pt1->getArea() << endl;

	//������ �迭 ����
	Test t2[3];
	Test* pt2 = t2;
	t2[0].radius = 5;
	t2[1].radius = 10;
	t2[2].radius = 15;

	for (int i = 0; i < 3; i++)
	{
		cout << "����" << i << " : " << t2[i].getArea() << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "����" << i << " : " << pt2->getArea() << endl;
		pt2++;

	}

	//��ü �迭 ������
	Test t3[3] = { Test(3), Test(6), Test(9) };
	Test* pt3 = t3;

	for (int i = 0; i < 3; i++)
	{
		cout << "������ " << i << " : " << t3[i].radius << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "p������ " << i << " : " << (pt3 + i)->radius << endl;
	}

	//������ ��ü �迭
	Test t4[2][3] = {
		{ Test(3), Test(6), Test(9)},
		{ Test(5), Test(6), Test(7)}
	};

	Test (*pt4)[3] = t4;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "������ " << i << " : " << t4[i][j].radius << endl;
		}
	}

	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "������ " << i << " : " << (*(pt4 + i) + j)->radius << endl;
		}
	}
}