#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
/*
static void help()
{
	std::cout <<	
		"\nA program using pyramid scaling, Canny, contours, contour simpification and\n"
		"memory storage (it's got it all folks) to find\n"
		"squares in a list of images pic1-6.png\n"
		"Returns sequence of squares detected on the image.\n"
		"the sequence is stored in the specified memory storage\n"
		"Call:\n"
		"./squares\n"
		"Using OpenCV version %s\n" << CV_VERSION << "\n" << endl;
}
*/

// extern int thresh, N;
// extern const char* wndname;

// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
// {
	// double dx1 = pt1.x - pt0.x;
	// double dy1 = pt1.y - pt0.y;
	// double dx2 = pt2.x - pt0.x;
	// double dy2 = pt2.y - pt0.y;
	// return (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
// }

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
void findSquares(const cv::Mat& image, vector<vector<cv::Point> >& squares);
// {
	// squares.clear();

	// cv::Mat pyr, timg, gray0(image.size(), CV_8U), gray;
	// int nCol = image.cols, nRow = image.rows;
	// int minArea = (int)(nCol*nRow / (30 * 40));// the minimum area


											   // // down-scale and upscale the image to filter out the noise
	// pyrDown(image, pyr, cv::Size(image.cols / 2, image.rows / 2));
	// pyrUp(pyr, timg, image.size());


	// vector<vector<cv::Point> > contours;

	// // find squares in every color plane of the image
	// for (int c = 0; c < 3; c++)
	// {
		// int ch[] = { c, 0 };   // "c" is the input channel, "0" is the output channel
							   // //Copies specified channels from input arrays to the specified channels of output arrays.
		// mixChannels(&timg, 1, &gray0, 1, ch, 1);

		// // try several threshold levels
		// for (int th = 0; th < N; th++)
		// {
			// // hack: use Canny instead of zero threshold level.
			// // Canny helps to catch squares with gradient shading
			// if (th == 0)
			// {
				// // apply Canny. Take the upper threshold from slider
				// // and set the lower to 0 (which forces edges merging)
				// Canny(gray0, gray, 0, thresh, 5);
				// //imshow("canny", gray);
				// //waitKey();

				// // dilate canny output to remove potential
				// // holes between edge segments
				// dilate(gray, gray, cv::Mat(), cv::Point(-1, -1));
				// //imshow("dilate", gray);
				// //waitKey();

			// }
			// else
			// {
				// // apply threshold if th!=0:
				// //     tgray(x,y) = gray(x,y) < (th+1)*255/N ? 255 : 0
				// gray = gray0 >= (th + 1) * 255 / N;
			// }

			// // find contours and store them all as a list
			// findContours(gray, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

			// vector<cv::Point> approx;

			// // test each contour
			// for (size_t i = 0; i < contours.size(); i++)
			// {
				// // approximate contour with accuracy proportional
				// // to the contour perimeter
				// //参数为：输入图像的2维点集，输出结果，估计精度，是否闭合
				// // Mat(contours[i]): contours[i].size()  *  1 的矩阵
				// approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
				// cv::Mat ttt = cv::Mat(contours[i]);
				// // square contours should have 4 vertices after approximation
				// // relatively large area (to filter out noisy contours)
				// // and be convex.
				// // Note: absolute value of an area is used because
				// // area may be positive or negative - in accordance with the
				// // contour orientation
				// if (approx.size() == 4 &&
					// fabs(cv::contourArea(cv::Mat(approx))) > minArea &&
					// cv::isContourConvex(cv::Mat(approx)))
				// {
					// double maxCosine = 0;

					// for (int j = 2; j < 5; j++)
					// {
						// // find the maximum cosine of the angle between joint edges
						// double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
						// maxCosine = MAX(maxCosine, cosine);
					// }

					// // if cosines of all angles are small
					// // (all angles are ~90 degree) then write quandrange
					// // vertices to resultant sequence
					// if (maxCosine < 0.1)
						// squares.push_back(approx);
				// }
			// }
		// }
	// }
// }


// the function draws all the squares in the image
void drawSquares(cv::Mat& image, const vector<vector<cv::Point> >& squares);
// {
	// for (size_t i = 0; i < squares.size(); i++)
	// {
		// const cv::Point* p = &squares[i][0];  // the "i"th square, the first point
		// int n = (int)squares[i].size();
		// polylines(image, &p, &n, 1, true, cv::Scalar(0, 255, 0), 3, cv::LINE_AA);
	// }

	// if (image.rows > 3000)
	// {
		// // down sample
		// cv::Mat downBin;
		// cv::resize(image, downBin, cv::Size(), 0.35, 0.35, CV_INTER_LINEAR);
		// imshow(wndname, downBin);
	// }
	// else
	// {
		// imshow(wndname, image);
	// }


// }
