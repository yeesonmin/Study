#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Release로 실행해야 빠름
int main()
{
	VideoCapture cap("vtest.avi");

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return -1;
	}

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());//SVM 머신러닝 사용해서 사람 검출

	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		vector<Rect> detected;
		hog.detectMultiScale(frame, detected);//사람 검출하면 저장

		for (Rect r : detected) {
			Scalar c = Scalar(rand() % 256, rand() % 256, rand() % 256);
			rectangle(frame, r, c, 3);//표시
		}

		imshow("frame", frame);

		if (waitKey(10) == 27)
			break;
	}

	return 0;
}
