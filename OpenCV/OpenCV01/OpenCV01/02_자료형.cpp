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

	int d1 = pt1.dot(pt2);//두 점의 내적
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
	Rect rc3 = rc1 + Size(10, 10);//rc1에 각 크기를 더함.
	Rect rc4 = rc1 + Point(20, 20);//rc1에 각 좌표를 더함.
	Rect rc5 = rc1 & rc2;// 두 사각형에 교차영역 반환
	Rect rc6 = rc1 | rc2;// 두 사각형을 모두 포함하는 최소 크기의 사각형 반환

	cout << "rc1 : " << rc1 << endl;
	cout << "rc2 : " << rc2 << endl;
	cout << "rc3 : " << rc3 << endl;
	cout << "rc4 : " << rc4 << endl;
	cout << "rc5 : " << rc5 << endl;
	cout << "rc6 : " << rc6 << endl;

	//RotatedRect
	RotatedRect rr1(Point2f(10,10),Size2f(5,5),30.f);//중심좌표, 크기, 회전각
	Point2f pts[4];
	rr1.points(pts);//회전한 사각형의 4개 꼭지점 좌표 반환
	Rect br = rr1.boundingRect();//회전한 사각형을 포함한 최소크기 사각형 반환

	cout << "pts : " << pts << endl;
	cout << "br : " << br << endl;

	//Range
	Range r1(0, 10);
	int rsize = r1.size();//길이를 반환
	cout << "rsize : " << rsize << endl;

	//String
	String str1 = "Hi";
	String str2 = " Seon";
	String str3 = str1 + str2;
	String str4 = format("age : %d", 25);
	cout << str3 << endl;
	cout << str4 << endl;

	//Mat
	Mat img1(480, 640, CV_8UC1);//그레이
	Mat img2(480, 640, CV_8UC3);//트루컬러
	Mat img3(Size(480, 640), CV_8UC3);
	Mat img4(Size(480, 640), CV_8UC1,Scalar(128));//모든 픽셀 값 128
	Mat img5(Size(480, 640), CV_8UC3, Scalar(0,0, 128));//빨강 픽셀 값 128
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	// 000
	// 000
	// 000

	Mat mat2 = Mat::ones(3, 3, CV_32SC1);
	// 111
	// 111
	// 111

	Mat mat3 = Mat::eye(3, 3, CV_32SC1);
	// 100
	// 010
	// 001

	float data[] = { 1,2,3,4,5,6, };
	Mat mat4(2, 3, CV_32SC1, data);
	
	Mat_<float> mat5_(2, 3);
	mat5_ << 1, 2, 3, 4, 5, 6;
	Mat mat5 = mat5_;// 한 줄 코드 Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<float>({ 2,3 }, { 1,2,3,4,5,6 });
	// 1 2 3
	// 4 5 6

	mat4.create(256, 256, CV_8UC3);//Mat 새로 만들기

	//setTo
	mat5.setTo(1.f);// 모든 원소값을 일괄적으로 설정
	
	//Mat 복사
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1; //앝은 복사 => 하나 영상 공유
	Mat img3 = img1.clone(); // 깊은 복사 = > 각각 변수에 영상 복사 

	//Mat 부분 행렬 추출
	Mat img4 = imread("cat.bmp");
	Mat img5 = img4(Rect(220, 120, 340, 240));//(220,120) 부터 (340, 240)까지 추출(얕은 복사)
	Mat img6 = img4(Rect(220, 120, 340, 240)).clone();//(220,120) 부터 (340, 240)까지 추출(깊은 복사)

	//at 행렬 원소값 참조
	Mat atmat = Mat::zeros(3, 4, CV_8UC1);
	for (int i = 0; i < atmat.rows; i++)
	{
		for (int j = 0; j < atmat.cols; j++)
		{
			atmat.at<uchar>(j, i)++;//각각의 원소값을 1씩 증가
		}
	}

	//ptr 행렬의 특정 행 주소 반환
	for (int i = 0; i < atmat.rows; i++)
	{
		uchar* pmat = mat1.ptr<uchar>(i);
		for (int j = 0; j < atmat.cols; j++)
		{
			pmat[j]++;//각각의 원소값을 1씩 증가
		}
	}

	//at, ptr 크기 초과 방지 MatIterator_ 단, 속도가 느림
	for (MatIterator_<uchar> it = atmat.begin<uchar>(); it != atmat.end<uchar>(); ++it)
	{
		(*it)++;
	}

	//타입 변환
	Mat img7 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat img8;
	img7.convertTo(img8, CV_32FC1);

	//resize 행크기 변환
	mat1.resize(5, 100);//값이 없는 값은 100으로 반환
}