#include<iostream>
#include <string>
using namespace std;

void main() {
	string str;
	string address("����");
	string copyadd(address);
	string copyadd2(address , 2);//����Ʈ ������ ����

	cout << address << " " << copyadd<<" "<< copyadd2 << endl;

	//string ���� ����
	string* ps = new string("c++");
	cout << *ps << endl;
	ps->append(" heard");
	cout << *ps << endl;
	delete ps;


	//string �Է�
	string sin;
	cin >> sin;
	cout << sin << endl;

	string sin2;
	getline(cin, sin2, '0');//'0'���� �� ���� �Է�
	cout << sin2 << endl;

	//���ڿ� ��
	string a1 = "apple", b1 = "apple2";
	int res1 = a1.compare(b1);// 0 : ����, ���� : a1�� ���� �´�. ��� : b1�� ���� �´�.
	cout << res1 << endl;

	//���ڿ� ����
	string a2 = "1 +  = 2";
	a2.insert(3, " 1");
	cout << a2 << endl;
	a2.replace(0, 1, "12");
	cout << a2 << endl;

	//���ڿ� ����
	string a3 = "123456789";
	int len1 = a3.length();//���� ����
	int len2 = a3.size();//���� ����
	int len3 = a3.capacity();//���� �뷮

	cout << len1 << endl << len2 << endl << len3 << endl;

	//���� ����
	a3.clear();
	a2.erase(0, 3);
	cout << a3 << endl << a2 << endl;

	//���ڿ� �Ϻ� ���
	string a4 = "123456";
	string a5 = a4.substr(2, 3);
	cout << a4 << endl << a5 << endl;
	a5 = a4.substr(2);
	cout << a4 << endl << a5 << endl;

	//���ڿ� �˻�
	int index = a4.find("abc");//������ 0
	int index2 = a4.find("123");//������ ���� ����� ��ġ ��ȯ
	int index3 = a4.find("123",3);
	cout << index << endl << index2 << endl << index3 <<endl;

	//���ڿ� ���� ��ȯ
	int n = stoi(a4);//atoi : c++ 2008 ����
	cout << n << endl;
}
