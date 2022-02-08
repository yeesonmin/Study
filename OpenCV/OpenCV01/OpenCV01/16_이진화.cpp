//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void on_threshold(int pos, void* userdata);
//void on_trackbar(int pos, void* userdata);
//
//void threshold1();
//void threshold2();
//void adaptivethreshold();
//
//int main(int argc, char* argv[])
//{
//	//threshold1();
//	//threshold2();
//	adaptivethreshold();
//	return 0;
//}
//
//
//void on_threshold(int pos, void* userdata)
//{
//	Mat src = *(Mat*)userdata;
//
//	Mat dst;
//	threshold(src, dst, pos, 255, THRESH_BINARY);
//
//	imshow("dst", dst);
//}
//
//void threshold1()
//{
//	Mat src;
//
//	src = imread("neutrophils.png", IMREAD_GRAYSCALE);
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	imshow("src", src);
//
//	namedWindow("dst");
//	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
//	setTrackbarPos("Threshold", "dst", 128);
//
//	waitKey(0);
//}
//void threshold2()
//{
//	Mat src;
//
//	src = imread("sudoku.jpg", IMREAD_GRAYSCALE);//불균일한 영상 => 적응형 이진화 사용해야 함.
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	imshow("src", src);
//
//	namedWindow("dst");
//	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
//	setTrackbarPos("Threshold", "dst", 128);
//
//	waitKey(0);
//}
//
//void adaptivethreshold()
//{
//	Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	imshow("src", src);
//
//	namedWindow("dst");
//	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
//	setTrackbarPos("Block Size", "dst", 11);
//
//	waitKey(0);
//	return;
//}
//
//void on_trackbar(int pos, void* userdata)
//{
//	Mat src = *(Mat*)userdata;
//
//	int bsize = pos;
//	if (bsize % 2 == 0) bsize--;
//	if (bsize < 3) bsize = 3;
//
//	Mat dst;
//	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,	bsize, 2);
//
//	imshow("dst", dst);
//}