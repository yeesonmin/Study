#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void sobel_derivative();
void sobel_edge();
void canny_edge();
void hough_lines();
void hough_line_segments();
void hough_circles();

int main(void)
{
	//sobel_derivative();
	//sobel_edge();
	//canny_edge();

	//hough_lines();
	//hough_line_segments();
	hough_circles();
	return 0;
}

void sobel_derivative()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	//중앙차분
	Mat mx = Mat_<float>({ 1, 3 }, { -1 / 2.f, 0, 1 / 2.f });
	Mat my = Mat_<float>({ 3, 1 }, { -1 / 2.f, 0, 1 / 2.f });

	Mat dx, dy;
	filter2D(src, dx, -1, mx, Point(-1, -1), 128);//각 값에 128을 더함
	filter2D(src, dy, -1, my, Point(-1, -1), 128);

	imshow("src", src);
	imshow("dx", dx);
	imshow("dy", dy);

	waitKey();
	destroyAllWindows();
}

void sobel_edge()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dx, dy;
	//Sobel(src, dx, CV_32FC1, 1, 0);//소벨 필터 마스크
	//Sobel(src, dy, CV_32FC1, 0, 1);
	Scharr(src, dx, CV_32FC1, 1, 0);//샤르 필터 마스크(소벨 보다 정확하다고 함)
	Scharr(src, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;
	magnitude(dx, dy, fmag);//벡터 크기 계산
	fmag.convertTo(mag, CV_8UC1);//그레이스케일 형식으로 변환

	//Mat edge = mag > 150;//150보다 크면 255, 작으면 0
	Mat edge = mag > 240;//(샤르필터에 적용)
	imshow("src", src);
	imshow("mag", mag);
	imshow("edge", edge);

	waitKey();
	destroyAllWindows();
}

void canny_edge()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst1, dst2;
	Canny(src, dst1, 50, 100);//두 임계값에 따른 엣지 출력 변화
	Canny(src, dst2, 50, 150);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

void hough_lines()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat edge;
	Canny(src, edge, 50, 150);

	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		float rho = lines[i][0], theta = lines[i][1];
		float cos_t = cos(theta), sin_t = sin(theta);
		float x0 = rho * cos_t, y0 = rho * sin_t;
		float alpha = 1000;//직선 길이를 곱함.

		Point pt1(cvRound(x0 - alpha * sin_t), cvRound(y0 + alpha * cos_t));
		Point pt2(cvRound(x0 + alpha * sin_t), cvRound(y0 - alpha * cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

void hough_line_segments()
{
	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat edge;
	Canny(src, edge, 50, 150);

	vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (Vec4i l : lines) {
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

void hough_circles()
{
	Mat src = imread("coins.png", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat blurred;
	blur(src, blurred, Size(3, 3));//잡음제거

	vector<Vec3f> circles;
	HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);//50 : 검출할 원의 최소중심 거리, 150 : 캐니 에지 하이값, 30 : 추적 배열 원소 수 => 원의 중심 선택할 값

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (Vec3f c : circles) {
		Point center(cvRound(c[0]), cvRound(c[1]));
		int radius = cvRound(c[2]);
		circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}