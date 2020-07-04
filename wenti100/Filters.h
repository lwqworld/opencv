#pragma once
//**********************ÂË²¨Æ÷*******************//

#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#define _USE_MATH_DEFINES 
#include<math.h>

/*
	¸ßË¹ÂË²¨
*/



cv::Mat gaussian_filter(cv::Mat img, double sigma, int kernel_size);