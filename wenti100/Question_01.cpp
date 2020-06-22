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
	int pixCount[GrayScale] = { 0 };//ÿ���Ҷ�ֵ��ռ����
	double pixPro[GrayScale] = { 0 };//ÿ���Ҷ�ֵ��ռ����

	int thr = 0;//��ֵ
	int val = 0;

	//����������w0,����ƽ���Ҷ�u0
	//ǰ������w1,ǰ��ƽ���Ҷ�u1
	double w0 = 0, w1 = 0, u0 = 0, u1 = 0;
	
	double sb = 0, max_sb = 0;//����ó��ķ���ֵ

	//����ֵͳ��
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			pixCount[ gray_img.at<uchar>(y, x)]++;
				
		}
	}
	//�Ҷ�ֵ��ռ����
	for (int i = 0; i < GrayScale; i++)
	{
		pixPro[i] = pixCount[i] * 1.0 / size;
	}
	//�������лҶȼ�
	for (int t = 0; t < GrayScale; t++) {
		w0 = w1 = u0 = u1 = 0;
		for (int j = 0; j < GrayScale; j++) {
			if (j <= t)//����
			{
				//����ƽ���Ҷ�,����
				w0 += pixPro[j];
				u0 += j * pixPro[j];
			}
			else//ǰ�� 
			{
				//����ƽ���Ҷ�,����
				w1 += pixPro[j];
				u1 += j * pixPro[j];
			}
		}
		u0 = u0 / w0;
		u1 = u1 / w1;
		//��������
		sb = (double)(w0 * w1 * pow((u0 - u1), 2));
		//ǰ���뱳������Խ������Խ����
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
