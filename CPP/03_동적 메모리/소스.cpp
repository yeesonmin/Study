#include<iostream>
using namespace std;



void main() {
	//new : ������ Ÿ�� ũ�⸸ŭ ������ �޸� �Ҵ�
	int* pint = new int; //int Ÿ�԰��� �Ҵ�

	//delete : �Ҵ��� �޸� ��ȯ
	delete pint;


	//�޸� �ʱ�ȭ
	int* pint2 = new int(20);///20���� �ʱ�ȭ�� ���� �Ҵ�
	delete pint2;
}