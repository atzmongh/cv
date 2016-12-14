// hello cv2 draw lines.cpp : Defines the entry point for the console application.
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
	Scalar initValue = Scalar(0,0,0, 0);
	Mat canvass = Mat(500, 500, CV_8UC3,initValue);
	imshow("black", canvass);
	line(canvass, Point(10, 10), Point(50, 50), Scalar(120, 45, 50), 5);
	circle(canvass, Point(120, 120), 100, Scalar(200, 0, 0), 3);
	rectangle(canvass, Rect(300, 300, 40, 50), Scalar(250, 0, 0), 6);
	Point * pointAr1 = new Point[3]{ Point(10,10),Point(100,100),Point(100,150) };
	Point * pointAr2 = new Point[4]{ Point(200,200),Point(250,150),Point(300,300),Point(400,400) };
	Point ** pointArP = new Point*[2]{ pointAr1, pointAr2 };


	int poligonSizeA[2] = { 3,4 };

	polylines(canvass, pointArP, poligonSizeA, 2, false, Scalar(250, 100, 100));
	putText(canvass, "hello open cv", Point(0, 250), 2, 2.0, Scalar(150, 150, 150), 1);
	imshow("black", canvass);
	waitKey();
	destroyAllWindows();
	



	return 0;
}

