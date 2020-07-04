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
			out.at<uchar>(y, x) = 0.2126 * (float)img.at<cv::Vec3b>(y, x)[2] \
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
			pixCount[gray_img.at<uchar>(y, x)]++;

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

cv::Mat HSVBGR(cv::Mat img, int hsv)
{

	int W = img.cols;
	int H = img.rows;
	float r, g, b;
	float h, s, v;
	float max, min;
	cv::Mat out;
	
	switch (hsv) {
	case 0://BGR=>HSV
		
		out= cv::Mat::zeros(H, W, CV_32FC3);
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {

				r = (float)img.at<cv::Vec3b>(y, x)[2] / 255;
				g = (float)img.at<cv::Vec3b>(y, x)[1] / 255;
				b = (float)img.at<cv::Vec3b>(y, x)[0] / 255;

				max = fmax(r, fmax(g, b));
				min = fmin(r, fmin(g, b));
				float temp = max - min;//max-min
				//V
				v = max;
				//S
				if (max != 0) {
					s = temp / max;
				}
				else {
					s = 0;
				}
				//H
				if (v == r && g >= b) {
					h = 60 * (g - b) / temp;
				}
				else if (v == r && g < b) {
					h = 60 * (g - b) / temp + 360;
				}
				else if (v == g) {
					h = 120 + 60 * (b - r) / temp;
				}
				else if(v==b) {
					h = 240 + 60 * (r - g) / temp;
				}
				out.at<cv::Vec3f>(y, x)[0] = h;
				out.at<cv::Vec3f>(y, x)[1] = s;
				out.at<cv::Vec3f>(y, x)[2] = v;
				
			}
		}
		break;
	case 1://HSV=>BGR
		out = cv::Mat::zeros(H, W, CV_8UC3);
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				v = (float)img.at<cv::Vec3f>(y, x)[2];
				s = (float)img.at<cv::Vec3f>(y, x)[1];
				h = (float)img.at<cv::Vec3f>(y, x)[0];

				float rgb_max = v * 255.0f;
				float rgb_min = rgb_max * (1 - s) / 1.0f;

				int t = h / 60;
				int difs = fmod(h ,60);
				float rgb_Adj = (rgb_max - rgb_min) * difs / 60.0f;
				r = g = b = rgb_max;
				switch(t) {
				case 0:
					g = rgb_min + rgb_Adj;
					b = rgb_min;
					break;
				case 1:
					r = rgb_max - rgb_Adj;
					b = rgb_min;
					break;
				case 2:
					r = rgb_min;
					b = rgb_min + rgb_Adj;
					break;
				case 3:
					r = rgb_min;
					b = rgb_max - rgb_Adj;
					break;
				case 4:
					r= rgb_min + rgb_Adj;
					g = rgb_min;
					break;
				default :
					g = rgb_min;
					b = rgb_max + rgb_Adj;
					break;

				}
				out.at<cv::Vec3b>(y, x)[0] = b;
				out.at<cv::Vec3b>(y, x)[1] = g;
				out.at<cv::Vec3b>(y, x)[2] = r;
			}
		}
		break;
	}

	return out;
}

cv::Mat Decrease_color(cv::Mat img)
{
	int w = img.cols;
	int h = img.rows;
	int channel = img.channels();
	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC3);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			for (int c = 0; c < channel; c++) {
				out.at<cv::Vec3b>(y, x)[c] = (uchar)(floor( \
					(double)img.at<cv::Vec3b>(y, x)[c] / 64) * 64 + 32);
			}
		}
	}
	return out;
}

cv::Mat Pooling(cv::Mat img, int pool)
{
	int h = img.rows;
	int w = img.cols;
	int channel = img.channels();

	int r = 4;//pool 核大小(r*r)
	double val = 0;
	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC3);

	if (pool == 0) {
		for (int y = 0; y < h; y+= r) {
			for (int x = 0; x < w; x+= r) {
				for (int c = 0; c < channel; c++) {
					val = 0;
					for (int y_ = 0; y_ < r; y_++) {
						for (int x_ = 0; x_ < r; x_++) {
							val += (double)img.at<cv::Vec3b>(y + y_, x + x_)[c];

						}
					}
					val /= (r * r);
					for (int y_ = 0; y_ < r; y_++) {
						for (int x_ = 0; x_ < r; x_++) {
							out.at<cv::Vec3b>(y + y_, x + x_)[c] = (uchar)val;

						}
					}
				}
			}
		}

	}
	else if(pool=1){
		for (int y = 0; y < h; y += r) {
			for (int x = 0; x < w; x += r) {
				for (int c = 0; c < channel; c++) {
					val = 0;
					for (int y_ = 0; y_ < r; y_++) {
						for (int x_ = 0; x_ < r; x_++) {
							val = fmax(img.at<cv::Vec3b>(y + y_, x + x_)[c], val);

						}
					}
					val /= (r * r);
					for (int y_ = 0; y_ < r; y_++) {
						for (int x_ = 0; x_ < r; x_++) {
							out.at<cv::Vec3b>(y + y_, x + x_)[c] = (uchar)val;

						}
					}
				}
			}
		}

	}
	return out;
}
