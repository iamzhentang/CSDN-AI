// homework1_further.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
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
    Mat image = imread("F:/codecs/CSDN-AI/分离HSI/homework1_further/Lenna.png");
	Mat hsv, BGRChannel[3], hsvChannel[3];
	
	//show the source image
	imshow("source image", image);
	//TODO split BRG
	split(image, BGRChannel);
	imshow("Blue", (BGRChannel[0], 0, 0));
	imshow("Green", (0, BGRChannel[1], 0));
	imshow("Red", (0, 0, BGRChannel[2]));

	waitKey();
	//TODO split hsv
	cvtColor(image, hsv, COLOR_BGR2HSV);
	split(hsv, hsvChannel);
	imshow("Hue", hsvChannel[0]);
	imshow("Saturation", hsvChannel[1]);
	imshow("Value", hsvChannel[2]);
	waitKey();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
