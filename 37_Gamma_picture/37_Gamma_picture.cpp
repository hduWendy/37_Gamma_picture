// 37_Gamma_picture.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片，将图片进行gamma矫正，并显示出来！
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/数图图片/gtest.jpg");

	uint8_t b[256] = { 0 };
	for (int t = 255; t > 0; t--)
	{
		float t_0_1 = t / 255.0;
		b[t] = (uint8_t)255 * pow(t_0_1, 0.5);
	}

	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------开始处理每个像素-----------------
			for (int n = 0; n < 3; n++)
			{
				uint8_t p = srcMat.at<Vec3b>(j, i)[n];
				srcMat.at<Vec3b>(j, i)[n] = b[p];
			}

			//-------------结束像素处理------------------------
		} //单行处理结束
	}
	imshow("src", srcMat);
	//等待用户按键
	waitKey(0);
	return 0;
}
