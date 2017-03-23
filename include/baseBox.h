#pragma once

//// the position of a point in a box
//#define TOP_LEFT 0
//#define DOWN_LEFT 1
//#define DOWN_RIGHT 2
//#define TOP_RIGHT 3
#include <opencv2/opencv.hpp>
#include <math.h>
#include <vector>
#include "baseDefine.h"
//#include "baseBox.h"

using namespace cv;
using namespace std;


//the default template is "Point"
template<typename Point2idf = cv::Point> class BaseBox 
{

protected:
	std::vector<Point2idf> square; //four points,"Point,Point2f,Point2d"
	//std::vector<Point2d> square;
	//int row, col; //the position of the box
	Point2idf pTopLeft; //the point on the top-left 
	//cv::Point center;
	double height;
	double width;
	double area;
public:
	int TopLeft, DownLeft, DownRight, TopRight;//anti-clockwise
	BaseBox()
	{
		TopLeft = 0;
		DownLeft = 1;
		DownRight = 2;
		TopRight = 3;
		//RowCol.resize(2,0); // the first represents row, second column, all initialize 0
		square.resize(4, Point2idf(0,0));  // four points in a square
		pTopLeft = Point2idf(0, 0);
		height = 0;
		width = 0;
		area = 0;
	}

	/*
	// the four points are sorted by anticlockwise
	// the sort is TopLeft--DownLeft--DownRight--TopRight
	Square: a square contains four points
	*/	
	void antiClock(const vector<Point2idf>& Square)
	{
		//square = Square;
		//center = (Square[0] + Square[1] + Square[2] + Square[3]) / 4;
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
			if ((left > right) && (up > down)) square[TopLeft] = Square[i];//TopLeft
			else if ((left > right) && (up < down)) square[DownLeft] = Square[i];//DownLeft
			else if ((left < right) && (up > down)) square[TopRight] = Square[i];//TopRight
			else if ((left < right) && (up < down)) square[DownRight] = Square[i];//DownRight

		}
	}

	 /*
	 initialize the box
	 */	
	void boxInit(const vector<Point2idf>& Square)
	{
		square = Square;
		//row = sRow;		col = sCol;
		//center = (Square[0] + Square[1] + Square[2] + Square[3]) / 4;
		//center.y = (Square[0].y + Square[1].y + Square[2].y + Square[3].y) / 4;
		antiClock(Square);

		float Ldx = (float)((square[TopLeft].x - square[DownLeft].x)*(square[TopLeft].x - square[DownLeft].x));
		float Ldy = (float)((square[TopLeft].y - square[DownLeft].y)*(square[TopLeft].y - square[DownLeft].y));
		float Rdx = (float)((square[TopRight].x - square[DownRight].x)*(square[TopRight].x - square[DownRight].x));
		float Rdy = (float)((square[TopRight].y - square[DownRight].y)*(square[TopRight].y - square[DownRight].y));
		height = (double)(sqrtf(Ldx + Ldy) + sqrtf(Rdx + Rdy)) / 2;

		float Udx = (float)((square[TopLeft].x - square[TopRight].x)*(square[TopLeft].x - square[TopRight].x));
		float Udy = (float)((square[TopLeft].y - square[TopRight].y)*(square[TopLeft].y - square[TopRight].y));
		float Ddx = (float)((square[DownLeft].x - square[DownRight].x)*(square[DownLeft].x - square[DownRight].x));
		float Ddy = (float)((square[DownLeft].y - square[DownRight].y)*(square[DownLeft].y - square[DownRight].y));
		width = (double)(sqrtf(Udx + Udy) + sqrtf(Ddx + Ddy)) / 2;

		area = contourArea(Square);
		pTopLeft = square[TopLeft];

	}

	//set the "i"th point of square	
	void setSquare(Point2idf ssp, int i)
	{
		if (4 > i)
		{
			square[i] = ssp;
		}

	}	
	void setSquare(vector<Point2idf> vp)
	{
		square = vp;
	}

	void setTopLeft(Point2idf pTL)
	{
		pTopLeft = pTL;
	}

	//return square	
	std::vector<Point2idf> getSquare()
	{
		return square;
	}
	//return point
	Point2idf getSquare(int myP)
	{
		if ((int)square.size() > myP)
		{
			return square[myP];
		}
		else return cv::Point(-1, -1);

	}

	Point2idf getTopLeft()
	{
		return pTopLeft;
	}

	double getHeight()
	{
		return height;
	}

	double getWidth()
	{
		return width;
	}

	double getArea()
	{
		return area;
	}



};


