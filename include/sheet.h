#pragma once
#include "mySquare.h"
#include "baseDefine.h"
#include <string>

#include <stdio.h>
#include <stdlib.h>


#include <sstream>
#include <fstream>
#include <codecvt>

#define MAXBOXWIDTH 1188
#define MAXBOXHEIGHT 772

//Point2idf: Point,Point2f,Point2d
template<typename Point2idf=cv::Point> class WordBox : public BaseBox<Point2idf>
{
private:
	string words;  //words in the box
	//the head of the content
	//string content;  //the content need to be recogonised
	int row, col;   // the position in the image
	int flagItemCont; //the flag that differentiates "item" and "content"
	//double height, width[3];// the height and width compared to the biggest box
	//vector<Point2idf> itemSquare, contSquare;  //the position of the item or content
	int Character;// the flag that uses tesseracr "Eng","chi_sim" or "chi_tra"

public:
	WordBox()
	{
		words = "Empty";
		row = 0;
		col = 0;
		flagItemCont = -1;
	}
	//set words in the box, row and column of the box,
	//sch means "Eng","chi_sim" or "chi_tra"
	//ItemCont: item or content
	void setWordBox(string sWord, int srow, int scol, int sch, int ItemCont)
	{
	//	item = sItem;
	//	content = sCont;
		words = sWord;
		row = srow;
		col = scol;
		Character = sch;
		flagItemCont = ItemCont;
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

	string getWords()
	{
		return words;
	}

	int getCharacter()
	{
		return Character;
	}

	int getItemCont()
	{
		return flagItemCont;
	}

	bool Empty()
	{
		if (words == "Empty")
			return true;
		else
			return false;
	}	

};



// creat a sheet
vector<vector<WordBox<BOX_POINT>>> NormSheet();
void SheetImage(vector<vector<WordBox<BOX_POINT>>>& normSheet, vector<vector<WordBox<Point>>>& Sheet, vector<cv::Point> Box);
/*find four points in order to do perspective transformation
1:found  ; -1:not found  
*/
int ExtractBill(const cv::Mat& srcImage, cv::Mat& perspImage, vector<BaseBox<>>& SortSquare, vector<cv::Point> &foundSquare);
/* save the "content" of a bill
and put them into "tesseract.exe" to be recognised
Bill: the bill correspond to the input image
image: the image which has been done perspective transform
*/
//void RecognizeContent(const cv::Mat& image, vector<vector<WordBox<>>>& Bill);
//Read Unicode UTF-8 file into wstring
//std::wstring readFile(const char* filename);
