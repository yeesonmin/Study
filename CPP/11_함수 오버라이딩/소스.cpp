#include <iostream>
using namespace std;
class Parent {
public:
	void func() { cout << "부모 클래스의 func 함수 호출!" << endl; }
};

class Child : public Parent {//함수 오버라이딩
public:
	void func() { cout << "자식 클래스의 func 함수 호출!" << endl; }
};

class Parent2 {
public:
	virtual void func() { cout << "부모 클래스의 func 함수 호출!" << endl; }
};

class Child2 : public Parent2 {//가상함수 오버라이딩
public:
	virtual void func() { cout << "자식 클래스의 func 함수 호출!" << endl; }//파생 클래스는 virtual 생략가능
};

class Parent3 {
public:
	virtual void func() { cout << "부모 클래스의 func 함수 호출!" << endl; }
};

class Child3 : public Parent3 {//오버라딩 확인 override
public:
	virtual void func() override { cout << "자식 클래스의 func 함수 호출!" << endl; }
};
int main()
{
	Parent P, * pP;
	Child C, *pC;

	pP = &P;
	pP->func();

	pC = &C;
	pC->func();

	pP = &C;
	pP->func();//업스캐티 때문에 부모 클래스 출력

	Parent2 P2, * pP2;
	Child2 C2, * pC2;

	pP2 = &P2;
	pP2->func();

	pC2 = &C2;
	pC->func();

	pP2 = &C2;
	pP2->func();

	Parent3 P3, * pP3;
	Child3 C3, * pC3;

	pP3 = &P3;
	pP3->func();

	pC3 = &C3;
	pC->func();

	pP3 = &C3;
	pP3->func();
	return 0;
}
