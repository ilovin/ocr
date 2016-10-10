#include "sheet.h"

vector<vector<Sheet>> creatSheet()
{
	Sheet Single;
	vector<Sheet> temBill;
	vector<vector<Sheet> > Bill;
	//int nItem = 21;// 21 tatol items
	 
	string Item;
	string Cont;
	int row, col;
	double wid[3], hei;

	
	//initialize the detail items
	Cont = "Empty"; 

	Item = ("¿¿¿¿/¿¿¿¿/¿¿¿¿");
	row = 0;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG); 
	// set the normalized square
	//wid[boxALL] = 866.0/1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 445.0 / 1500.0;
	hei = 235.0/990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¿¿¿";
	row = 0;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 895.0 / 1500.0;
	wid[boxITEM] = 59.0 / 1500.0;
	wid[boxCONTENT] = 783.0 / 1500.0;
	hei = 235.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill); // the first row
	temBill.clear();

	Item = "¿¿¿/¿¿¿¿";
	row = 1;
	col = 0;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 715.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 505.0 / 1500.0;
	hei = 100.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "Empty";
	row = 1;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 782.0 / 1500.0;
	wid[boxITEM] = 332.0 / 1500.0;
	wid[boxCONTENT] = 450.0 / 1500.0;
	hei = 100.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill); //the second row
	temBill.clear();

	Item = "¿¿¿¿";
	row = 2;
	col = 0;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 530.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 320.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¿¿¿¿";
	row = 2;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG_CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 636.0 / 1500.0;
	wid[boxITEM] = 128.0 / 1500.0;
	wid[boxCONTENT] = 508.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¿¿";
	row = 2; 
	col = 2;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 332.0 / 1500.0;
	wid[boxITEM] = 78.0 / 1500.0;
	wid[boxCONTENT] = 254.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the third row
	temBill.clear();

	Item = "¿¿¿¿";
	row = 3;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 530.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] =320.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "Empty";
	row = 3;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 967.0 / 1500.0;
	wid[boxITEM] = 185.0 / 1500.0;
	wid[boxCONTENT] =782.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 4th row
	temBill.clear();

	Item = "¿¿¿¿";
	row = 4;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 714.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] =504.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¿¿¿¿¿¿/¿¿¿¿";
	row = 4;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 783.0 / 1500.0;
	wid[boxITEM] = 302.0 / 1500.0;
	wid[boxCONTENT] =481.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 5th row
	temBill.clear();

	Item = "¼ÛË°ºÏ¼Æ";
	row = 5;
	col = 0;
	Single.setSheet(Item, Cont, row, col,CHI_TRA);
	// set the normalized square
	//wid[boxALL] = 1010.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 800.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¼ÛË°Ð¡Ð´";
	row = 5;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 487.0 / 1500.0;
	wid[boxITEM] = 167.0 / 1500.0;
	wid[boxCONTENT] = 320.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill); //the 6th row
	temBill.clear();

	Item = "Ïú»õµ¥Î»Ãû³Æ";
	row = 6;
	col = 0;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 985.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 775.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill); //the 7th row
	temBill.clear();

	Item = "ÄÉË°ÈËÊ¶±ðºÅ";
	row = 7;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 775.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "ÕËºÅ";
	row = 7;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 75.0 / 1500.0;
	wid[boxCONTENT] = 437.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 8th row
	temBill.clear();

	Item = "µØÖ·";
	row = 8;
	col = 0;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 582.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "¿ª»§ÒøÐÐ";
	row = 8;
	col = 1;
	Single.setSheet(Item, Cont, row, col,CHI_SIM);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 120.0 / 1500.0;
	wid[boxCONTENT] = 585.0 / 1500.0;
	hei = 71.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 9th row
	temBill.clear();

	Item = "Empty";
	row = 9;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 1287.0 / 1500.0;
	hei = 91.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 10th row,empty
	temBill.clear();


	Item = "²»º¬Ë°¼Û";
	row = 10;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 352.0 / 1500.0;
	hei = 65.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "Empty";
	row = 10;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 177.0 / 1500.0;
	wid[boxCONTENT] = 510.0 / 1500.0;
	hei = 65.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "ÏÞ³ËÈËÊý";
	row = 10;
	col = 2;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 128.0 / 1500.0;
	wid[boxCONTENT] = 120.0 / 1500.0;
	hei = 65.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 11th row
	temBill.clear();

	Item = "Empty";
	row = 11;
	col = 0;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 656.0 / 1500.0;
	hei = 235.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	//Bill.push_back(temBill);  //the  th row
	//temBill.clear();

	Item = "Empty";
	row = 11;
	col = 1;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 656.0 / 1500.0;
	hei = 235.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Item = "Empty";
	row = 11;
	col = 2;
	Single.setSheet(Item, Cont, row, col,ENG);
	// set the normalized square
	//wid[boxALL] = 866.0 / 1500.0;
	wid[boxITEM] = 210.0 / 1500.0;
	wid[boxCONTENT] = 656.0 / 1500.0;
	hei = 235.0 / 990.0;
	Single.setWidHeig(wid, hei);
	temBill.push_back(Single);

	Bill.push_back(temBill);  //the 12th row
	temBill.clear();

	return Bill;
}

//"Box" is the biggest box on the sheet
// create boxes that circumscribe "item" or "content"
void SheetImage(vector<vector<Sheet>>& Bill,vector<cv::Point> Box)
{
	int numRow = (int)Bill.size()-1, numCol,temWid,temHei;	
	int widBox = Box[RIGHT_UP].x - Box[LEFT_UP].x, heiBox= Box[LEFT_DOWN].y - Box[LEFT_UP].y;
	 
	cv::Point pointLU = Box[LEFT_UP];
	temHei = 0;
	for (int i = 0; i < numRow; i++)
	{
		if (i > 0)
		{
			temHei = temHei + (int)(Bill[i - 1][0].getHeight()*heiBox + 0.5);  //round
			pointLU = cv::Point(Box[LEFT_UP].x, Box[LEFT_UP].y+temHei);
		}
		numCol = (int)(Bill[i].size());
			for (int j = 0; j < numCol; j++)
			{
				// creat item square
				if (j > 0)
				{
					temWid = (int)(Bill[i][j-1].getWidth(boxCONTENT)*widBox + 0.5);
					pointLU = pointLU + cv::Point(temWid, 0);  //the left-up point of "item"
				}
				Bill[i][j].creatSquare(pointLU, widBox, heiBox, boxITEM);
				// creat content square
				temWid = (int)(Bill[i][j].getWidth(boxITEM)*widBox+0.5);
				pointLU = pointLU + cv::Point(temWid, 0);  //the left-up point of "content"
				Bill[i][j].creatSquare(pointLU, widBox, heiBox, boxCONTENT);
			}
	}

	//the two head squares
	//"¿ªÆ±ÈÕÆÚ"
	//item
	temHei = (int)(Bill[numRow][0].getHeight()*heiBox+0.5);
	pointLU = Box[LEFT_UP] - cv::Point(0, temHei);
	Bill[numRow][0].creatSquare(pointLU, widBox, heiBox, boxITEM);
	// creat content square
	temWid = (int)(Bill[numRow][0].getWidth(boxITEM)*widBox + 0.5);
	pointLU = pointLU + cv::Point(temWid, 0);  //the left-up point of "content"
	Bill[numRow][0].creatSquare(pointLU, widBox, heiBox, boxCONTENT);

	//"·¢Æ±´úÂë"
	//item
	temHei = (int)((Bill[numRow][1].getHeight() + Bill[numRow][2].getHeight())*heiBox + 0.5);
	temWid = (int)((Bill[0][0].getWidth(boxALL)+ Bill[0][1].getWidth(boxALL)-0.5*Bill[0][1].getWidth(boxCONTENT))*widBox + 0.5);
	pointLU = Box[LEFT_UP] + cv::Point(temWid, -temHei);
	Bill[numRow][1].creatSquare(pointLU, widBox, heiBox, boxITEM);
	// creat content square
	temWid = (int)(Bill[numRow][1].getWidth(boxITEM)*widBox + 0.5);
	pointLU = pointLU + cv::Point(temWid, 0);  //the left-up point of "content"
	Bill[numRow][1].creatSquare(pointLU, widBox, heiBox, boxCONTENT);

	//"·¢Æ±ºÅÂë"
	//item
	temWid = (int)((Bill[0][0].getWidth(boxALL) + Bill[0][1].getWidth(boxALL) - 0.5*Bill[0][1].getWidth(boxCONTENT))*widBox + 0.5);
	temHei = (int)(Bill[numRow][2].getHeight()*heiBox);
	pointLU= Box[LEFT_UP] + cv::Point(temWid, -temHei);
	Bill[numRow][2].creatSquare(pointLU, widBox, heiBox, boxITEM);
	// creat content square
	temWid = (int)(Bill[numRow][2].getWidth(boxITEM)*widBox + 0.5);
	pointLU = pointLU + cv::Point(temWid,0);  //the left-up point of "content"
	Bill[numRow][2].creatSquare(pointLU, widBox, heiBox, boxCONTENT);
}

/* find four points in order to do perspective transformation
perspImage: the result of the perspective transformation
*/
void ExtractBill(const cv::Mat& srcImage, cv::Mat& perspImage, vector<Position>& SortSquare)
{
	int sameP = 5,// the points are on the same line
		minFlag = 10,
		onflag, online;
	int nSqu = (int)SortSquare.size();

	double  maxAng = 1.0 * CV_PI / 180.0;
	vector<cv::Point2d> Pre, Cur, vecP;

	double lenV[3], angV[3];
	vector<cv::Point2f> pointList(4);
	vector<cv::Point2f> dstPointList = { cv::Point2f(0, 0), cv::Point2f(paper_width, 0),
		cv::Point2f(paper_width, paper_height), cv::Point2f(0, paper_height) };


	for (int i = 0; i < nSqu; i++)
	{
		Pre.clear();
		onflag = 0; //the number of squares that the left vertical line are on the square "i's" left vertical line
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

		if (onflag > minFlag)// the biggest box is found
		{
			//find the right-up point of the biggest box
			double sdx[4], sdy[4], sdist[4],
				recDis[4],// the height of the square whose distance between the biggest square is the minimum
				mindist[4] = { -1.0,-1.0,-1.0,-1.0 };
			vector<cv::Point> pointRU(4);
			for (int k = i + 1; k < nSqu; k++)
			{
				if ((SortSquare[k].getArea() / SortSquare[i].getArea()) < 0.5)
				{
					for (int m = 0; m < 4; m++)//anticlockwise
					{
						sdx[m] = SortSquare[k].getSquare(m).x - SortSquare[i].getSquare(m).x;
						sdy[m] = SortSquare[k].getSquare(m).y - SortSquare[i].getSquare(m).y;
						sdist[m] = sqrt(sdx[m]*sdx[m] + sdy[m]*sdy[m]);
						if (mindist[m] == (-1.0))
						{
							mindist[m] = sdist[m];// find the minmum distance
							pointRU[m] = SortSquare[k].getSquare(m);
							recDis[m] = SortSquare[k].getHeight()/2.0;// get the limitation
						}
						else if (sdist[m] < mindist[m])
						{
							mindist[m] = sdist[m];
							pointRU[m] = SortSquare[k].getSquare(m);
							recDis[m] = SortSquare[k].getHeight();
						}
					}					

				}
			}

			//int rc = 50;
			//circle(srcImage, pointRU, rc, CvScalar(255, 0, 0),7);
			//MyImageShow(srcImage);			
			//cvWaitKey();

			//clockwise
			for (int m = 0; m < 4; m++)
			{
				if (m == LEFT_UP)
				{
					if (mindist[m] < (0.3*recDis[m]))
					{
						pointList[0] = pointRU[LEFT_UP];
					}
					else
					{
						pointList[0] = SortSquare[i].getSquare(LEFT_UP);
					}
				}
				if (m == RIGHT_UP)
				{
					if (mindist[m] < (0.8 * recDis[m]))
					{
						pointList[1] = pointRU[RIGHT_UP];
					}
					else
					{
						pointList[1] = SortSquare[i].getSquare(RIGHT_UP);
					}
				}
				if (m == RIGHT_DOWN)
				{
					if (mindist[m] < (0.7*recDis[m]))
					{
						pointList[2] = pointRU[RIGHT_DOWN];
					}
					else
					{
						pointList[2] = SortSquare[i].getSquare(RIGHT_DOWN);
					}
				}
				if (m == LEFT_DOWN)
				{
					if (mindist[m] < (0.7*recDis[m]))
					{
						pointList[3] = pointRU[LEFT_DOWN];
					}
					else
					{
						pointList[3] = SortSquare[i].getSquare(LEFT_DOWN);
					}
				}
			}

			//pointList[0] = SortSquare[i].getSquare(LEFT_UP);
			//pointList[1] = SortSquare[i].getSquare(RIGHT_UP);
			//pointList[2] = SortSquare[i].getSquare(RIGHT_DOWN);
			//pointList[3] = SortSquare[i].getSquare(LEFT_DOWN);

			//cv::Mat dst_img = image.clone();

			cv::Mat trans = cv::getPerspectiveTransform(pointList, dstPointList);
			cv::warpPerspective(srcImage, perspImage, trans, cv::Size(paper_width, paper_height));
			//imshow("perspective", dst_img);
			// delete the squares that before the "i"th square
			/*if (i > 0)
			{
				vector<Position>::iterator begSq, endSq;
				begSq = SortSquare.begin();
				endSq = begSq + i;
				SortSquare.erase(begSq, endSq);

			}
			else if (i == 0)
			{
				vector<Position>::iterator begSq;
				begSq = SortSquare.begin();
				SortSquare.erase(begSq);
			}*/

			break;
		}
	}

}


//Read Unicode UTF-8 file into wstring
std::wstring readFile(const char* filename)//(const char* filename)
{
	std::wifstream wif(filename);
	// wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}


/* save the "content" of a bill
and put them into "tesseract.exe" to be recognised
Bill: the bill correspond to the input image
image: the image which has been done perspective transform
*/
void RecognizeContent(const cv::Mat& image, vector<vector<Sheet>>& Bill)
{
	//vector<cv::Rect> billRects;
	cv::Rect rect;
	int numRow = (int)Bill.size()-1,// without "¿ªÆ±ÈÕÆÚ£¬·¢Æ±´úÂë£¬·¢Æ±ºÅÂë"
		numCol;
	cv::Mat tempImage;
	char ImagePath[50];
	char TessParam[300];
	char TxtPath[50];
	wstring TxtFile;
	
	//int outflag = 0;
	for (int bi = 0; bi < numRow; bi++)
	{
		numCol = (int)Bill[bi].size();
		for (int bj = 0; bj < numCol; bj++)
		{
			if (!Bill[bi][bj].Empty())// the content is required
			{
				// move the left-up point a little in order to delete the line
				rect.x = Bill[bi][bj].getContSquare(LEFT_UP).x + (int)(0.07*Bill[bi][bj].Height);
				rect.y = Bill[bi][bj].getContSquare(LEFT_UP).y + (int)(0.07*Bill[bi][bj].Height);
				rect.width = Bill[bi][bj].Width[boxCONTENT] - (int)(0.1*Bill[bi][bj].Height);
				rect.height = Bill[bi][bj].Height - (int)(0.2*Bill[bi][bj].Height);
				//billRects.push_back(rect);
				//r: row, c: col
				/* get the parameters of OCR*/
				sprintf(ImagePath, ".\\tempJpg\\r%dc%d.jpg  ", bi, bj);
				string strIP(ImagePath);				
				sprintf(TxtPath, ".\\tempTxt\\r%dc%d", bi, bj);
				string strTTP(TxtPath);
				strIP = strIP + strTTP;  //union
				string tempSP;// = "-l eng --tessdata-dir  .\\tesseract\\tessdata";
				// eng/chi_sim/chi_tra
				if (Bill[bi][bj].getCharacter() == ENG)
				{
					tempSP = " -l eng --tessdata-dir  .\\tesseract\\tessdata";
				}
				else if (Bill[bi][bj].getCharacter() == CHI_SIM)
				{
					tempSP = " -l chi_sim --tessdata-dir  .\\tesseract\\tessdata";
				}
				else if (Bill[bi][bj].getCharacter() == CHI_TRA)
				{
					tempSP = " -l chi_tra --tessdata-dir  .\\tesseract\\tessdata";
				}
				else if (Bill[bi][bj].getCharacter() == ENG_CHI_SIM)
				{
					tempSP = " -l eng+chi_sim --tessdata-dir  .\\tesseract\\tessdata";
				}				
				string strTP = strIP + tempSP;//txt path
				
				//".\\tempJpg\\r%dc%d.jpg .\\tempTxt\\r%dc%d.txt 
				//-l chi_sim+eng+chi_tra --tessdata-dir  .\\tesseract\\tessdata "
				strcpy(TessParam, strTP.c_str());//copy to char*, used for "ShellExecuteA"
				tempImage = image(rect);  // cut the squares
				cv::imwrite(ImagePath, tempImage); //save the squares

				/* start tesseract.exe untill it ends */
				// wchar_t* wString = new wchar_t[100];
				// MultiByteToWideChar(CP_ACP, 0, ".\\tesseract\\tesseract.exe", -1, wString, 100);
				// wchar_t* wTessPara = new wchar_t[300];
				// MultiByteToWideChar(CP_ACP, 0, TessParam, -1, wTessPara, 300);
				// SHELLEXECUTEINFO ShExecInfo = { 0 };
				// ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
				// ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
				// ShExecInfo.hwnd = NULL;
				// ShExecInfo.lpVerb = NULL;
				// ShExecInfo.lpFile = wString;
				// ShExecInfo.lpParameters = wTessPara;
				// ShExecInfo.lpDirectory = NULL;
				// ShExecInfo.nShow = SW_HIDE;
				// ShExecInfo.hInstApp = NULL;
				// //ShellExecuteA(&ShExecInfo);
				// ShellExecuteEx(&ShExecInfo);
				// WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

				//HINSTANCE hNewE = ShellExecuteA(NULL, "open", ".\\tesseract\\tesseract.exe", 
					//TessParam,NULL,SW_HIDE);
	
				//cvWaitKey(500);
				//get the txt path
				string postfix = ".txt";
				strTTP += postfix;
				strcpy(TxtPath, strTTP.c_str());
				TxtFile = readFile(TxtPath);
				//outflag++;
				cout << Bill[bi][bj].getItem()<<":" <<endl;
				//cvWaitKey(500);
				wcout.imbue(locale("chs"));
				wcout << TxtFile << "\n"<<endl;
				//cvWaitKey(1000);
				//printf("r%dc%d\n", bi, bj);
				

 				
			}

		}

	}


}







/*
//match boxes
void boxMatch(vector<vector<Sheet>>& Bill, vector<Position>& SortSquare)
{
	//extract the squares from "SortSquare"
	vector<Position>::iterator ptBeg, ptEnd; //iterator of position
		vector<vector<cv::Point>> bSquare;
	ptBeg = SortSquare.begin();
	ptEnd = SortSquare.end();
	for (; ptBeg != ptEnd; ptBeg++)
	{
		bSquare.push_back((*ptBeg).getSquare());
	}

	// match the squares, if some squares are matched, 
	//save them as "*.jpg", and delete them 
	int numRow = (int)Bill.size()-1, numCol;//the last one will be dealt alone
	//vector<vector<cv::Point>>::iterator sqBeg, sqEnd,sqTemp;  //the iterator of square
	double dx, dy,tempDis, 
		dist, //distance
		maxArea,//the maximum difference of two area
		maxDist;//the maximum difference of distance
	vector<cv::Point> tempSquare;

	if (!SortSquare.empty())
	{
		ptBeg = SortSquare.begin();
		ptEnd = SortSquare.end();
		for (int bi = 0; bi < numRow; bi++)
		{
			numCol = (int)Bill[bi].size();
			for (int bj = 0; bj < numCol; bj++)
			{
				//for (int bk = 0; bk < 2; bk++) //"item" and "content"
				//{
					tempDis=SortSquare[0].getHeight();
					for (; ptBeg != ptEnd; ++ptBeg)
					{
						dx = (double)(Bill[bi][bj].Center[boxCONTENT].x - (*ptBeg).getCenter().x);
						dy = (double)(Bill[bi][bj].Center[boxCONTENT].y - (*ptBeg).getCenter().y);
						dist = sqrt(dx*dx + dy*dy);
						maxDist = 0.5*Bill[bi][bj].Height;
						maxArea = 0.2*Bill[bi][bj].Area[boxCONTENT];
						if ((dist < maxDist) && (fabs(Bill[bi][bj].Area[boxCONTENT] - (*ptBeg).getArea()) < maxArea))
						{
							if (dist < tempDis)
							{
								tempDis = dist;
								tempSquare = (*ptBeg).getSquare();
							}

						}

					}

				//}



			}
		}
	}



}*/
