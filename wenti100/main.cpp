#include"Question_01.h"
#include"Filters.h"

int  g_nValueSilder=128;//����������
cv::Mat img, gray, out;

//�������ص�����
void binarize_track(int, void*) {
	out = Binarize(gray, g_nValueSilder);
	cv::imshow("ʵ����ʾ", out);
}

int main(int argc, char* argv) {
	img = cv::imread("../test_picture/test2.png", cv::IMREAD_COLOR);
	if (!img.data) {
		return 0;
	}
	
	//cv::imshow("IMG", img);
	//�ҶȻ�
	//gray = Grayscale(img);
	////cv::imshow("gray", gray);
	//cv::namedWindow("ʵ����ʾ", 1);
	////����������
	//cv::createTrackbar("��ֵ", "ʵ����ʾ", &g_nValueSilder, 256, binarize_track);
	//binarize_track(g_nValueSilder, 0);

	
	//
	//cv::Mat  out = Otsu(gray);
	//cv::imshow("out",out);
	//cv::Mat hsv = HSVBGR(img, 0);
	//cv::imshow("HSV", hsv);
	//cv::Mat bgr = HSVBGR(hsv, 1);
	//cv::imshow("BGR", bgr);

	//cv::Mat  out = Decrease_color(img);
	//cv::imshow("out",out);

	out = gaussian_filter(img, 1.3, 3);
	cv::imshow("gaussian", out);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}