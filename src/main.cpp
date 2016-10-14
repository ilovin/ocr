#include <tesseract/baseapi.h>

#include <leptonica/allheaders.h>
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <codecvt>

#include <experimental/filesystem>
#include <mutex>
#include <thread>

#include "sheet.h"
#include "Squares.h"
#include "blockingQueue.h"


using namespace cv;
using namespace std;
namespace fs=std::experimental::filesystem;

#define nr_threads 10
BlockingQueue<string> bQ;

vector<vector<Sheet> > bill; 
int readFileName(std::string &path);
void findRect(Mat &src,Mat &perspImage,std::vector<std::vector<Sheet> > &bill);
void idChar(Mat src,std::vector<std::vector<Sheet> > &bill,std::string &filename);
// void workBuffer(vector<vector<Sheet> > bill,int tid);
void workBuffer(int tid);

int main()
{
    std::string path="./img"; 
    if(readFileName(path)){
        std::cout<<"cannot read file"<<endl;
        return -1;
    }
    // std::string str ="./img/4.jpg";
    // const char* filename = str.c_str();
    // Mat img = cv::imread(filename,1);
    // if(img.empty())
    // {
		// std::cout<<"Can't load img"<<std::endl;
		// return -1;
    // }
    bill= creatSheet();
    vector<thread> th;
    for(int i=0;i<nr_threads;i++)
        th.push_back(std::thread(workBuffer,i));


    for(auto &t : th)
        t.join();
    // findRect(img,perspImage,bill);
    // // MyImageShow(perspImage);
    // idChar(perspImage,bill,str);


    // pixDestroy(&image);
    // imshow(str,img);
    // waitKey(0);


    return 0;

}

// void workBuffer(vector<vector<Sheet> > bill,int tid){
void workBuffer(int tid){
    Mat src;
    Mat perspImage;
    std::string fName;

    while(bQ.size()){
        if(!bQ.tryPop(fName,std::chrono::milliseconds(10))) continue;
        else{
            cout<<"capture by tid "<<tid<<": "<<fName<<endl;
            src=imread(fName,1);
            if(src.empty()){
                cout<<fName<<" is not a img"<<endl;
                continue;
            }
            findRect(src,perspImage,bill);
             // MyImageShow(perspImage);
            idChar(perspImage,bill,fName);
        }
    }

}

int readFileName(std::string &path){
    if(fs::path(path).empty()){
        std::cout<<"the folder is empty"<<endl;
        return -1;
    }
    for(auto& dirEntry : fs::recursive_directory_iterator(path))
        bQ.push(dirEntry.path().string());
    return 0;
}

void idChar(Mat src,std::vector<std::vector<Sheet> > &bill,std::string &filename){
    char *outText;
    std::ofstream f;
    std::string fName = filename.substr(0,filename.rfind('.'))+".txt";
    f.open(fName,std::ofstream::out| std::ofstream::trunc);
    std::string utf8=u8"字符识别程序样例\n";
    // f<<utf8;
    cout<<utf8;

    tesseract::TessBaseAPI *apiEngAndSim = new tesseract::TessBaseAPI();
    tesseract::TessBaseAPI *apiTra = new tesseract::TessBaseAPI();
    tesseract::TessBaseAPI *apiEng = new tesseract::TessBaseAPI();
    tesseract::TessBaseAPI *apiSim = new tesseract::TessBaseAPI();

    // Initialize tesseract-ocr with English, without specifying tessdata path

    if (apiEngAndSim->Init(NULL, "eng+chi_sim")||apiEng->Init(NULL,"eng")
		    ||apiTra->Init(NULL,"chi_tra")
		    ||apiSim->Init(NULL,"chi_sim")) {

	fprintf(stderr, "Could not initialize tesseract.\n");
	exit(1);
    }

    //tick tock
    double t  = static_cast<double>(getTickCount());

    // Open input image with leptonica library
    
    //std::string str ="/home/mlab/work/tesseract/testing/phototest.tif";
    apiEngAndSim->SetImage((uchar*)src.data,src.size().width,src.size().height,
		    src.channels(),src.step1());
    apiTra->SetImage((uchar*)src.data,src.size().width,src.size().height,
		    src.channels(),src.step1());
    apiEng->SetImage((uchar*)src.data,src.size().width,src.size().height,
		    src.channels(),src.step1());
    apiSim->SetImage((uchar*)src.data,src.size().width,src.size().height,
		    src.channels(),src.step1());

    int rectWid, rectHei;
    cv::Rect rect;
    for(auto bi:bill)
    {
	    for(auto b:bi)
	    {
                if(b.Empty()) continue;
		std::cout<<b.getItem()<<": "<<std::endl;
       		rectWid = b.getContSquare()[2].x - b.getContSquare()[1].x;
		rectHei = b.getContSquare()[1].y - b.getContSquare()[0].y;
		rect = cv::Rect(b.getContSquare()[0].x, 
				b.getContSquare()[0].y,rectWid,rectHei);
		switch(b.getCharacter()){
			case ENG:
    				apiEng->SetRectangle(rect.tl().x,rect.tl().y
						,rect.width,rect.height);
        			outText = apiEng->GetUTF8Text();
				// std::cout<<b.getItem()<<std::endl;
				// std::cout<<outText<<std::endl;
			break;
			case ENG_CHI_SIM:
    				apiEngAndSim->SetRectangle(rect.tl().x,rect.tl().y
						,rect.width,rect.height);
        			outText = apiEngAndSim->GetUTF8Text();
				// std::cout<<b.getItem()<<std::endl;
				// std::cout<<outText<<std::endl;
			break;
			case CHI_SIM:
    				apiSim->SetRectangle(rect.tl().x,rect.tl().y
						,rect.width,rect.height);
        			outText = apiSim->GetUTF8Text();
				// std::cout<<b.getItem()<<std::endl;
				// std::cout<<outText<<std::endl;
			break;
			case CHI_TRA:
    				apiTra->SetRectangle(rect.tl().x,rect.tl().y
						,rect.width,rect.height);
        			outText = apiTra->GetUTF8Text();
				// std::cout<<b.getItem()<<std::endl;
				// std::cout<<outText<<std::endl;
			break;
			default:
				cout<<"cannot find appropriate charactor"<<std::endl;
			break;
		}

                // printf("OCR output:\n%s", outText);
             std::cout<<outText<<std::endl;
             f<<b.getItem()<<endl;
             f<<outText;
	    }

    }
    f.close();
    // cv::Rect rect = rectBill[0];

    // api->SetRectangle(0,0,640,190);
    // outText = api->GetUTF8Text();
    // printf("OCR output:\n%s", outText);

    t = (static_cast<double>(getTickCount())-t)/getTickFrequency();
    std::cout<<"consume time: "<<t<<std::endl;



    // Destroy used object and release memory

    apiEng->End();
    apiEngAndSim->End();
    apiTra->End();
    apiSim->End();

    delete [] outText;

}

void findRect(Mat &src,Mat &perspImage,std::vector<std::vector<Sheet> > &bill){
	cv::Mat GausImage;
	std::vector<std::vector<cv::Point> >squares;
	GaussianBlur(src,GausImage,cv::Size(9,9),2);
	findSquares(GausImage,squares);

	std::vector<Position> pos;
	pos = SortByArea(squares);
	perspImage = src.clone();
	ExtractBill(src,perspImage,pos);

	vector<cv::Point> box = {cv::Point(0,0), cv::Point(0,perspImage.rows ),
		cv::Point(perspImage.cols,perspImage.rows),
		cv::Point(perspImage.cols,0)};
	SheetImage(bill,box);
}

