#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

#include<math.h>
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
cv::Mat Binarize(cv::Mat gray_img, int thr);
/*
	���ܣ�����ֵ��
	���룺gray_img�Ҷ�ͼ��
	�����outת����ͼƬ��
*/
cv::Mat Otsu(cv::Mat gray_img);
/*
	���ܣ�HSV�任
	R,G,B from 0-255, H from 0-360, S,V from 0-100
	���룺img��ɫͼ��hsv:(0/1)(HSV/BGR)ת����ʽ
	�����outת����ͼƬ��
*/
cv::Mat HSVBGR(cv::Mat img, int hsv);
/*
	���ܣ���ɫ����

	���룺img��ɫͼ��
	�����outת����ͼƬ��
*/
cv::Mat Decrease_color(cv::Mat img);
/*
	���ܣ��ػ�
	���룺img��ɫͼ��pool:(Average/Max)�ػ���ʽ
	�����outת����ͼƬ��
*/
cv::Mat Pooling(cv::Mat img,int pool=0);
