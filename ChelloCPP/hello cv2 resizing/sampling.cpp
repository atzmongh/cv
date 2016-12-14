#include "stdafx.h"

using namespace std;
using namespace cv;

Vec3b calculatePixel(const Mat& image, int i, int j, int downSampleRate);
void resample()
{
	Mat image = cv::imread("f:/computer vision course/masteropencv/images/elephant.jpg");
	imshow("original", image);
	Mat down;
	int rows = image.rows;
	int cols = image.cols;

	pyrDown(image, down, Size((cols+1)/2,(rows+1)/2));
	imshow("half size", down);
	/*Mat up;
	pyrUp(down, up, Size());
	imshow("back original", up);*/

	
	return;
}


void downSampleSimple(int downSampleRate)
{
	Mat image = imread("f:/computer vision course/masteropencv/images/elephant.jpg");
	int rows = image.rows;
	int columns = image.cols;
	

	
	int downSampledRows = (rows + downSampleRate-1) / downSampleRate;
	int downSampledCols = (columns + downSampleRate - 1) / downSampleRate;

	Mat downSampled = Mat(downSampledRows, downSampledCols, CV_8UC3);

	Mat_<Vec3b> _image = image;
	Mat_<Vec3b> _downSampled = downSampled;

	for (int i = 0, downI=0; i < rows; i+= downSampleRate,downI++)
	{
		for (int j = 0, downJ=0; j < columns; j += downSampleRate,downJ++)
		{
			_downSampled(downI,downJ) = _image(i, j);
		}
	}

	imshow("simple half size", _downSampled);
}

/**
 * \brief the function downsamples an image by averaging the pixels that are in the nXn neighbourhood.
 * \param downSampleRate e.g.: a rate of 2 means that we wish to take half the rows and half the columns
 */
void downSamplingByAverage(int downSampleRate)
{
	Mat image = imread("f:/computer vision course/masteropencv/images/elephant.jpg");
	int rows = image.rows;
	int columns = image.cols;
	

	
	int downSampledRows = (rows + downSampleRate - 1) / downSampleRate;
	int downSampledCols = (columns + downSampleRate - 1) / downSampleRate;

	Mat downSampled = Mat(downSampledRows, downSampledCols, CV_8UC3);
	
	Mat_<Vec3b> _image = image;
	Mat_<Vec3b> _downSampled = downSampled;
	for (Vec3b elem : _downSampled)
	{
		cout << elem;
	}

	for (int i = 0, downI = 0; i < rows; i += downSampleRate, downI++)
	{
		for (int j = 0, downJ = 0; j < columns; j += downSampleRate, downJ++)
		{
			//average the pixels in the downsampled area (for downsampling rate of 2, the area will be 4
			_downSampled(downI, downJ) = calculatePixel(image, i, j, downSampleRate);
		}
	}

	imshow("downsample by average", _downSampled);
}


/**
 * \brief the function calculates a single pixel based on the nXn close pixels
 * \param image original image to be downsampled
 * \param i the on-hand row number
 * \param j the on-hand column number
 * \param downSampleRate e.g.: 2 means that we want half the rows and half the columns
 * \return 
 */
Vec3b calculatePixel(const Mat& image, int i, int j, int downSampleRate)
{

	Mat_<Vec3b> _image = image;
	int outputPixel[3] = { 0,0,0 };
	int pixelCount = 0;

	for (int rowI = 0; rowI < downSampleRate && i + rowI < image.rows; rowI++)
	{
		for (int colI = 0; colI < downSampleRate && j + colI < image.cols; colI++)
		{
			Vec3b pixel = _image(i+rowI, j+colI);
			outputPixel[0] += pixel[0];
			outputPixel[1] += pixel[1];
			outputPixel[2] += pixel[2];
			pixelCount++;
		}
	}
	outputPixel[0] /= pixelCount;
	outputPixel[1] /= pixelCount;
	outputPixel[2] /= pixelCount;
	Vec3b outputPixelV = Vec3b(outputPixel[0], outputPixel[1], outputPixel[2]);

	
	return  outputPixelV;
}