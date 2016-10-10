#pragma once

#include <opencv2/opencv.hpp>
#include <math.h>
/*#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string.h>*/



//using namespace cv;
using namespace std;

#define LEFT_UP 0
#define LEFT_DOWN 1
#define RIGHT_DOWN 2
#define RIGHT_UP 3
//const int LEFT_UP = 0;
//const int LEFT_DOWN = 1;
//const int RIGHT_DOWN = 2;
//const int RIGHT_UP = 3;

#define paper_width 3000  //500 
#define paper_height 1980  //330


class Position
{
private:
	vector<cv::Point> square;
	cv::Point center;
	float height;
	float width;
    double area;
public:
	Position()
	{
		//square.push_back(cv::Point(-1, -1));
		center = cv::Point(-1, -1);
		height = 0.0;
		width = 0.0;
		area = 1.0;
	}
	/*vector<Point> square;
	Point center;
	float height;
	float width;
	double area;*/
	// the four points are sorted by anticlockwise
	// the sort is LEFT_UP--LEFT_DOWN--RIGHT_DOWN--RIGHT_UP	
	void antiClock(const vector<cv::Point>& Square)
	{
		square = Square;
		center = (Square[0] + Square[1] + Square[2] + Square[3]) / 4;
		//center.y = (Square[0].y + Square[1].y + Square[2].y + Square[3].y) / 4;
		int Num = (int)Square.size(), left, right, up, down;


		for (int i = 0; i < Num; i++)  // determine where the ith point should be
		{
			left = 0;
			right = 0;
			up = 0;
			down = 0;
			for (int j = 0; j < Num; j++)
			{
				if (Square[i].x < Square[j].x) left++;
				if (Square[i].x > Square[j].x) right++;
				if (Square[i].y < Square[j].y) up++;
				if (Square[i].y > Square[j].y) down++;
			}
			if ((left > right) && (up > down)) square[LEFT_UP] = Square[i];
			else if ((left > right) && (up < down)) square[LEFT_DOWN] = Square[i];
			else if ((left < right) && (up > down)) square[RIGHT_UP] = Square[i];
			else if ((left < right) && (up < down)) square[RIGHT_DOWN] = Square[i];

		}
		float Ldx = (float)((square[LEFT_UP].x - square[LEFT_DOWN].x)*(square[LEFT_UP].x - square[LEFT_DOWN].x));
		float Ldy = (float)((square[LEFT_UP].y - square[LEFT_DOWN].y)*(square[LEFT_UP].y - square[LEFT_DOWN].y));
		float Rdx = (float)((square[RIGHT_UP].x - square[RIGHT_DOWN].x)*(square[RIGHT_UP].x - square[RIGHT_DOWN].x));
		float Rdy = (float)((square[RIGHT_UP].y - square[RIGHT_DOWN].y)*(square[RIGHT_UP].y - square[RIGHT_DOWN].y));
		height = (sqrtf(Ldx + Ldy) + sqrtf(Rdx + Rdy))/2;

		float Udx = (float)((square[LEFT_UP].x - square[RIGHT_UP].x)*(square[LEFT_UP].x - square[RIGHT_UP].x));
		float Udy = (float)((square[LEFT_UP].y - square[RIGHT_UP].y)*(square[LEFT_UP].y - square[RIGHT_UP].y));
		float Ddx = (float)((square[LEFT_DOWN].x - square[RIGHT_DOWN].x)*(square[LEFT_DOWN].x - square[RIGHT_DOWN].x));
		float Ddy = (float)((square[LEFT_DOWN].y - square[RIGHT_DOWN].y)*(square[LEFT_DOWN].y - square[RIGHT_DOWN].y));
		width = (sqrtf(Udx + Udy) + sqrtf(Ddx + Ddy))/2;
		area = contourArea(Square);

	}
	
	//return square
	vector<cv::Point> getSquare()
	{
		return square;
	}
	//return point
	cv::Point getSquare(int myP)
	{
		if ((int)square.size() > myP)
		{
			return square[myP];
		}
		else return cv::Point(-1, -1);
		
	}
	//set the "i"th point of square
	void setSquare(cv::Point ssp,int i)
	{
		if (4>i)
		{
			square[i] = ssp;
		}
		
	}
	//return one point of the square
	void setSquare(vector<cv::Point> vp)
	{
		square = vp;
	}

	cv::Point getCenter()
	{
		return center;
	}

	float getHeight()
	{
		return height;
	}

	float getWidth()
	{
		return width;
	}

	double getArea()
	{
		return area;
	}



};





// sort the squares according to area
vector<Position> SortByArea(const vector<vector<cv::Point>>& squares);
//merge the same squares
void MergeSquare(const cv::Mat& image, vector<Position>& SortSqu);
// average squares
vector<cv::Point> aveSquare(vector<vector<cv::Point>> squs);

// Delete red seal
void DeleteRed(cv::Mat& image);
// if the image is too large, then down sample
void MyImageShow(const cv::Mat& image);
// calculate the average angle from the SortSquare
//double CalAngle(const vector<Position>& SortSquare);
//find border of the sheet, then calculate the angle
double FindAngle(const cv::Mat& image, vector<Position>& SortSquare);
// adjust image
cv::Mat AdjustImage(const cv::Mat& image, vector<Position>& SortSquare);

