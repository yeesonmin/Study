#pragma once

//���� ������ => �ٸ� ������� �������� �� �浹 ����
#ifndef TEST_H //���ó�� �Ȱ� ������ ���� false�� �Ǽ� endif���� ����
#define TEST_H //��� ó�� ��.
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
	return 3.14 * radius * radius;
}

//������
Test::Test() {
	radius = 3;
}

//������2
Test::Test(int a) {
	radius = a;
}

#endif // !TEST_H

