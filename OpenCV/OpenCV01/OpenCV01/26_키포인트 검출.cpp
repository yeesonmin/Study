//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void detect_keypoints();
//
//void keypoint_matching();
//void good_matching();
//void find_homography();
//
//int main(void)
//{
//	detect_keypoints();
//	keypoint_matching();
//	good_matching();
//	find_homography();
//
//	return 0;
//}
//
//void detect_keypoints()
//{
//	Mat src = imread("box_in_scene.png", IMREAD_GRAYSCALE);
//
//	if (src.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Ptr<Feature2D> feature = ORB::create();
//
//	//vector<KeyPoint> keypoints;
//	//feature->detect(src, keypoints);//키포인트 벡터 저장
//
//	//Mat desc;
//	//feature->compute(src, keypoints, desc);//키포인트 기술자 계산
//	vector<KeyPoint> keypoints;
//	Mat desc;
//	feature->detectAndCompute(src, Mat(), keypoints, desc);//한번에 함.
//
//	cout << "keypoints.size(): " << keypoints.size() << endl;
//	cout << "desc.size(): " << desc.size() << endl;
//
//	Mat dst;
//	drawKeypoints(src, keypoints, dst, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void keypoint_matching()
//{
//	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
//	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Ptr<Feature2D> feature = ORB::create();
//
//	vector<KeyPoint> keypoints1, keypoints2;
//	Mat desc1, desc2;
//	feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
//	feature->detectAndCompute(src2, Mat(), keypoints2, desc2);
//	cout << "desc1.size(): " << desc1.size() << endl;
//	cout << "desc2.size(): " << desc2.size() << endl;
//
//	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
//
//	vector<DMatch> matches;
//	matcher->match(desc1, desc2, matches);
//
//	Mat dst;
//	drawMatches(src1, keypoints1, src2, keypoints2, matches, dst);
//
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void good_matching()
//{
//	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
//	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Ptr<Feature2D> feature = ORB::create();
//
//	vector<KeyPoint> keypoints1, keypoints2;
//	Mat desc1, desc2;
//	feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
//	feature->detectAndCompute(src2, Mat(), keypoints2, desc2);
//
//	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
//
//	vector<DMatch> matches;
//	matcher->match(desc1, desc2, matches);
//
//	std::sort(matches.begin(), matches.end());//매칭값 정렬
//	vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);//50개만 추출
//
//	Mat dst;
//	drawMatches(src1, keypoints1, src2, keypoints2, good_matches, dst,
//		Scalar::all(-1), Scalar::all(-1), vector<char>(),
//		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);//매칭되지 않은 점은 표시 x
//
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}
//
//void find_homography()
//{
//	Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
//	Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty()) {
//		cerr << "Image load failed!" << endl;
//		return;
//	}
//
//	Ptr<Feature2D> feature = ORB::create();
//
//	vector<KeyPoint> keypoints1, keypoints2;
//	Mat desc1, desc2;
//	feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
//	feature->detectAndCompute(src2, Mat(), keypoints2, desc2);
//
//	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
//
//	vector<DMatch> matches;
//	matcher->match(desc1, desc2, matches);
//
//	std::sort(matches.begin(), matches.end());
//	vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);
//
//	Mat dst;
//	drawMatches(src1, keypoints1, src2, keypoints2, good_matches, dst,
//		Scalar::all(-1), Scalar::all(-1), vector<char>(),
//		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//
//	vector<Point2f> pts1, pts2;
//	for (size_t i = 0; i < good_matches.size(); i++) {
//		pts1.push_back(keypoints1[good_matches[i].queryIdx].pt);
//		pts2.push_back(keypoints2[good_matches[i].trainIdx].pt);
//	}
//
//	Mat H = findHomography(pts1, pts2, RANSAC);
//
//	vector<Point2f> corners1, corners2;
//	corners1.push_back(Point2f(0, 0));
//	corners1.push_back(Point2f(src1.cols - 1.f, 0));
//	corners1.push_back(Point2f(src1.cols - 1.f, src1.rows - 1.f));
//	corners1.push_back(Point2f(0, src1.rows - 1.f));
//	perspectiveTransform(corners1, corners2, H);//이동하는 위치 corners2에 저장
//
//	vector<Point> corners_dst;
//	for (Point2f pt : corners2) {
//		corners_dst.push_back(Point(cvRound(pt.x + src1.cols), cvRound(pt.y)));
//	}
//
//	polylines(dst, corners_dst, true, Scalar(0, 255, 0), 2, LINE_AA);
//
//	imshow("dst", dst);
//
//	waitKey();
//	destroyAllWindows();
//}