#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void color_op();
void color_inverse();
void color_grayscale();
void color_split();

void color_req();//명도 조절

int lower_hue = 40, upper_hue = 80;
Mat src, src_hsv, mask;

void on_hue_changed(int, void*);
void color_inrange();
void color_backpoj();//히스토그램 역투영


int main(void)
{
	//color_op();
	//color_inverse();
	//color_grayscale();
	//color_split();
	//color_req();
	//color_inrange();
	color_backpoj();
	return 0;
}

void color_op()
{
	Mat img = imread("butterfly.jpg", IMREAD_COLOR);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Vec3b& pixel = img.at<Vec3b>(0, 0);
	uchar b1 = pixel[0];
	uchar g1 = pixel[1];
	uchar r1 = pixel[2];

	Vec3b* ptr = img.ptr<Vec3b>(0);
	uchar b2 = ptr[0][0];
	uchar g2 = ptr[0][1];
	uchar r2 = ptr[0][2];
}

void color_inverse()
{
	Mat src = imread("butterfly.jpg", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			//Vec3b& p1 = src.at<Vec3b>(j, i);
			//Vec3b& p2 = dst.at<Vec3b>(j, i);

			//p2[0] = 255 - p1[0]; // B
			//p2[1] = 255 - p1[1]; // G
			//p2[2] = 255 - p1[2]; // R

			dst.at<Vec3b>(j, i) = Vec3b(255, 255, 255) - src.at<Vec3b>(j, i);
		}
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void color_grayscale()
{
	Mat src = imread("butterfly.jpg");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

void color_split()
{
	Mat src = imread("candies.png");
	Mat dst2;
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes);
	merge(bgr_planes, dst2); //여러 채널 합치기

	imshow("src", src);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);
	imshow("dst2", dst2);
	
	

	waitKey();
	destroyAllWindows();
}

void color_req()
{
	Mat src = imread("pepper.bmp", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat src_ycrcb;
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);//밝기와 색정보가 있는 YCrCb로 변환

	vector<Mat> ycrcb_planes;
	split(src_ycrcb, ycrcb_planes);

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]); // Y channel

	Mat dst_ycrcb;
	merge(ycrcb_planes, dst_ycrcb);

	Mat dst;
	cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR);

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return;
}


void on_hue_changed(int, void*)
{
	Scalar lowerb(lower_hue, 100, 0);//색상, 채도, 명도
	Scalar upperb(upper_hue, 255, 255);
	inRange(src_hsv, lowerb, upperb, mask);

	imshow("mask", mask);
}

void color_inrange()
{
	src = imread("candies.png", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	imshow("src", src);

	namedWindow("mask");
	createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey(0);
	return;
}
void color_backpoj()
{
	// Calculate CrCb histogram from a reference image

	Mat ref, ref_ycrcb, mask;
	ref = imread("ref.png", IMREAD_COLOR);
	mask = imread("mask.bmp", IMREAD_GRAYSCALE);
	cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);

	Mat hist;
	int channels[] = { 1, 2 };
	int cr_bins = 128; int cb_bins = 128;
	int histSize[] = { cr_bins, cb_bins };
	float cr_range[] = { 0, 256 };
	float cb_range[] = { 0, 256 };
	const float* ranges[] = { cr_range, cb_range };

	calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);//기준영상에서 crcb 히스토그램 계산해서 hist에 저장

	// Apply histogram backprojection to an input image

	Mat src, src_ycrcb;
	src = imread("kids.png", IMREAD_COLOR);
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);

	Mat backproj;
	calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true);//구한 hist를 이용해서 다른 영상의 crcb 구하기

	imshow("src", src);
	imshow("backproj", backproj);
	waitKey(0);

	return;
}