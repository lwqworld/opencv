#include "Filters.h"

cv::Mat gaussian_filter(cv::Mat img, double sigma, int kernel_size)
{
	int h = img.rows;
	int w = img.cols;
	int channel = img.channels();

	cv::Mat out = cv::Mat::zeros(h, w, CV_8UC3);

	/*###################高斯核生成####################*/
	int pad = floor(kernel_size / 2);
	int _x = 0, _y = 0;
	double kernel_sum = 0;
	//创建动态二维数组
	float** kernel = new float* [kernel_size];
	for (int i = 0; i < kernel_size; i++) {
		kernel[i] = new float[i];
	}


	for (int y = 0; y < kernel_size; y++) {
		for (int x = 0; x < kernel_size; x++) {
			_y = y - pad;
			_x = x - pad;
			kernel[y][x] = 1 / (2 * M_PI * sigma * sigma) * exp(-(_x * _x + _y * _y) / (2 * sigma * sigma));
			kernel_sum += kernel[y][x];
		}
	}
	for (int y = 0; y < kernel_size; y++) {
		for (int x = 0; x < kernel_size; x++) {
			kernel[y][x] /= kernel_sum;
		}
	}
	//输出二维数组
	std::cout << "输出二维数组: " << std::endl;
	for (int i = 0; i < kernel_size; i++) {
		for (int j = 0; j < kernel_size; j++) {
			std::cout << kernel[i][j];
		}
		std::cout << std::endl;
	}
	double v = 0;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			for (int c = 0; c < channel; c++) {

				v = 0;

				for (int dy = -pad; dy < pad + 1; dy++) {
					for (int dx = -pad; dx < pad + 1; dx++) {
						if (((x + dx) >= 0) && ((y + dy) >= 0)) {
							v += (double)img.at<cv::Vec3b>(y + dy, x + dx)[c] * kernel[dy + pad][dx + pad];
						}
					}
				}
				out.at<cv::Vec3b>(y, x)[c] = v;
			}
		}
	}
	//释放二维数组
	for (int i = 0; i < kernel_size; i++) {
		delete[]kernel[i];
	}
	delete[]kernel;
	return out;
}
