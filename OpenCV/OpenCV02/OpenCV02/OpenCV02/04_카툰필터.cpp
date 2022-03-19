#include<opencv2/opencv.hpp>

using namespace cv;

Mat cartoonfilter(Mat ori);
Mat sketchfilter(Mat ori);
void main() {
	VideoCapture cap(0);
	Mat img, cartoon, sketch, blr;

	while (true)
	{
		cap >> img;
		bilateralFilter(img, blr, -1, 10, 5);

		cartoon = cartoonfilter(blr);
		sketch = sketchfilter(blr);
		imshow("cartoon", cartoon);
		imshow("sketch", sketch);
		waitKey(1);
	}
	
}

Mat cartoonfilter(Mat ori)
{
	Mat blr, edge, result;
	Size oriSize(ori.size().width, ori.size().height);

	resize(ori,ori, Size(oriSize.width / 2, oriSize.height/2));//속도를 위해 크기 줄임
	bilateralFilter(ori, blr, -1, 20, 7);
	
	Canny(ori, edge,120,140);
	bitwise_not(edge, edge);

	cvtColor(edge, edge, COLOR_GRAY2BGR);

	bitwise_and(blr, edge, result);
	resize(result, result, Size(oriSize.width, oriSize.height),INTER_NEAREST);//원래 크리고 복구하되 카툰 필터 효과를 더 주기 위해 INTER_NEAREST 설정
	return result;
}

Mat sketchfilter(Mat ori)
{
	Mat gray, gaus, result, blrresult;
	cvtColor(ori, gray, COLOR_BGR2GRAY);

	GaussianBlur(gray, gaus, Size(), 3);

	divide(gray, gaus, result, 255);

	medianBlur(result, blrresult, 3);
	//bilateralFilter(result, blrresult, -1, 20, 9);

	cvtColor(blrresult, blrresult, COLOR_GRAY2BGR);
	return blrresult;
}
