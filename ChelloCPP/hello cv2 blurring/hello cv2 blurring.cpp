// hello cv2 blurring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	Mat image = imread("f:/computer vision course/masteropencv/images/elephant.jpg");
	Mat blurred;
	Mat blurred2;
	Mat blurred3;
	Mat bilatteral;
	Mat bilatteral2;
	Mat denoised;
	Mat kernel = Mat(7,7, CV_32F, Scalar(1.0 / 49));
	filter2D(image, blurred,-1,kernel);
	imshow("original", image);
	imshow("blurred", blurred);

	blur(image, blurred2, Size(7,7));
	imshow("blur function", blurred2);
	GaussianBlur(image, blurred3, Size(7,7),0);
	imshow("gausian", blurred3);

	bilatteral = image.clone();
	for (int i=0;i<20;i++)
	{
		bilateralFilter(bilatteral, bilatteral2, 9, 50, 50);
		bilatteral = bilatteral2.clone();
	}
	

	imshow("bilateral2", bilatteral2);
	fastNlMeansDenoisingColored(image, denoised);
	imshow("denoised", denoised);
	waitKey();
	destroyAllWindows();
	return 0;
}

