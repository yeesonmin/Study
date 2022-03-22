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
	//�̹��� �б�
	Mat img = imread("..\\..\\imgs\\exam_document.jpg");
	Mat img2 = imread("..\\..\\imgs\\exam_document2.jpg");
	Mat img_g, img_g2;
	cvtColor(img, img_g, COLOR_BGR2GRAY);
	cvtColor(img2, img_g2, COLOR_BGR2GRAY);

	//���� ����
	Mat gaus, gaus2;
	GaussianBlur(img_g, gaus, Size(), 3);
	GaussianBlur(img_g2, gaus2, Size(), 3);

	Mat blr, blr2;
	bilateralFilter(gaus, blr, -1, 10, 5);
	bilateralFilter(gaus2, blr2, -1, 10, 5);

	//������ ����
	resize(gaus, gaus,Size(), 0.125, 0.125);
	resize(img, img, Size(), 0.125, 0.125);
	resize(gaus2, gaus2, Size(), 0.125, 0.125);
	resize(img2, img2, Size(), 0.125, 0.125);
	resize(blr, blr, Size(), 0.125, 0.125);
	resize(blr2, blr2, Size(), 0.125, 0.125);

	////���� ����
	Mat edge, edge2;
	Canny(blr, edge, 150, 300);
	Canny(blr2, edge2, 150, 300);

	//�ܰ��� ����
	vector<vector<Point>> contours, contours2;
	findContours(edge, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);//�ܰ��� ����(���� ���� x
	findContours(edge2, contours2, RETR_LIST, CHAIN_APPROX_SIMPLE);//�ܰ��� ����(���� ���� x)

	//������ ����
	Mat img_corner;
	Mat img_corner2;
	Point2f corner[4], corner2[4];
	img.copyTo(img_corner);
	img2.copyTo(img_corner2);
	for (vector<Point> pts : contours) {
		if (contourArea(pts) < 400)//������ 400���� ������ �������� ����
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);//������ ����.

		int vtc = (int)approx.size();
		 if (vtc == 4) {
			 for (size_t i = 0; i < 4; i++)
			 {
				 circle(img_corner, approx[i], 5, Scalar(255, 0, 0), -1, LINE_AA);
				 corner[i] = approx[i];
			 }
			
		}
		
	}

	for (vector<Point> pts : contours2) {
		if (contourArea(pts) < 400)//������ 400���� ������ �������� ����
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);//������ ����.

		int vtc = (int)approx.size();
		if (vtc == 4) {
			for (size_t i = 0; i < 4; i++)
			{
				circle(img_corner2, approx[i], 5, Scalar(255, 0, 0), -1, LINE_AA);
				corner2[i] = approx[i];
			}

		}

	}

	//����Ȯ��
	int w2 = abs(corner2[0].x - corner2[1].x);
	int h2 = abs(corner2[0].y - corner2[2].y);
	int w = abs(corner[0].x - corner[1].x), h = abs(corner[0].y - corner[2].y);
	Point2f dstPts[4], dstPts2[4];
	dstPts[0] = Point2f(0, 0);
	dstPts[1] = Point2f(w - 1, 0);
	dstPts[2] = Point2f(w - 1, h - 1);
	dstPts[3] = Point2f(0, h - 1);
	dstPts2[0] = Point2f(0, 0);
	dstPts2[1] = Point2f(w2 - 1, 0);
	dstPts2[2] = Point2f(w2 - 1, h2 - 1);
	dstPts2[3] = Point2f(0, h2 - 1);


	Mat pers = getPerspectiveTransform(corner, dstPts);//��ȯ ��� ���
	Mat pers2 = getPerspectiveTransform(corner2, dstPts2);//��ȯ ��� ���

	Mat result, result2;
	warpPerspective(img, result, pers, Size(w, h));//���� ��ȯ
	warpPerspective(img2, result2, pers2, Size(w2, h2));//���� ��ȯ


	//���� ���
	
	imshow("blr", blr);
	imshow("edge", edge);
	imshow("img_corner", img_corner);
	imshow("result", result);

	//imshow("gaus2", gaus2);
	imshow("blr2", blr2);
	imshow("edge2", edge2);
	imshow("img_corner2", img_corner2);
	imshow("result2", result2);
	waitKey();
}
