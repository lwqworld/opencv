#include<opencv2/opencv.hpp>
using namespace cv;
void main()
{
	Mat srcImage = imread("test_picture/test1.png");
	imshow("srcImage", srcImage);
	waitKey(0);
}