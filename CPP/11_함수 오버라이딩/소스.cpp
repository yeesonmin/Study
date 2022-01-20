#include <iostream>
using namespace std;
class Parent {
public:
	void func() { cout << "�θ� Ŭ������ func �Լ� ȣ��!" << endl; }
};

class Child : public Parent {//�Լ� �������̵�
public:
	void func() { cout << "�ڽ� Ŭ������ func �Լ� ȣ��!" << endl; }
};

class Parent2 {
public:
	virtual void func() { cout << "�θ� Ŭ������ func �Լ� ȣ��!" << endl; }
};

class Child2 : public Parent2 {//�����Լ� �������̵�
public:
	virtual void func() { cout << "�ڽ� Ŭ������ func �Լ� ȣ��!" << endl; }//�Ļ� Ŭ������ virtual ��������
};

class Parent3 {
public:
	virtual void func() { cout << "�θ� Ŭ������ func �Լ� ȣ��!" << endl; }
};

class Child3 : public Parent3 {//������� Ȯ�� override
public:
	virtual void func() override { cout << "�ڽ� Ŭ������ func �Լ� ȣ��!" << endl; }
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
	pP->func();//����ĳƼ ������ �θ� Ŭ���� ���

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
