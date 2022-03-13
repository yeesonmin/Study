//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//
//void main() {
//	//두 영상준비(프레임이 같음)
//	VideoCapture cap1("..\\..\\videos\\video1.mp4");
//	VideoCapture cap2("..\\..\\videos\\video2.mp4");
//
//	Mat frame;
//
//	double fps = cap1.get(CAP_PROP_FPS);
//	int framecnt = cap1.get(CAP_PROP_FRAME_COUNT);
//	int delay = cvRound(1000 / fps);//각 프레임마다 딜레이 5ms 추가
//	int cnt = 0;
//
//	int width = cvRound(cap1.get(CAP_PROP_FRAME_WIDTH));
//	int height = cvRound(cap1.get(CAP_PROP_FRAME_HEIGHT));
//
//
//	//출력
//	while (true)
//	{
//		if (cnt < framecnt)
//		{
//			cap1 >> frame;
//
//			//영상 겹치기
//			//10프레임 전에 겹치기 시작
//			if (cnt  > framecnt - 10 && cnt < framecnt) {
//
//				Mat tempFrame(Size(width, height),CV_8UC3);
//				frame.colRange(0, cvRound(width * (framecnt - cnt)/10)).copyTo(tempFrame.colRange(0, cvRound(width * (framecnt - cnt) / 10)));
//				
//				cap2 >> frame;
//				frame.colRange(cvRound(width * (framecnt - cnt) / 10), width).copyTo(tempFrame.colRange(cvRound(width * (framecnt - cnt) / 10), width));
//
//				tempFrame.copyTo(frame);
//
//			}
//
//
//			if (frame.empty())
//				break;
//		}
//		else
//		{
//			cap2 >> frame;
//			if (frame.empty())
//				break;
//		}
//		
//		
//
//		imshow("frame", frame);
//
//		if (waitKey(delay) == 27)
//			break;
//
//		cnt++;
//	}
//}