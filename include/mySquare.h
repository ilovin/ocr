#pragma once

#include <opencv2/opencv.hpp>
#include <math.h>

#include"baseDefine.h"
#include"baseBox.h"



//using namespace cv;
//using namespace std;


//#define paper_width 3000  //500 
//#define paper_height 1980  //330


// sort the squares according to area
vector<BaseBox<>> SortByArea(const vector<vector<cv::Point>>& squares);
//merge the same squares
//void MergeSquare(const cv::Mat& image, vector<BaseBox<>>& SortSqu);
// average squares
//vector<cv::Point> aveSquare(vector<vector<cv::Point>> squs);

// Delete red seal

// if the image is too large, then down sample
void MyBinShow(const char*wnd, const cv::Mat& image);
//image with 3 channels
void MyImgShow(const char*wnd, const cv::Mat& image);

// calculate the average angle from the SortSquare
//double CalAngle(const vector<BaseBox<>>& SortSquare);
//find border of the sheet, then calculate the angle
//double FindAngle(const cv::Mat& image, vector<BaseBox<>>& SortSquare);
// adjust image
//cv::Mat AdjustImage(const cv::Mat& image, vector<BaseBox<>>& SortSquare);

