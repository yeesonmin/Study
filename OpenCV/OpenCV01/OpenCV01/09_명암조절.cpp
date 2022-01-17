//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void contrast1();
//void contrast2();
//
//int main(void)
//{
//	contrast1();
//	contrast2();
//
//	return 0;
//}
//
//void contrast1()
//{
//	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	float s = 2.f;
//	Mat dst = s * src;//이 방식은 사용안함.
//
//	imshow("src", src);
//	imshow("dst", dst);
//	waitKey();
//
//	destroyAllWindows();
//}
//
//void contrast2()
//{
//	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	float alpha = 1.f;
//	Mat dst = src + (src - 128) * alpha;//중간값 설정해서 기준보다 작으면 작게, 크면 크게 적용
//
//	imshow("src", src);
//	imshow("dst", dst);
//	waitKey();
//
//	destroyAllWindows();
//}
