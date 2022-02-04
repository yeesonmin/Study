//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
////어파인 변환
//void affine_transform();
//void affine_translation();
//void affine_shear();
//void affine_scale();
//void affine_rotation();
//void affine_flip();
//
////투시변환
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
//	//영상의 3좌표
//	srcPts[0] = Point2f(0, 0);
//	srcPts[1] = Point2f(src.cols - 1, 0);
//	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//
//	//변형할 영상의 3좌표
//	dstPts[0] = Point2f(50, 50);
//	dstPts[1] = Point2f(src.cols - 100, 100);
//	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);
//
//	//어파인 변환 행렬
//	Mat M = getAffineTransform(srcPts, dstPts);
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());//변환
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
//	//150,100만큼 이동
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
//	//전단변환 = 층밀림 변환 = 평행사변형 모양으로 변형
//
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	double mx = 0.3;
//	Mat M = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });//x값이 y값이 증가할 수록 증가함.
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
//	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);//양방향으로 4배씩 확대, INTER_NEAREST 가장 빠른 속도/나쁜화질
//	resize(src, dst2, Size(1920, 1280));//1920*1280 크기로 확대, 속도 화질 무난
//	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);//화질 좋음
//	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);//축소할 때 유용함.
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
//	Mat M = getRotationMatrix2D(cp, 20, 1);//회전 중심 좌표, 각도, 확대축소 비율
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());//변형
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
//		flip(src, dst, flipCode[i]);//양수 : 좌우 대칭, 0 : 상하 대칭, 음수 : 상하좌우 대칭
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
//				Mat pers = getPerspectiveTransform(srcPts, dstPts);//변환 행렬 얻기
//
//				Mat dst;
//				warpPerspective(src, dst, pers, Size(w, h));//투시 변환
//
//				imshow("dst", dst);
//			}
//		}
//	}
//}