// hello cv2 sharpening.cpp : Defines the entry point for the console application.
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
	Mat image = imread("F:\\computer vision course\\MasterOpenCV\\images\\elephant.jpg");
	Mat sharpened;
	
	float kernelArray[9]{  -1,-2,-1,-1,14,-1,-1,-2,-1};

	Mat kernel = Mat(3, 3, CV_32F, kernelArray);
	cout << kernel << endl;

	if (image.empty()) {
		cout << "could not load image file";
	}
	else {
		filter2D(image, sharpened, -1, kernel);
		imshow("original", image);
		imshow("sharpened", sharpened);
		waitKey();
		destroyAllWindows();
	}
	return 0;
}

