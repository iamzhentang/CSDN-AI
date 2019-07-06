#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include"opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include"opencv2/xfeatures2d.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img_1 = imread("F:/codecs/small.jpg", CV_LOAD_IMAGE_COLOR);
	Mat img_2 = imread("F:/codecs/large.jpg", CV_LOAD_IMAGE_COLOR);
	Ptr<Feature2D> sift = xfeatures2d::SIFT::create();
	vector<KeyPoint> keypoints_1, keypoints_2;
	Mat descriptors_1, descriptors_2;


	sift->detectAndCompute(img_1, noArray(), keypoints_1, descriptors_1);
	sift->detectAndCompute(img_2, noArray(), keypoints_2, descriptors_2);
	//绘制特征点(关键点)
	drawKeypoints(img_1, keypoints_1, descriptors_1, Scalar(0, 0,
		255));
	drawKeypoints(img_2, keypoints_2, descriptors_2, Scalar::all
	(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	imshow("img_1", descriptors_1);
	imshow("img_2", descriptors_2);
	waitKey(0);
	return 0;
}
