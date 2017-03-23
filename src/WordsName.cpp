#include"WordsName.h"


/*get file names */
vector<string> getAllFilesNamesWithinFolder(string folder)
{
	vector<string> names;
	std::string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}

/* UTF_8 to unicode */
wchar_t * Utf_8ToUnicode(char* szU8)
{
	//UTF8 to Unicode
	//��������ֱ�Ӹ��ƹ���������룬��������ʱ�ᱨ���ʲ���16������ʽ

	//Ԥת�����õ�����ռ�Ĵ�С
	int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
	//����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
	wchar_t* wszString = new wchar_t[wcsLen + 1];
	//ת��
	::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
	//������'\0'
	wszString[wcsLen] = '\0';
	return wszString;
}

/*unicode to ansi*/
char* UnicodeToAnsi(const wchar_t* szStr)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];

	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);

	return pResult;

}



/*    */
string process(char* outText, int cnt)
{
	string result;
	wchar_t *tempchar;
	char * resulttemp;
	tempchar = Utf_8ToUnicode(outText);
	resulttemp = UnicodeToAnsi(tempchar);
	std::cout << resulttemp << std::endl;
	string output = resulttemp;
	for (int i = 0; i < output.length(); i++)
	{
		if (output[i] == '\n')
		{
			output[i] = '\r';
		}
	}
	for (int i = 0; i < output.length(); i++)
	{
		if (output[i] == '\"')
		{
			output.insert(i + 1, "\"");
			i++;
		}
	}
	if (cnt != 1)
	{
		result = ",\"" + output + "\"";
	}
	else
	{
		result = "\"" + output + "\"";
	}

	return result;
}