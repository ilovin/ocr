#pragma once
#include "baseBox.h"
/*
all the definitions
*/

// the name of a box
#define ITEM 0
#define CONTENT 1
#define ALL 2

// character library
#define ENG 0  //English
#define CHI_SIM 1  // simple Chinese
#define CHI_TRA 2  // traditional Chinese
#define ENG_CHI_SIM 3
#define ENG_CHI_TRA 4
#define CHI_SIM_TRA 5
#define CHI_NUM 6  //traditional Chinese number

// the position of a point in a box
#define TOP_LEFT 0
#define DOWN_LEFT 1
#define DOWN_RIGHT 2
#define TOP_RIGHT 3

//the type of Point
#define BOX_POINT cv::Point2f

/*
overload the operator "/" for "std::vector<cv::Point>"
Point2ifd: only for type "Point,Point2f,Point2d"
Ifd:int, float, double
*/
template<typename Point2ifd,typename Ifd> std::vector<Point2ifd> operator / (std::vector<Point2ifd> squ, Ifd k)
{

	if ((k != 0) || (k != 0.0))
	{
		for (int i = 0; squ.size() > i; i++)
		{
			squ[i] = squ[i] / k;
		}
	}
	return squ;

}


/*
overload the operator "*" for "std::vector<cv::Point>"
Point2ifd: only for type "Point,Point2f,Point2d"
Ifd:int, float, double
*/
template<typename Point2ifd, typename Ifd> std::vector<Point2ifd> operator * (std::vector<Point2ifd> squ, Ifd k)
{
	
		for (int i = 0; squ.size() > i; i++)
		{
			squ[i] = squ[i] * k;
		}
	
	return squ;

}



//transfer "Point2f£¬d" to "Point"
template<typename Point2fd> std::vector<cv::Point> vecPointfd2Point(const std::vector<Point2fd>& squ)
{
	std::vector<cv::Point> vtemp;
	cv::Point ptemp;
	for (int i = 0; squ.size() > i; i++)
	{
		ptemp.x = round(squ[i].x);
		ptemp.y = round(squ[i].y);
		vtemp.push_back(ptemp);
	}
	return vtemp;
}

//square * point=(s.x*p.x,s.y*p.y)
//Point2ifd: only for type "Point,Point2f,Point2d"
template<typename Point2ifd1, typename Point2ifd2> std::vector<Point2ifd1> VecMultiPoint (const std::vector<Point2ifd1>& squ, Point2ifd2 poi)
{
	std::vector<Point2ifd1> tempS;
	tempS = squ;
	for (int i = 0; squ.size() > i; i++)
	{
		tempS[i].x = squ[i].x * poi.x;
		tempS[i].y = squ[i].y * poi.y;
	}
	return tempS;
}

//square / point
template<typename Point2ifd1, typename Point2ifd2> std::vector<Point2ifd1> VecDevPoint(const std::vector<Point2ifd1>& squ, Point2ifd2 poi)
{
	std::vector<Point2ifd1> tempS;
	tempS = squ;
	for (int i = 0; squ.size() > i; i++)
	{
		if ((poi.x != 0) && (poi.y != 0))
		{
			tempS[i].x = squ[i].x / poi.x;
			tempS[i].y = squ[i].y / poi.y;
		}

	}
	return tempS;
}






