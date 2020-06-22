#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<iostream>
/*
	���ܣ�ͨ��ת��
	���룺img��ɫͼ��c1��c2ת����ͨ������
	�����outת����ͼƬ��
*/
cv::Mat chanel_swap(cv::Mat img, int c1, int c2);
/*
	���ܣ��ҶȻ�
	���룺img��ɫͼ��
	�����outת����ͼƬ��
*/
cv::Mat  Grayscale(cv::Mat img);
/*
	���ܣ���ֵ��
	���룺gray_img�Ҷ�ͼ��
	�����outת����ͼƬ��
*/
cv::Mat Thresholding(cv::Mat gray_img, int thr);
/*
	���ܣ�����ֵ��
	���룺gray_img�Ҷ�ͼ��
	�����outת����ͼƬ��
*/
cv::Mat Otsu(cv::Mat gray_img);
/*
	���ܣ�HSV�任
	���룺img��ɫͼ��HSV/BGRת����ʽ
	�����outת����ͼƬ��
*/
cv::Mat HSVBGR(cv::Mat img, int s);
