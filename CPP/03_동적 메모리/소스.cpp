#include<iostream>
using namespace std;



void main() {
	//new : 데이터 타입 크기만큼 힙으로 메모리 할당
	int* pint = new int; //int 타입공간 할당

	//delete : 할당한 메모리 반환
	delete pint;


	//메모리 초기화
	int* pint2 = new int(20);///20으로 초기화된 공간 할당
	delete pint2;
}