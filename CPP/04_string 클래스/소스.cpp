#include<iostream>
#include <string>
using namespace std;

void main() {
	string str;
	string address("ㅋㅋ");
	string copyadd(address);
	string copyadd2(address , 2);//바이트 단위로 복사

	cout << address << " " << copyadd<<" "<< copyadd2 << endl;

	//string 동적 생성
	string* ps = new string("c++");
	cout << *ps << endl;
	ps->append(" heard");
	cout << *ps << endl;
	delete ps;


	//string 입력
	string sin;
	cin >> sin;
	cout << sin << endl;

	string sin2;
	getline(cin, sin2, '0');//'0'만날 때 까지 입력
	cout << sin2 << endl;

	//문자열 비교
	string a1 = "apple", b1 = "apple2";
	int res1 = a1.compare(b1);// 0 : 같다, 음수 : a1이 먼저 온다. 양수 : b1이 먼저 온다.
	cout << res1 << endl;

	//문자열 삽입
	string a2 = "1 +  = 2";
	a2.insert(3, " 1");
	cout << a2 << endl;
	a2.replace(0, 1, "12");
	cout << a2 << endl;

	//문자열 길이
	string a3 = "123456789";
	int len1 = a3.length();//문자 개수
	int len2 = a3.size();//문자 개수
	int len3 = a3.capacity();//문자 용량

	cout << len1 << endl << len2 << endl << len3 << endl;

	//문자 삭제
	a3.clear();
	a2.erase(0, 3);
	cout << a3 << endl << a2 << endl;

	//문자열 일부 얻기
	string a4 = "123456";
	string a5 = a4.substr(2, 3);
	cout << a4 << endl << a5 << endl;
	a5 = a4.substr(2);
	cout << a4 << endl << a5 << endl;

	//문자열 검색
	int index = a4.find("abc");//없으며 0
	int index2 = a4.find("123");//있으면 가장 가까운 위치 반환
	int index3 = a4.find("123",3);
	cout << index << endl << index2 << endl << index3 <<endl;

	//문자열 숫자 변환
	int n = stoi(a4);//atoi : c++ 2008 이하
	cout << n << endl;
}
