#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	string title;
	vector<Mat> imgs;
	for (int i = 0; i < 3; i++) {
		title += "img";
		title += to_string(i + 1);
		title += ".jpg";
		Mat img = imread(title);

		if (img.empty()) {
			cerr << "Image load failed!" << endl;
			return -1;
		}

		imgs.push_back(img);

		title.clear();
	}

	Ptr<Stitcher> stitcher = Stitcher::create();

	Mat dst;
	Stitcher::Status status = stitcher->stitch(imgs, dst);

	if (status != Stitcher::Status::OK) {
		cerr << "Error on stitching!" << endl;
		return -1;
	}

	imwrite("result.jpg", dst);

	imshow("dst", dst);

	waitKey();
	return 0;
}