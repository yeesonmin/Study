#include<opencv2/opencv.hpp>

#include <iostream>
#include <io.h>
#include <string>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void*);
Point ptOld;
bool drawing = false;
Mat img, oriimg;
Mat saveimg;

int imgindex = 0;
int minW = 999999999, minH = 999999999, maxW = 0, maxH = 0;

void main() {
	//여러 이미지 읽기
	vector<string> files;
	vector<Mat> imgs;

	//string path = "..\\..\\imgs\\*.*";
	//string path = "C:\\Users\\yeeso\\Desktop\\인공지능 실습\\자료\\데이터\\bmp_원본이미지\\*.*";
	//string path = "C:\\Users\\yeeso\\Desktop\\인공지능 실습\\데이터\\*.*";
	string path = "C:\\Users\\yeeso\\Desktop\\AI\\데이터\\test\\nomask\\*.*";

	struct _finddata_t fd;
	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
		cout << "No file in directory!" << endl;
	do
	{
		cout << fd.name << endl;
		files.push_back(fd.name);

	} while (_findnext(handle, &fd) == 0);
	_findclose(handle);
	
	for (size_t i = 2; i < files.size(); i++)
	{
		string tpath = "C:\\Users\\yeeso\\Desktop\\AI\\데이터\\test\\nomask\\" + files[i];
		imgs.push_back(imread(tpath));
	}
	

	
	//이미지 출력
	int imgcnt = imgs.size()-1;
	
	/*for (size_t i = 0; i < imgcnt; i++)
	{
		if (imgs[i].cols > maxW) {
			maxW = imgs[i].cols;
		}
		if (imgs[i].cols < minW) {
			minW = imgs[i].cols;
		}

		if (imgs[i].rows > maxH) {
			maxH = imgs[i].rows;
		}
		if (imgs[i].rows < minH) {
			minH = imgs[i].rows;
		}
	}
	cout << "Max W : " << maxW << " Min W : " << minW << " Max H : " << maxH << " Min H : " << minH << "\n";*/
	string title;
	title = to_string(imgindex + 1);
	imgs[imgindex].copyTo(img);
	imgs[imgindex].copyTo(oriimg);
	imshow(title, img);
	moveWindow(title, 800, 30);
	while (true)
	{
		

		//키보드 방향키로 이미지 전환
		int key = waitKeyEx(10);
		if (key == 0x270000) {
			//->
			if (imgindex + 1 == imgcnt+1) {
				imgindex = 0;
			}
			else
			{
				destroyAllWindows();
				imgindex++;
				title = to_string(imgindex + 1);
				imgs[imgindex].copyTo(img);
				imgs[imgindex].copyTo(oriimg);
				imshow(title, img);
				moveWindow(title, 800, 30);
			}
			
		}
		else if (key == 0x250000) {
			//<-
			if (imgindex -1 == -1) {
				imgindex = imgcnt;
			}
			else
			{
				destroyAllWindows();
				imgindex--;
				title = to_string(imgindex + 1);
				imgs[imgindex].copyTo(img);
				imgs[imgindex].copyTo(oriimg);
				imshow(title, img);
				moveWindow(title, 800, 30);
			}
			
		}
		else if (key == 27) {
			break;
		}
		
		imshow(title, img);
		setMouseCallback(title, on_mouse);
	}

	destroyAllWindows();
	
	
}

void on_mouse(int event, int x, int y, int flags, void*)
{
    switch (event) {
    case EVENT_LBUTTONDOWN:
        ptOld = Point(x, y);
        //cout << "old x : "  << ptOld.x <<"| x :" << x << "| old y : " << ptOld.y << "| y : "<< y<<"\n";
        drawing = true;
        break;
    case EVENT_LBUTTONUP:
        drawing = false;
        if (ptOld.x < x && ptOld.y < y) {
            rectangle(img, ptOld, Point(x, y), Scalar(255, 0, 0), 2);
			oriimg(Rect(ptOld, Point(x, y))).copyTo(saveimg);

			String path = format("C:/Users/yeeso/Desktop/AI/데이터/test/nomask2/%d.jpg", imgindex + 1);
			imwrite(path, saveimg);

			if (saveimg.cols > maxW) {
				maxW = saveimg.cols;
			}
			if (saveimg.cols < minW) {
				minW = saveimg.cols;
			}

			if (saveimg.rows > maxH) {
				maxH = saveimg.rows;
			}
			if (saveimg.rows < minH) {
				minH = saveimg.rows;
			}

			//imshow("saveimg", saveimg);
            //cout << "old x : " << ptOld.x << "| x :" << x << "| old y : " << ptOld.y << "| y : " << y << "\n";
			cout << "SAVE "<< imgindex +1 << "| Max W : " << maxW << " Min W : "<< minW << " Max H : " << maxH << " Min H : "<< minH << "\n";
        }
       
        break;
    case EVENT_MOUSEMOVE:
        if (drawing) {
			oriimg.copyTo(img);
            rectangle(img, ptOld, Point(x, y), Scalar(255, 0, 0), 2);
            //cout << "old x : " << ptOld.x << "| x :" << x << "| old y : " << ptOld.y << "| y : " << y << "\n";
        }
        break;
    default:
        break;
    }
}

