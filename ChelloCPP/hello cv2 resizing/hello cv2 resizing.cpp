// hello cv2 resizing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace cv;

void change_size();
void resample();
void downSampleSimple(int);
void downSamplingByAverage(int downSampleRate);



int main()
{
	
	
	
	//change_size();
	resample();
	downSampleSimple(6);
	downSamplingByAverage(6);
	waitKey();
	destroyAllWindows();
	return 0;
}

void change_size()
{
	Mat image = imread("f:/computer vision course/masteropencv/images/elephant.jpg");

	
	Mat resized_image;

	
	for (int i = 100; i > 0; i--) {
		resize(image, resized_image, Size(), (i) / 100.0, (i) / 100.0);
		int rows = resized_image.rows;
		int columns = resized_image.cols;

		Point2f center = Point(rows / 2, columns / 2);
		Mat rotationMat = getRotationMatrix2D(center, (100 - i) * 2, 1);
		Mat rotated_image;
		warpAffine(resized_image, rotated_image, rotationMat, Size(rows, columns));
		imshow("resized", rotated_image);
		waitKey(30);
	}


	waitKey();
	destroyAllWindows();
}

