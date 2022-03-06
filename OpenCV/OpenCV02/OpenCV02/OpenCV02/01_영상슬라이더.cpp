#include<opencv2/opencv.hpp>

#include <iostream>
#include <io.h>
#include <string>

using namespace std;
using namespace cv;


void main() {
	//여러 이미지 읽기
	vector<string> files;
	vector<Mat> imgs;

	string path = "..\\..\\imgs\\*.*";

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
		string tpath = "..\\..\\imgs\\" + files[i];
		imgs.push_back(imread(tpath));
	}
	

	
	//이미지 출력
	namedWindow("img slider");
	int imgcnt = imgs.size()-1;
	int imgindex = 0;
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
				imgindex++;
			}
			
		}
		else if (key == 0x250000) {
			//<-

			if (imgindex -1 == -1) {
				imgindex = imgcnt;
			}
			else
			{
				imgindex--;
			}
			
		}
		else if (key == 27) {
			break;
		}

		imshow("img slider", imgs[imgindex]);
		
	}

	destroyWindow("img slider");
	
	
}

