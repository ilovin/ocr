#pragma once
#include "DelRedSeal.h"



/* 
image: the original image
maskRed: binary image, the position of the seal
dstRed: the output of the image without the seal
*/
void DelSeal(const Mat &image, Mat &maskRed,Mat &dstRed)
{
	Mat hsvImg;
	Mat BinRed1, BinRed2, imgRed;
	Mat kern; //the kernel for dilate
	int sca[4] = { 0,8,160,180 };

	//find the red seal
	//Mat maskRed = Mat::zeros(image.rows, image.cols, CV_8U);
	cvtColor(image, hsvImg, CV_BGR2HSV);
	//binaryzation, h:0~10,s:100~255,v:120~255
	inRange(hsvImg, Scalar(sca[0], 100, 120), Scalar(sca[1], 255, 255), BinRed1);
	//binaryzation, h:170~180,s:100~255,v:120~255
	inRange(hsvImg, Scalar(sca[2], 100, 120), Scalar(sca[3], 255, 255), BinRed2);
	maskRed = BinRed1 + BinRed2;

	//delete the seal
	kern = getStructuringElement(CV_SHAPE_ELLIPSE, Size(5, 5));
	dilate(maskRed, maskRed, kern);
	inpaint(image, maskRed, dstRed, 3, INPAINT_TELEA);



}