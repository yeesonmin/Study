#pragma once

//조건 컴파일 => 다른 헤더에서 선언했을 때 충돌 방지
#ifndef TEST_H //상수처리 된게 있으면 값이 false가 되서 endif으로 전달
#define TEST_H //상수 처리 됨.
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

//생성자
Test::Test() {
	radius = 3;
}

//생성자2
Test::Test(int a) {
	radius = a;
}

#endif // !TEST_H

