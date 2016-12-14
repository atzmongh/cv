// hello cv2 rotations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat image = imread("f:/computer vision course/masteropencv/images/elephant.jpg");
	Mat rotatedImage;
	int rows = image.rows;
	int columns = image.cols;
	
	Point2f center = Point(rows / 2, columns / 2);
	for (size_t i = 0; i < 90 ; i++)
	{
		Mat rotationMat = getRotationMatrix2D(center, i, 1);
		warpAffine(image, rotatedImage, rotationMat, Size(rows, columns));
		imshow("rotated", rotatedImage);
		waitKey(20);
	}
	
	waitKey();
	destroyAllWindows();


	return 0;
}

