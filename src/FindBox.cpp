#include "baseBox.h"
#include "baseDefine.h"
#include "DelRedSeal.h"
#include "mySquare.h"
#include "sheet.h"
#include "Squares.h"
#include "directory.h"


namespace fs = std::experimental::filesystem;

int main()
{
	Mat srcImg;
	fs::path srcDirectory = "E:\\receiptSelected\\",
		desDirectory ="E:\\receiptSelected\\";
	vector<fs::path> fileList;
	int isGetFileSuccess;
	isGetFileSuccess = getImgList(srcDirectory, fileList);
	std::string fn;

	//static const char* names[] = { "self2.jpg",0 }; //"jie.jpg", "1.jpg","3.jpg",
																	  //help();
																	  //cv::namedWindow(wndname, 1);
	vector<vector<cv::Point> > squares, squares2;
	vector<vector<WordBox<BOX_POINT>>> normbill = NormSheet();
	vector<vector<WordBox<>>> bill;
    //locale::global(locale("chs"));
	//wcout.imbue(locale("chs")); 

	//myfile.close();

	//for (int i = 0; names[i] != 0; i++)
	//{

	
	int foundFlag;

	if (!isGetFileSuccess)
	{
		for (fs::path fileName : fileList)
		{
			foundFlag = -1;
			cv::Mat GausImage;
			vector<BaseBox<>> pos;
			vector<cv::Point> foundSquare(4), perspBox;

			srcImg = imread(fileName.string(), 1);
			if (!srcImg.data) { printf("Oh£¨no£¨∂¡»°Image¥ÌŒÛ~£°\n"); return false; }

			/*Mat temImage;
			GaussianBlur(srcImg, srcImg, Size(9, 9), 1.5);
			cvtColor(srcImg, temImage, CV_BGR2GRAY);
			equalizeHist(temImage, temImage);
			cvtColor(temImage, srcImg, CV_GRAY2RGB);*/

			//MyImgShow("pic", srcImg);
			
			GaussianBlur(srcImg, GausImage, cv::Size(9, 9), 2);


			//MyImageShow(srcImg);
			//waitKey();
			//int kp = srcImg.channels();
			//find squares
			findSquares(GausImage, squares);
			/*drawSquares(GausImage, squares);
			cvWaitKey();*/

			
			pos = SortByArea(squares);
			cv::Mat perspImage = srcImg.clone();
			
			//do perspective transform
			foundFlag=ExtractBill(srcImg, perspImage, pos,foundSquare);

			//copy the picure and create a new text
			//if (foundFlag == 1)//find the biggest box
			//{
			//	CopyAndCreateFile(fileName,desDirectory, foundSquare);

			//}

			//double angle = FindAngle(srcImg, pos);
			//cv::Mat adImage = AdjustImage(srcImg, pos);
			//cv::Mat billImg = adImage;


			/**/
			//show images
			//vector<cv::Point> box = pos[0].getSquare();
			vector<cv::Point> box = { cv::Point(0,0), cv::Point(0,perspImage.rows),
				cv::Point(perspImage.cols ,perspImage.rows), cv::Point(perspImage.cols,0) };//anticlockwise

																							//vector<vector<cv::Point> > squareBill;
			vector<cv::Rect> rectBill; //rectangle of opencv
			cv::Rect rect;
			normbill.clear();
			normbill = NormSheet();//the original bill
			SheetImage(normbill, bill, box); //the bill correspond to the input srcImg
											 // get every square
											 /*squareBill.clear();
											 for (int bi = 0; bi < (int)bill.size()-1; bi++)
											 for (int bj = 0; bj < (int)bill[bi].size(); bj++)
											 {
											 squareBill.push_back(bill[bi][bj].getItemSquare());
											 squareBill.push_back(bill[bi][bj].getContSquare());
											 }*/
			std::vector< std::vector<cv::Point>> dSqu;
											 //get rectangle of content
			rectBill.clear();
			int rectWid, rectHei;
			for (int bi = 0; bi < (int)bill.size() - 1; bi++)
				for (int bj = 0; bj < (int)bill[bi].size(); bj++)
				{
					rectWid = bill[bi][bj].getWidth();
					rectHei = bill[bi][bj].getHeight();
					rect = cv::Rect(bill[bi][bj].getTopLeft().x, bill[bi][bj].getTopLeft().y, rectWid, rectHei);
					rectBill.push_back(rect);
					dSqu.push_back(bill[bi][bj].getSquare());
				}
			drawSquares(perspImage, dSqu);
			cvWaitKey();
			/**/


			//run tesseract.exe
			//RecognizeContent(perspImage, bill);


			//TxtFile = readFile();
			//MyImageShow( srcImg);
			//drawSquares(adImage, squareBill);
			// drawSquares(perspImage, squareBill);
			//imshow("dst", dstImage);
			//MyImgShow("persp", perspImage);
			//printf("Please press any key...\n");
			//cin.get();
			//cvWaitKey();


			//MergeSquare(srcImg, pos);
			//double angle2 = FindAngle(srcImg, pos);
			//MyImageShow(srcImg);
			//waitKey();

			/*int Nump = (int) pos.size();
			squares2.clear();
			for (int nk = 0; nk < Nump; nk++)  //Nump
			{
			squares2.push_back(pos[nk].getSquare());
			}

			drawSquares(srcImg, squares2);*/


			//int c = cv::waitKey();
			//if ((char)c == 27)
			//break;
		}

	}

	return 0;



}


