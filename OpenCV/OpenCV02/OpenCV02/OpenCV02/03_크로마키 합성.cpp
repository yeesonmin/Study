//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//
//void main() {
//	//�ʷϻ� ���
//	VideoCapture cap1("..\\..\\videos\\woman.mp4");
//
//	//�ռ��� ����
//	VideoCapture cap2("..\\..\\videos\\raining.mp4");
//
//	double fps = cap1.get(CAP_PROP_FPS);
//	int delay = cvRound(1000 / fps);//�� �����Ӹ��� ������ 5ms �߰�
//
//	Mat frame1, frame2, mask, frame1HSV;
//	while (true)
//	{
//		cap1 >> frame1;
//
//		//�� ��ȯ
//		cvtColor(frame1, frame1HSV, COLOR_BGR2HSV);
//
//		//����ũ ����(�ʷϻ� �κ��� ������ ���� ����)
//		inRange(frame1HSV, Scalar(50, 150, 0), Scalar(80, 255, 255),mask);
//
//		//�ռ�
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