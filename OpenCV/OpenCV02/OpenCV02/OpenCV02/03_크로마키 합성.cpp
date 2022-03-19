//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//
//void main() {
//	//초록색 배경
//	VideoCapture cap1("..\\..\\videos\\woman.mp4");
//
//	//합성할 영상
//	VideoCapture cap2("..\\..\\videos\\raining.mp4");
//
//	double fps = cap1.get(CAP_PROP_FPS);
//	int delay = cvRound(1000 / fps);//각 프레임마다 딜레이 5ms 추가
//
//	Mat frame1, frame2, mask, frame1HSV;
//	while (true)
//	{
//		cap1 >> frame1;
//
//		//색 변환
//		cvtColor(frame1, frame1HSV, COLOR_BGR2HSV);
//
//		//마스크 제작(초록색 부분을 제외한 영역 제거)
//		inRange(frame1HSV, Scalar(50, 150, 0), Scalar(80, 255, 255),mask);
//
//		//합성
//		cap2 >> frame2;
//		copyTo(frame2, frame1, mask);
//
//		imshow("result", frame1);
//
//		if (waitKey(delay) == 27)
//			break;
//
//	}
//}