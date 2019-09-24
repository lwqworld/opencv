#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

//»ù´¡²âÊÔ
int main()
{
	Mat srcImage, ero_Image, blur_Image;//Image
	Mat element;//Ä£°å
	srcImage = imread("test_picture/test1.png");
	imshow("srcImage", srcImage);
	//¸¯Ê´²Ù×÷
	element = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(srcImage, ero_Image, element);//¸¯Ê´º¯Êý
	imshow("ero_Image", ero_Image);
	//ÂË²¨£¨¾ùÖµ£©
	blur(srcImage, blur_Image, Size(7, 7));
	imshow("blur_Image", blur_Image);
	//canny±ßÔµ¼ì²â

	waitKey(0);
}