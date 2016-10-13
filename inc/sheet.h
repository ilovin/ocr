#pragma once
#include "mySquare.h"
#include <string>

#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
//#include <shellapi.h>

#include <sstream>
#include <fstream>
#include <codecvt>
// #include <locale>

#define boxITEM 0
#define boxCONTENT 1
#define boxALL 2
//const int boxALL = 2;
//const int boxITEM = 0;
//const int boxCONTENT = 1;
#define ENG 0  //english
#define CHI_SIM 1  //chinese simple
#define CHI_TRA 2  //chinese traditional
#define ENG_CHI_SIM 3
#define ENG_CHI_TRA 4
#define CHI_SIM_TRA 5
//const int ENG = 0;
//const int CHI_SIM = 1;
//const int CHI_TRA = 2;

class Sheet
{
private:
    std::string item;  //the head of the content
	string content;  //the content need to be recogonised
	int row, col;   // the position in the image
	double height, width[3];// the height and width compared to the biggest box
	vector<cv::Point> itemSquare, contSquare;  //the position of the item or content
	int Character;// tht flag that uses tesseracr.exe "Eng","chi_sim" or "chi_tra"

public:
	int Height, Width[2];  // the height and width in an image
	vector<cv::Point> Center;// the center of a square
	int Area[2]; //the area of a square
	//int Charac;// tht flag that uses tesseracr.exe "Eng","chi_sim" or "chi_tra"
	//Position posSheet;  //the position of the item or content
	Sheet()
	{
		for (int i = 0; i <= boxALL; i++)
		{
			width[i] = 0.0;
			
		}	
		height= 0.0;
		row = 0;
		col = 0;
		item = "blank";
		content = "blank";
		Center.push_back(cv::Point(-1, -1));
		Center.push_back(cv::Point(-1, -1));
		//itemSquare.push_back(cv::Point(-1, -1));
	}

	void setSheet(std::string &sItem, string &sCont, int &srow, int &scol, int sch)
	{
		item = sItem;
		content = sCont;
		row = srow;
		col = scol;
		Character = sch;
	}

	void setCont(string cont)
	{
		content = cont;		
	}

	int getRow()
	{
		return row;
	}

	int getColum()
	{
		return col;
	}

	//return the ith number
	// the width compared to the biggest box
	double getWidth(int i)
	{
		return width[i];
	}
	// the height compared to the biggest box
	double getHeight()
	{
		return height;
	}

	// set the width and height
	void setWidHeig(double swid[], double shei)
	{
		for (int i = 0; i < boxALL; i++)
		{
			width[i] = swid[i];
		}
		width[boxALL] = width[boxCONTENT] + width[boxITEM];
		height = shei;
	}
	//get the square of "item"
	vector<cv::Point> getItemSquare()
	{
		return itemSquare;
	}
	//get the point that ranks i in the square
	cv::Point getItemSquare(int i)
	{
		if (4 > i)
		{
			return itemSquare[i];
		}		
	}

	//get the square of "content"
	vector<cv::Point> getContSquare()
	{
		return contSquare;
	}
	//get the point that ranks i in the square
	cv::Point getContSquare(int i)
	{
		if (4 > i)
		{
			return contSquare[i];
		}
		return cv::Point(-1,-1);
	}

	vector<cv::Point> getSquare()
	{
		return itemSquare;
	}

	string getItem()
	{
		return item;
	}

	string getContent()
	{
		return content;
	}

	int getCharacter()
	{
		return Character;
	}

	bool Empty()
	{
		if (item == "Empty")
			return true;
		else
			return false;
	}

	/*  LUpoint: the left-up point of a certain square, 
		lenRow: the width of the biggest box
		lenCol:  the height of biggest box
		i: the ith square
	*/
	void creatSquare(cv::Point LUpoint, int lenRow, int lenCol,int i)
	{
		int sqWid, sqHei;
		//width[i] = width[i] * lenRow;
		sqWid = (int)(width[i] * lenRow+0.5);
		//height = height*lenCol;  //round
		sqHei = (int)(height*lenCol + 0.5);

		Height = sqHei;
		cv::Point temP, sumP;
		//anticlockwise
		sumP = LUpoint;
		if (i == boxITEM)
		{
			
			Width[i] = sqWid;
			Area[i] = Width[i] * Height;//area of the box

			itemSquare.push_back(LUpoint);
			temP = LUpoint + cv::Point(0, sqHei);
			sumP = sumP + temP;
			itemSquare.push_back(temP);
			temP = LUpoint + cv::Point(sqWid, sqHei);
			sumP = sumP + temP;
			itemSquare.push_back(temP);
			temP = LUpoint + cv::Point(sqWid, 0);
			sumP = sumP + temP;
			itemSquare.push_back(temP);
		}
		
		if(i==boxCONTENT)
		{
			Width[i] = sqWid;
			Area[i] = Width[i] * Height; //area of the box in an image

			contSquare.push_back(LUpoint);
			temP = LUpoint + cv::Point(0, sqHei);
			sumP = sumP + temP;
			contSquare.push_back(temP);
			temP = LUpoint + cv::Point(sqWid, sqHei);
			sumP = sumP + temP;
			contSquare.push_back(temP);
			temP = LUpoint + cv::Point(sqWid, 0);
			sumP = sumP + temP;
			contSquare.push_back(temP);			
		}
		Center[i]=(sumP / 4);

	}



};

// creat a sheet
vector<vector<Sheet>> creatSheet();
void SheetImage(vector<vector<Sheet>>& Bill, vector<cv::Point> Box);
//find four points in order to do perspective transformation
void ExtractBill(const cv::Mat& srcImage, cv::Mat& dstImage, vector<Position>& SortSquare);
/* save the "content" of a bill
and put them into "tesseract.exe" to be recognised
Bill: the bill correspond to the input image
image: the image which has been done perspective transform
*/
// void RecognizeContent(const cv::Mat& image, vector<vector<Sheet>>& Bill);
//Read Unicode UTF-8 file into wstring
std::wstring readFile(const char* filename);
