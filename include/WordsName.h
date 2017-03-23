#pragma once

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <windows.h>

//using namespace cv;
using namespace std;

/*get file names */
vector<string> getAllFilesNamesWithinFolder(string folder);
/* UTF_8 to unicode */
wchar_t * Utf_8ToUnicode(char* szU8);
/*unicode to ansi*/
char* UnicodeToAnsi(const wchar_t* szStr);
/*    */
string process(char* outText, int cnt);