#include"Question_01.h"


cv::Mat chanel_swap(cv::Mat img, int c1, int c2)
{
	int w = img.cols;
	int h = img.rows;

	cv::Mat out = img.clone();

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			out.at<cv::Vec3b>(y, x)[c2] = img.at<cv::Vec3b>(y, x)[c1];
			out.at<cv::Vec3b>(y, x)[c1] = img.at<cv::Vec3b>(y, x)[c2];

		}
	}
	return out;
}

cv::Mat Grayscale(cv::Mat img)
{
	int w = img.cols;
	int h = img.rows;
	
	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC1);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			out.at<uchar>(y,x)= 0.2126 * (float)img.at<cv::Vec3b>(y, x)[2] \
				+ 0.7152 * (float)img.at<cv::Vec3b>(y, x)[1] \
				+ 0.0722 * (float)img.at<cv::Vec3b>(y, x)[0];
		}
	}
	return out;
}

cv::Mat Binarize(cv::Mat gray_img, int thr)
{
	int w = gray_img.cols;
	int h = gray_img.rows;

	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC1);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (gray_img.at<uchar>(y, x) > thr) {
				out.at<uchar>(y, x) = 255;
			}
			else {
				out.at<uchar>(y, x) = 0;
			}
		}
	}
	return out;
}

cv::Mat Otsu(cv::Mat gray_img)
{
	int w = gray_img.cols;
	int h = gray_img.rows;
	int size = h * w;

	int thr = 0;//阈值
	int val = 0;

	int sb = 0, max_sb = 0;//计算得出的方差值
	//前景比例w0,前景平均灰度u0
	//背景比例w1,背景平均灰度u1
	double w0 = 0, w1 = 0, u0 = 0, u1 = 0;
	for (int t = 0; t < 255; t++) {
		w0 = 0; w1 = 0;
		u0 = 0; u1 = 0;

		//像素值统计区分
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				val = gray_img.at<uchar>(y, x);
				if (val < thr) {
					w0++;
					u0 += val;//SUM
				}
				else {
					w1++;
					u1 += val;//SUM
				}
			}
		}

		//计算平均灰度,比例
		u0 /= w0;
		u1 /= w1;
		w0 /= size;
		w1 /= size;
		//
	}
	
	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC1);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {

		}
	}
	return cv::Mat();
}

cv::Mat HSVBGR(cv::Mat img, int s)
{
	int w = img.cols;
	int h = img.rows;

	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC1);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {

		}
	}
	return cv::Mat();
}
