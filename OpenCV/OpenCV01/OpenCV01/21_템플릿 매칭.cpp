//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void template_matching();
//
//int main()
//{
//	template_matching();
//
//	return 0;
//}
//
//void template_matching()
//{
//	Mat img = imread("circuit.bmp", IMREAD_COLOR);
//	Mat templ = imread("crystal.bmp", IMREAD_COLOR);
//
//	if (img.empty() || templ.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	img = img + Scalar(50, 50, 50);
//
//	Mat noise(img.size(), CV_32SC3);
//	randn(noise, 0, 10);
//	add(img, noise, img, Mat(), CV_8UC3);
//
//	Mat res, res_norm;
//	matchTemplate(img, templ, res, TM_CCOEFF_NORMED);//최댓값 위치가 매칭이 가장 일치함.
//	normalize(res, res_norm, 0, 255, NORM_MINMAX, CV_8U);//정규화 진행해서 값을 0~255까지 균일화함.
//
//	double maxv;
//	Point maxloc;
//	minMaxLoc(res, 0, &maxv, 0, &maxloc);//값 중에서 최댓값 추출
//	cout << "maxv: " << maxv << endl;
//
//	rectangle(img, Rect(maxloc.x, maxloc.y, templ.cols, templ.rows), Scalar(0, 0, 255), 2);//
//
//	imshow("templ", templ);
//	imshow("res", res);
//	imshow("res_norm", res_norm);
//	imshow("img", img);
//
//	waitKey(0);
//	destroyAllWindows();
//}
