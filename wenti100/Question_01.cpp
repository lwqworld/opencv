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
			/*else {
				out.at<uchar>(y, x) = 0;
			}*/
		}
	}
	return out;
}

cv::Mat Otsu(cv::Mat gray_img)
{
	int w = gray_img.cols;
	int h = gray_img.rows;
	int size = h * w;

	const int GrayScale = 256;
	int pixCount[GrayScale] = { 0 };//每个灰度值所占个数
	double pixPro[GrayScale] = { 0 };//每个灰度值所占比例

	int thr = 0;//阈值
	int val = 0;

	//背景景比例w0,背景平均灰度u0
	//前景比例w1,前景平均灰度u1
	double w0 = 0, w1 = 0, u0 = 0, u1 = 0;
	
	double sb = 0, max_sb = 0;//计算得出的方差值

	//像素值统计
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			pixCount[ gray_img.at<uchar>(y, x)]++;
				
		}
	}
	//灰度值所占比例
	for (int i = 0; i < GrayScale; i++)
	{
		pixPro[i] = pixCount[i] * 1.0 / size;
	}
	//遍历所有灰度级
	for (int t = 0; t < GrayScale; t++) {
		w0 = w1 = u0 = u1 = 0;
		for (int j = 0; j < GrayScale; j++) {
			if (j <= t)//背景
			{
				//计算平均灰度,比例
				w0 += pixPro[j];
				u0 += j * pixPro[j];
			}
			else//前景 
			{
				//计算平均灰度,比例
				w1 += pixPro[j];
				u1 += j * pixPro[j];
			}
		}
		u0 = u0 / w0;
		u1 = u1 / w1;
		//方差评估
		sb = (double)(w0 * w1 * pow((u0 - u1), 2));
		//前景与背景方差越大区分越明显
		if (sb > max_sb) {
			max_sb = sb;
			thr = t;
		}

	}
		
	
	std::cout << "Optimal threshold:" << thr << std::endl;

	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC1);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (gray_img.at<uchar>(y, x) > thr) {
				out.at<uchar>(y, x) = 255;
			}
			/*else {
				out.at<uchar>(y, x) = 0;
			}*/
		}
	}
	return out;
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
