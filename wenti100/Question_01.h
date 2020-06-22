#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<iostream>
/*
	功能：通道转换
	输入：img彩色图像；c1，c2转换的通道名；
	输出：out转换后图片；
*/
cv::Mat chanel_swap(cv::Mat img, int c1, int c2);
/*
	功能：灰度化
	输入：img彩色图像；
	输出：out转换后图片；
*/
cv::Mat  Grayscale(cv::Mat img);
/*
	功能：二值化
	输入：gray_img灰度图像；
	输出：out转换后图片；
*/
cv::Mat Binarize(cv::Mat gray_img, int thr);
/*
	功能：大津二值化
	输入：gray_img灰度图像；
	输出：out转换后图片；
*/
cv::Mat Otsu(cv::Mat gray_img);
/*
	功能：HSV变换
	输入：img彩色图像；HSV/BGR转换格式
	输出：out转换后图片；
*/
cv::Mat HSVBGR(cv::Mat img, int s);
