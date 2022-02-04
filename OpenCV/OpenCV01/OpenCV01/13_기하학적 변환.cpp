//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
////������ ��ȯ
//void affine_transform();
//void affine_translation();
//void affine_shear();
//void affine_scale();
//void affine_rotation();
//void affine_flip();
//
////���ú�ȯ
//Mat src;
//Point2f srcPts[4], dstPts[4];
//
//void on_mouse(int event, int x, int y, int flags, void* userdata);
//void Runperspective();
//
//int main(void)
//{
//	//affine_transform();
//	//affine_translation();
//	//affine_shear();
//	//affine_scale();
//	//affine_rotation();
//	//affine_flip();
//	Runperspective();
//	return 0;
//}
//
//void affine_transform()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Point2f srcPts[3], dstPts[3];
//	//������ 3��ǥ
//	srcPts[0] = Point2f(0, 0);
//	srcPts[1] = Point2f(src.cols - 1, 0);
//	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//
//	//������ ������ 3��ǥ
//	dstPts[0] = Point2f(50, 50);
//	dstPts[1] = Point2f(src.cols - 100, 100);
//	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);
//
//	//������ ��ȯ ���
//	Mat M = getAffineTransform(srcPts, dstPts);
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());//��ȯ
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void affine_translation()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	//150,100��ŭ �̵�
//	Mat M = Mat_<double>({ 2, 3 },
//		{ 1, 0, 150, 
//		  0, 1, 100 
//		});
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void affine_shear()
//{
//	//���ܺ�ȯ = ���и� ��ȯ = ����纯�� ������� ����
//
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	double mx = 0.3;
//	Mat M = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });//x���� y���� ������ ���� ������.
//
//	Mat dst;
//	warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void affine_scale()
//{
//	Mat src = imread("rose.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Mat dst1, dst2, dst3, dst4;
//	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);//��������� 4�辿 Ȯ��, INTER_NEAREST ���� ���� �ӵ�/����ȭ��
//	resize(src, dst2, Size(1920, 1280));//1920*1280 ũ��� Ȯ��, �ӵ� ȭ�� ����
//	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);//ȭ�� ����
//	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);//����� �� ������.
//
//	imshow("src", src);
//	imshow("dst1", dst1(Rect(400, 500, 400, 400)));
//	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
//	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
//	imshow("dst4", dst4(Rect(400, 500, 400, 400)));
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void affine_rotation()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Point2f cp(src.cols / 2.f, src.rows / 2.f);
//	Mat M = getRotationMatrix2D(cp, 20, 1);//ȸ�� �߽� ��ǥ, ����, Ȯ����� ����
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());//����
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void affine_flip()
//{
//	Mat src = imread("eastsea.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	imshow("src", src);
//
//	Mat dst;
//	int flipCode[] = { 1, 0, -1 };
//	for (int i = 0; i < 3; i++) {
//		flip(src, dst, flipCode[i]);//��� : �¿� ��Ī, 0 : ���� ��Ī, ���� : �����¿� ��Ī
//
//		String desc = format("flipCode: %d", flipCode[i]);
//		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);
//
//		imshow("dst", dst);
//		waitKey();
//	}
//
//	destroyAllWindows();
//}
//
//void Runperspective() {
//	src = imread("card.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//	}
//
//	namedWindow("src");
//	setMouseCallback("src", on_mouse);
//
//	imshow("src", src);
//	waitKey(0);
//
//}
//void on_mouse(int event, int x, int y, int flags, void*)
//{
//	static int cnt = 0;
//
//	if (event == EVENT_LBUTTONDOWN) {
//		if (cnt < 4) {
//			srcPts[cnt++] = Point2f(x, y);
//
//			circle(src, Point(x, y), 5, Scalar(0, 0, 255), -1);
//			imshow("src", src);
//
//			if (cnt == 4) {
//				int w = 200, h = 300;
//
//				dstPts[0] = Point2f(0, 0);
//				dstPts[1] = Point2f(w - 1, 0);
//				dstPts[2] = Point2f(w - 1, h - 1);
//				dstPts[3] = Point2f(0, h - 1);
//
//				Mat pers = getPerspectiveTransform(srcPts, dstPts);//��ȯ ��� ���
//
//				Mat dst;
//				warpPerspective(src, dst, pers, Size(w, h));//���� ��ȯ
//
//				imshow("dst", dst);
//			}
//		}
//	}
//}