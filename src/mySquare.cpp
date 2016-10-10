#include "mySquare.h"


// sort the squares according to area
vector<Position> SortByArea(const vector<vector<cv::Point>>& squares)
{
	vector<Position> Psquare;
	vector<Position>::iterator Pstart, Pend;
	Position Pos;
	int Num = (int)squares.size();
	for (int i = 0; i < Num; i++)
	{
		if (Psquare.empty())
		{
			Pos.antiClock(squares[i]);
			Psquare.push_back(Pos);
		}
		else
		{
			Pstart = Psquare.begin();
			Pend = Psquare.end();
			Pos.antiClock(squares[i]);
			for (; Pstart != Pend; ++Pstart)
			{
				if (Pos.getArea() > (*Pstart).getArea())  // from the biggest area to the minimum area
				{
					Psquare.insert(Pstart, Pos);
					break;
				}
			}
			if (Pstart == Pend)
			{
				Psquare.push_back(Pos);
			}
		}
	}

	return Psquare;
}

// average squares
vector<cv::Point> aveSquare(vector<vector<cv::Point>> squs)
{
	int num = (int)squs.size(),numi=(int)squs[0].size();
	cv::Point sumP;
	vector<cv::Point> ave;
	for (int i = 0; i < numi; i++) //number of points
	{
		sumP = cv::Point(0, 0);
		for (int j = 0; j < num ; j++)//number of squares
		{
			sumP =sumP + squs[j][i];
		}
		sumP = sumP / num;
		ave.push_back(sumP);
	}
	return ave;
}


//merge the same squares
void MergeSquare(const cv::Mat& image, vector<Position>& SortSqu)
{

	double minRate = 0.9, Arate; // the minimum rate of two areas 
	int maxDisCent = (int)(image.rows / 200); //if the centers are the same center?
	int Num = (int)SortSqu.size();
	int  j;  //flag;rate,
	vector<cv::Point> aveS;
	vector<vector<cv::Point>> squs;
	vector<Position>::iterator Sstart, EraseSta,EraseEnd;

	for (int i = 0; i < (Num - 1); i++)
	{
		//flag = 0;
		
		j = i ;
		Arate = SortSqu[j + 1].getArea() / SortSqu[i].getArea();
		while (((SortSqu[j + 1].getArea() / SortSqu[i].getArea()) > minRate) && (fabs(SortSqu[i].getCenter().x - SortSqu[j+1].getCenter().x) < maxDisCent)
			&& (fabs(SortSqu[i].getCenter().y - SortSqu[j+1].getCenter().y) < maxDisCent))  // the same squares
		{
			//flag ++;			
			j++;
			
			if (j >= (Num-1))
			{
				//j--;
				break;
			}
	
		}
		 
		if (j > i)
		{
			Sstart = SortSqu.begin();  // iterator
			EraseSta = Sstart + i+1;  
			EraseEnd = Sstart + j;
			 
			for (int k = 0; k <= (j - i); k++)
			{
				squs.push_back(SortSqu[i + k].getSquare());
			}
			SortSqu[i].setSquare(aveSquare(squs)) ;
			squs.clear();

			if ((j - i) == 1) // delete the elements from i+1 to j
			{
				SortSqu.erase(EraseSta);
			}
			else
			{
				SortSqu.erase(EraseSta, EraseEnd);  // locate the position where should be merged
			}
			
			
			Num = (int)SortSqu.size();


		}

		


	}
}

// Delete red seal
// this function need to be developed
void DeleteRed(cv::Mat& image)
{
	//Mat srcImage, binImage;
	vector<cv::Mat> channels, lab3c;   //  , mergeImage;
	cv::Mat  imageBlueChannel, imageGreenChannel, imageRedChannel, lab,blue_inv,mark;
	cv::MatIterator_<uchar> BlueStart, BlueEnd, GreenStart, GreenEnd, RedStart, RedEnd;
	int bluef = 0, greenf = 0, redf = 0, maxBlue = 128, minBlue = 0, minRed = 150;
	// split image into three channels
	split(image, channels);

	// "imageBlueChannel" is a reference (&) of channels.at(0)
	imageBlueChannel = channels.at(0);
	imageGreenChannel = channels.at(1);
	imageRedChannel = channels.at(2);

	// turn red to white
	cvtColor(image, lab, CV_BGR2Lab);

	//identify the red
	split(lab, lab3c);
	threshold(lab3c[2], blue_inv, 100, 255, cv::THRESH_BINARY);//less than 128, set it 255
	threshold(lab3c[1], mark, 128, 255, cv::THRESH_TOZERO);  //larger than 145,set it 255
	mark &= blue_inv;
	imageBlueChannel |= mark;
	imageGreenChannel |= mark;
	imageRedChannel |= mark;
	imshow("mark", mark);

	/*BlueStart= imageBlueChannel.begin<uchar>();
	BlueEnd = imageBlueChannel.end<uchar>();
	GreenStart = imageGreenChannel.begin<uchar>();
	GreenEnd = imageGreenChannel.end<uchar>();
	RedStart = imageRedChannel.begin<uchar>();
	RedEnd = imageRedChannel.end<uchar>();

	while ((BlueStart != BlueEnd) && (GreenStart != GreenEnd) && (RedStart != RedEnd))
	{
		if (((*BlueStart) < maxBlue) && ((*BlueStart) > minBlue)) bluef = 1;
		if (((*GreenStart) < maxBlue) && ((*GreenStart) > minBlue)) greenf = 1;
		if ((*RedStart) > minRed) redf = 1;
		if ((bluef == 1) && (greenf == 1) && (redf == 1))
		{
			*BlueStart = 255;
			*GreenStart = 255;
			*RedStart = 255;
		}
		bluef = 0;
		greenf = 0;
		redf = 0;
		BlueStart++;
		RedStart++;
		GreenStart++;
	}*/


	merge(channels, image);

}


// if the image is too large, then down sample
void MyImageShow(const cv::Mat& image)
{
	char* wnd = "Down Sample";
	if (image.rows > 1200)
	{
		// down sample
		cv::Mat downBin;
/*		int rowDS, colDS, DownS = 3;
		rowDS = (int)(image.rows / DownS) - 1;
		colDS = (int)(image.cols / DownS) - 1;
		Mat downBin(rowDS, colDS, CV_8UC3, Scalar(0, 0, 0));

		for (int dni = 0; dni < rowDS; dni++)
		{
			for (int dnj = 0; dnj < colDS; dnj++)
			{

				downBin.at<Vec3b>(dni, dnj) = image.at<Vec3b>(dni * DownS, dnj * DownS);  //point (dnj,dni)
			}
		}*/

		resize(image, downBin, cv::Size(), 0.4, 0.4, CV_INTER_LINEAR);
		imshow(wnd, downBin);
	}
	else
	{
		imshow(wnd, image);
	}
}


/*
// calculate the average angle from the SortSquare
double CalAngle( vector<Position>& SortSquare)
{
	int nSqu = (int)SortSquare.size();
	int beginSqu = (int)(0.3*nSqu), beginAng, endAng;
	double sumAng=0, calAng;
	vector<double> Angle;
	vector<double>::iterator angStart, angEnd;

	for (int i = beginSqu; i < nSqu; i++)  // Select some elements from SortSquare to calculate angle
	{
		// use left-up and left-down points to calculate angle
		double dx = (double)(SortSquare[i].getSquare(LEFT_UP).x - SortSquare[i].getSquare(LEFT_DOWN).x);
		double dy = (double)(SortSquare[i].getSquare(LEFT_DOWN).y - SortSquare[i].getSquare(LEFT_UP).y);
		calAng = atan(dx / dy);
		if (Angle.empty())
		{
			Angle.push_back(calAng);
		}
		else
		{
			angStart = Angle.begin();
			angEnd = Angle.end();
			for (; angStart != angEnd; ++angStart)
			{
				if (calAng > (*angStart)) // sort the angles from the biggest to the minimum
				{
					Angle.insert(angStart, calAng);
					break;
				}				
			}
			if (angStart == angEnd)
			{
				Angle.push_back(calAng);
			}
		}
	}

	beginAng = (int)(0.1*Angle.size());
	endAng = (int)(0.9*Angle.size());
	for (int j = beginAng; j < endAng; j++)  //select some angles to calculate the average angle
	{
		sumAng += Angle[j];
	}
	sumAng = sumAng / (endAng - beginAng);
	return sumAng;
}
*/

/* find border of the sheet, then calculate the angle
three points have three vectors, if angles of every two vectors are zero, 
three points are on the same line
Output: radian, anticlockwise is positive
*/
double FindAngle(const cv::Mat& image, vector<Position>& SortSquare)
{
	int sameP = 5,// the points are on the same line
		minFlag = 10, 
		onflag, online;
	int nSqu = (int)SortSquare.size();
	int maxOnline = (int)(image.rows / 200);
	double angle, maxAng=1.0 * CV_PI/180.0;
	vector<cv::Point2d> Pre, Cur, vecP;
	cv::Point2d temV;
	double lenV[3], angV[3];
	
	for (int i = 0; i < nSqu; i++)
	{
		Pre.clear();
		onflag = 0; //the number of squares that the left vertical line are on the square i's left vertical line
		//the chosen points
		Pre.push_back(SortSquare[i].getSquare(LEFT_UP));
		Pre.push_back(SortSquare[i].getSquare(LEFT_DOWN));
		for (int j = i + 1; j < nSqu; j++)
		{
			if ((SortSquare[j].getArea() / SortSquare[i].getArea()) < 0.2)
			{
				Cur.clear();
				//the detected points
				Cur.push_back(SortSquare[j].getSquare(LEFT_UP));
				Cur.push_back(SortSquare[j].getSquare(LEFT_DOWN));

				// if three points are on the same line, the vectors should be parallel
				online = 0;  //the three points are on the same  line
				for (int k = 0; k < 2; k++)
				{
					vecP.clear();
					//the first vector
					vecP.push_back(Pre[1] - Cur[k]);
					lenV[0] = sqrt(vecP[0].x*vecP[0].x + vecP[0].y*vecP[0].y);//length
																			  // the second
					vecP.push_back(Cur[k] - Pre[0]);
					lenV[1] = sqrt(vecP[1].x*vecP[1].x + vecP[1].y*vecP[1].y);//length
																			  //the third
					vecP.push_back(Pre[1] - Pre[0]);  //the long vetor
					lenV[2] = sqrt(vecP[2].x*vecP[2].x + vecP[2].y*vecP[2].y);//length
					if (lenV[2] < 1.0) lenV[2] = 1;

					if ((lenV[0] < sameP) || (lenV[1] < sameP))
					{
						online++;  //the three points are on the same  line
					}
					else
					{
						angV[0] = acos(fabs((vecP[0].x*vecP[1].x + vecP[0].y*vecP[1].y) / (lenV[0] * lenV[1])));//0,1
						angV[1] = acos(fabs((vecP[0].x*vecP[2].x + vecP[0].y*vecP[2].y) / (lenV[0] * lenV[2])));//0,2
						angV[2] = acos(fabs((vecP[2].x*vecP[1].x + vecP[2].y*vecP[1].y) / (lenV[2] * lenV[1])));//1,2
						if ((angV[0] < maxAng) && (angV[1] < maxAng) && (angV[2] < maxAng))// the vectors are parellel
						{
							online++;
						}

					}
				}
				if (online == 2) onflag++;
			  }
			}
		if (onflag > minFlag)
		{
			//calculate the angle, anticlockwise direction is positive

			// calculate the vertical line
			//double dx = (double)(SortSquare[i].getSquare(LEFT_DOWN).x - SortSquare[i].getSquare(LEFT_UP).x);
			//double dy = (double)(SortSquare[i].getSquare(LEFT_DOWN).y - SortSquare[i].getSquare(LEFT_UP).y);

			//calculate the horizontal line
			double dx = (double)(SortSquare[i].getSquare(RIGHT_UP).x - SortSquare[i].getSquare(LEFT_UP).x);
			double dy = (double)(SortSquare[i].getSquare(RIGHT_UP).y - SortSquare[i].getSquare(LEFT_UP).y);


			angle = atan(dy / dx);

			//const Point* p = &SortSquare[i].square[0];  // the "i"th square, the first point
			//int n = (int)SortSquare[i].square.size();
			//polylines(image, &p, &n, 1, true, Scalar(0, 255, 0), 3, LINE_AA);

			// delete the squares that before the "i"th square
			if (i > 0)
			{
				vector<Position>::iterator begSq, endSq;
				begSq = SortSquare.begin();
				endSq = begSq+i;
				SortSquare.erase(begSq, endSq);

			}
			else if (i == 0)
			{
				vector<Position>::iterator begSq;
				begSq = SortSquare.begin();
				SortSquare.erase(begSq);
			}

			break;
		}
		else angle = 0;
			

		
	}
	return angle;  //radian

}

// adjust image
cv::Mat AdjustImage(const cv::Mat& image, vector<Position>& SortSquare)
{

		CV_Assert(!image.empty());
		cv::Mat dst;
		double radian = FindAngle(image, SortSquare);  // rotate in the negative direction
		double angle = radian*180.0 / CV_PI;			

		int uniSize = max(image.cols, image.rows) * 2;
		int dx = (uniSize - image.cols) / 2;
		int dy = (uniSize - image.rows) / 2;

		copyMakeBorder(image, dst, dy, dy, dx, dx, cv::BORDER_CONSTANT);

		//旋轉中心
		cv::Point2f center((float)(dst.cols / 2), (float)(dst.rows / 2));
		cv::Mat affine_matrix = getRotationMatrix2D(center, angle, 1.0);

		warpAffine(dst, dst, affine_matrix, dst.size());

		double sinVal = fabs(sin(radian));
		double cosVal = fabs(cos(radian));

		//旋轉后的圖像大小
		cv::Size targetSize(image.cols * cosVal + image.rows * sinVal,
			image.cols * sinVal + image.rows * cosVal);

		//剪掉四周边框
		int x = (dst.cols - targetSize.width) / 2;
		int y = (dst.rows - targetSize.height) / 2;

		cv::Rect rect(x, y, targetSize.width, targetSize.height);
		dst = cv::Mat(dst, rect);

		//rotate the squares
		int moveX = (dst.cols - image.cols) / 2, moveY = (dst.rows - image.rows)/2, temX, temY;
		cv::Point moveP = cv::Point(moveX, moveY),//local cooedinate system moves in this direction
			cenP= cv::Point((int)(dst.cols/2), (int)(dst.rows / 2));//rotate center
		int nSque = (int)SortSquare.size();
		vector<Position>::iterator Pbeg, Pend;
		Pbeg = SortSquare.begin();
		Pend = SortSquare.end();
		//radian = -radian;
		for (; Pbeg != Pend;++Pbeg)
		{
			for (int j = 0; j < 4; j++)  // a square contains four points
			{
				 // translation
				(*Pbeg).setSquare((*Pbeg).getSquare(j) + moveP,j) ;
				// rotate
				temX = (int)(cos(radian)*((*Pbeg).getSquare(j).x-cenP.x)
					+ sin(radian)*((*Pbeg).getSquare(j).y-cenP.y))+cenP.x;
				temY = (int)(-sin(radian)*((*Pbeg).getSquare(j).x - cenP.x)
					+ cos(radian)*((*Pbeg).getSquare(j).y - cenP.y)) + cenP.y;
					
				(*Pbeg).setSquare(cv::Point(temX, temY),j) ;
				//(*Pbeg).square[j] = (*Pbeg).square[j] + moveP;
			}
		}


		return dst;
}

