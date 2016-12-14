// hello CV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2\imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;


int main()
{
	
	cout << "shalom"<<endl;
	cv::Mat image;
	
	image = cv::imread("F:\\computer vision course\\MasterOpenCV\\images\\bottlecaps.jpg");
	if (image.empty())
	{
		cout << "could not open image"<<endl;
	}
	else
	{
		cout << "loaded successfully"<<endl;
		//cv::imshow("this is text from cv2",image);
		//cv::namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
		//cv::imshow("MyWindow", image); //display the image which is stored in the 'img' in the "MyWindow" window

		//cv::waitKey(0); //wait infinite time for a keypress
		//change to gray scale
		Mat gray;
		cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		Mat HSV;
		cv::cvtColor(image, HSV, cv::COLOR_BGR2HSV);
		cv::imshow("gray scale", gray);
		cv::imshow("HSV", HSV);
		cv::waitKey(0); //wait infinite time for a keypress
		cv::destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
	}
	cout << "image dimensions" << image.dims<<endl;
	cout <<"rows:"<<image.rows<< " cols:" << image.cols<<endl;
	Range ranges[] = { Range(100,200),Range(100,200) };
	cout<<"mat size:"<<image.size();
	Mat cropped = image(ranges);
	cout <<"range 0 to 2"<< cropped.size()<<endl;
	Mat oneColor(100, 100, CV_8UC1);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			uchar element = cropped.at<uchar>(i, j*3 + 2);
			oneColor.at<uchar>(i, j) = element;
		}
	}
	imshow("full cllor", cropped);
	imshow("one element picture", oneColor);
	waitKey();
//	cv::imshow("cropped image", cropped);
//	cv::imwrite("images\\cropped.jpg", cropped);
	//cv::waitKey();
	cout << cropped<<endl;
	cout << "first elemenet:"<<(int)cropped.at<uchar>(0,0)<<endl;
	cout << "first elemenet:" << (int)cropped.at<uchar>(0, 1) << endl;
	cout << "first elemenet:" << (int)cropped.at<uchar>(4, 14) << endl;
	cout << "channels:" << cropped.channels()<< " elem size:"<<cropped.elemSize() <<"elem channel size:"<<cropped.elemSize1()<< endl;
	cout << "type:" << cropped.type()<<" this is:"<<CV_8UC3<<endl;
	cv::destroyAllWindows();
	

	cout << "ending program"<<endl;
	return 0;
}

