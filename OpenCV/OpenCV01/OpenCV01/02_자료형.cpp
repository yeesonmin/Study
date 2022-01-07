#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//Point
	Point pt1;
	pt1.x = 5;	pt1.y = 10;
	Point pt2(10, 2);
	Point pt3 = pt1 * 2;
	Point pt4 = pt1 + pt2;

	int d1 = pt1.dot(pt2);//�� ���� ����
	bool b1 = (pt1 == pt2);

	cout << "pt1 : " << pt1 <<endl;
	cout << "pt2 : " << pt2 << endl;
	cout << "pt3 : " << pt3 << endl;
	cout << "pt4 : " << pt4 << endl;
	cout << "d1 : " << d1 << endl;
	cout << "b1 : " << b1 << endl;


	//Size
	Size sz1;
	sz1.width = 10; sz1.height = 15;
	Size sz2(10, 20);
	Size sz3 = sz1 + sz2;
	Size sz4 = sz1 * 3;
	int ara1 = sz1.area();

	cout << "sz1 : " << sz1 << endl;
	cout << "sz2 : " << sz2 << endl;
	cout << "sz3 : " << sz3 << endl;
	cout << "sz4 : " << sz4 << endl;
	cout << "ara1 : " << ara1 << endl;


	//Rect
	Rect rc1;
	rc1.x = 10; rc1.y = 10; rc1.width = 30; rc1.height = 40;
	Rect rc2(20, 10, 40, 40);
	Rect rc3 = rc1 + Size(10, 10);//rc1�� �� ũ�⸦ ����.
	Rect rc4 = rc1 + Point(20, 20);//rc1�� �� ��ǥ�� ����.
	Rect rc5 = rc1 & rc2;// �� �簢���� �������� ��ȯ
	Rect rc6 = rc1 | rc2;// �� �簢���� ��� �����ϴ� �ּ� ũ���� �簢�� ��ȯ

	cout << "rc1 : " << rc1 << endl;
	cout << "rc2 : " << rc2 << endl;
	cout << "rc3 : " << rc3 << endl;
	cout << "rc4 : " << rc4 << endl;
	cout << "rc5 : " << rc5 << endl;
	cout << "rc6 : " << rc6 << endl;

	//RotatedRect
	RotatedRect rr1(Point2f(10,10),Size2f(5,5),30.f);//�߽���ǥ, ũ��, ȸ����
	Point2f pts[4];
	rr1.points(pts);//ȸ���� �簢���� 4�� ������ ��ǥ ��ȯ
	Rect br = rr1.boundingRect();//ȸ���� �簢���� ������ �ּ�ũ�� �簢�� ��ȯ

	cout << "pts : " << pts << endl;
	cout << "br : " << br << endl;

	//Range
	Range r1(0, 10);
	int rsize = r1.size();//���̸� ��ȯ
	cout << "rsize : " << rsize << endl;

	//String
	String str1 = "Hi";
	String str2 = " Seon";
	String str3 = str1 + str2;
	String str4 = format("age : %d", 25);
	cout << str3 << endl;
	cout << str4 << endl;




}