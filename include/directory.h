#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <experimental\filesystem>
#include <iostream>
#include <set>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <fstream>
//using namespace std;

// default: no recursive
namespace fs = std::experimental::filesystem;
int getImgList(fs::path &path, std::vector<fs::path> &imgList, bool isRecursive=0);

/*
Copy the picture from filepath1 to filepath2,
And create a new ".txt" file in file2 with the same name of file in filepath1
srcPath: the source file path, e.g. "E://test//ex.jpg"
desPath: the destination file path without the file name, e.g."E://test//"
square: the four points of the biggest box
*/
void CopyAndCreateFile(fs::path &srcPath, fs::path &desPath, std::vector<cv::Point> &square);