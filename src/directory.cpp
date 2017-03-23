/* 
find all pictures in a directory
*/


#include "directory.h"

namespace fs = std::experimental::filesystem;
using namespace std;

std::string suffix[6] = { "jpg","png","jpeg","tif","gif","bmp" };
static std::set<std::string> suffixSet(suffix, suffix + sizeof(suffix) / sizeof(suffix[0]));

/*
path: the path of the pictures
imgList: the list of all the paths of pictures
isRecursive:  "0" :no recursion;

*/

int getImgList(fs::path &path, std::vector<fs::path> &imgList, bool isRecursive) {
	if (!fs::exists(path))
	{
		std::cerr << "cannot open the directory: " << path.string()<<endl;
		return -1;
	}

	if (isRecursive)// "0" :no recursion;  
	{
		for (auto &p:fs::recursive_directory_iterator(path))
		{
			string filePath = p.path().string();
			string suf = filePath.substr(filePath.rfind('.') + 1);
			transform(suf.begin(), suf.end(), suf.begin(), ::tolower);
			if (suffixSet.find(suf)!=suffixSet.end())
				imgList.push_back(filePath);
		}
	}
	else
	{
		for (auto &p : fs::directory_iterator(path)) {
			string filePath = p.path().string();
			string suf = filePath.substr(filePath.rfind('.') + 1);
			transform(suf.begin(), suf.end(), suf.begin(), ::tolower);
			if (suffixSet.find(suf)!=suffixSet.end())
				imgList.push_back(filePath);

		}
	}
	return 0;
}



/*
Copy the picture from filepath1 to filepath2, 
And create a new ".txt" file in file2 with the same name of file in filepath1
srcPath: the source file path, e.g. "E://test//ex.jpg"
desPath: the destination file path without the file name, e.g."E://test//"
square: the four points of the biggest box
*/
void CopyAndCreateFile(fs::path &srcPath, fs::path &desPath, std::vector<cv::Point> &square)
{
	string fname = srcPath.filename().string();
	string temfname = fname;
	fs::path desFile(desPath.string() + fname);
	fs::copy_file(srcPath, desFile, fs::copy_options::overwrite_existing);//copy pictures
	//create a new txt, writing four points 
	temfname.erase(temfname.rfind("."));// erase the suffix
	ofstream outxt(desPath.string() + temfname + ".txt", ios::out);//create or rewrite
	for (int i = 0; i < square.size(); i++)
	{
		outxt << square[i].x << "," << square[i].y << endl;
	}

}
