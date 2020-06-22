#include"Question_01.h"
#include<Windows.h>


int main(int argc, char* argv) {
	cv::Mat img = cv::imread("../test_picture/test3.jpg", cv::IMREAD_COLOR);
	cv::Mat gray = Grayscale(img);
	cv::imshow("gray", gray);
	
	cv::Mat  out = Otsu(gray);
	cv::imshow("out",out);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}