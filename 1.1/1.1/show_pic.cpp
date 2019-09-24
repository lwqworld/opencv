#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

//��������
int main()
{
	Mat srcImage, ero_Image, blur_Image;//Image
	Mat element;//ģ��
	srcImage = imread("test_picture/test1.png");
	imshow("srcImage", srcImage);
	//��ʴ����
	element = getStructuringElement(MORPH_RECT, Size(15, 15));
	erode(srcImage, ero_Image, element);//��ʴ����
	imshow("ero_Image", ero_Image);
	//�˲�����ֵ��
	blur(srcImage, blur_Image, Size(7, 7));
	imshow("blur_Image", blur_Image);
	//canny��Ե���

	waitKey(0);
}