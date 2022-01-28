//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int arithmetic();
//int logic();
//int main(void)
//{
//	arithmetic();
//	logic();
//	return 0;
//}
//
//int arithmetic() {
//	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
//	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty()) {
//		cerr << "Image load failed!" << endl;
//		return -1;
//	}
//
//	imshow("src1", src1);
//	imshow("src2", src2);
//
//	Mat dst1, dst2, dst3, dst4;
//
//	add(src1, src2, dst1);
//	addWeighted(src1, 0.5, src2, 0.5, 0, dst2);
//	subtract(src1, src2, dst3);
//	absdiff(src1, src2, dst4);//움직이는 물체를 검출할 수 있다.
//
//	imshow("dst1", dst1);
//	imshow("dst2", dst2);
//	imshow("dst3", dst3);
//	imshow("dst4", dst4);
//	waitKey();
//}
//
//int logic() {
//	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
//	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty()) {
//		cerr << "Image load failed!" << endl;
//		return -1;
//	}
//
//	imshow("src1", src1);
//	imshow("src2", src2);
//
//	Mat dst1, dst2, dst3, dst4;
//
//	bitwise_and(src1, src2, dst1);
//	bitwise_or(src1, src2, dst2);
//	bitwise_xor(src1, src2, dst3);
//	bitwise_not(src1, dst4);
//
//	imshow("dst1", dst1);
//	imshow("dst2", dst2);
//	imshow("dst3", dst3);
//	imshow("dst4", dst4);
//	waitKey();
//}