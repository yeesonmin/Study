#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

void ScanDocument();
void main() {
	ScanDocument();
}

void ScanDocument()
{
	//이미지 읽기
	Mat img = imread("..\\..\\imgs\\exam_document.jpg");
	Mat img2 = imread("..\\..\\imgs\\exam_document2.jpg");
	Mat img_g, img_g2;
	cvtColor(img, img_g, COLOR_BGR2GRAY);
	cvtColor(img2, img_g2, COLOR_BGR2GRAY);

	//잡음 제거
	Mat gaus, gaus2;
	GaussianBlur(img_g, gaus, Size(), 3);
	GaussianBlur(img_g2, gaus2, Size(), 3);

	//사이즈 변경
	resize(gaus, gaus,Size(), 0.125, 0.125);
	resize(img, img, Size(), 0.125, 0.125);
	resize(gaus2, gaus2, Size(), 0.125, 0.125);
	resize(img2, img2, Size(), 0.125, 0.125);
	
	////엣지 검출
	Mat edge, edge2;
	Canny(gaus, edge, 150, 300);
	Canny(gaus2, edge2, 150, 300);

	//4개 꼭짓점 찾기
	Mat img_corner, img_corner2;
	img.copyTo(img_corner);
	img2.copyTo(img_corner2);

	vector<KeyPoint> keypoints, keypoints2;
	FAST(gaus, keypoints, 100, true);
	FAST(gaus2, keypoints2, 100, true);

	for (KeyPoint kp : keypoints) {
		Point pt(cvRound(kp.pt.x), cvRound(kp.pt.y));
		circle(img_corner, pt, 5, Scalar(0, 0, 255), 2);
	}

	for (KeyPoint kp : keypoints2) {
		Point pt(cvRound(kp.pt.x), cvRound(kp.pt.y));
		circle(img_corner2, pt, 5, Scalar(0, 0, 255), 2);
	}

	//불필요한 점 제거


	//문서 출력
	imshow("gaus", gaus);
	imshow("edge", edge);
	imshow("img_corner", img_corner);

	imshow("gaus2", gaus2);
	imshow("edge2", edge2);
	imshow("img_corner2", img_corner2);
	//imshow("result", img_g);
	waitKey();
}
