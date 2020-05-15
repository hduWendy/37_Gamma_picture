// 37_Gamma_picture.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ͼƬ����gamma����������ʾ������
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/��ͼͼƬ/gtest.jpg");

	uint8_t b[256] = { 0 };
	for (int t = 255; t > 0; t--)
	{
		float t_0_1 = t / 255.0;
		b[t] = (uint8_t)255 * pow(t_0_1, 0.5);
	}

	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			for (int n = 0; n < 3; n++)
			{
				uint8_t p = srcMat.at<Vec3b>(j, i)[n];
				srcMat.at<Vec3b>(j, i)[n] = b[p];
			}

			//-------------�������ش���------------------------
		} //���д������
	}
	imshow("src", srcMat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
