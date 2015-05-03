#include "GetFilesPath.h"

/*
* 功能：判断当前文件是否是指定的文件类型
* 输入：fileName string 文件名
* 输入：fileType string 文件类型
* 输出：true/false bool  
*/
bool IsSpecifiedFile(std::string fileName, std::string fileType)
{
	// 如果输入的文件名的长度小于等于文件类型的长度，返回 false
	if (fileName.size() <= fileType.size())
		return false;
	// 如果输入的文件类型为空，返回 true
	if (fileType.empty())
		return true;

	std::string getFileType = fileName.erase(0, fileName.size() - fileType.size()); // 取文件名的后几位

	return getFileType == fileType ? true : false;
}

/*
* io.h 头文件说明
* _finddata_t(io.h) 是用来存储文件各种信息的结构体
*	其中，unsigned attrib：文件属性的存储位置。它存储一个 unsigned 单元，用于表示文件的属性
*		_A_SUBDIR 表示是文件夹
*	char name[_MAX_FNAME]：文件的文件名。这里的 _MAX_FNAME 表示的是文件名的最大长度。
* _findfirst(io.h) 搜索与指定的文件名称匹配的第一个实例，若成功则返回第一个实例的句柄，否则返回-1L
* _findnext(io.h) 搜索与提供的文件名称匹配的下一个实例，若成功则返回0，否则返回－1
*/

/*
* 功能：读取指定目录下（包括子目录）的所有文件，并保存对应的文件路径
* 输入：filePath string 指定的目录
* 输入：fileType string 文件类型
* 输出：files vector<string> 保存所有文件路径和文件名
*/
void GetFiles(std::string filePath, std::string fileType, std::vector<std::string>& files)
{
	struct _finddata_t fileinfo; // 
	std::string currentPath; // 当前路径
	long   hFile = 0;//文件句柄

	if ((hFile = _findfirst(currentPath.assign(filePath).append("/*").c_str(), &fileinfo)) !=  -1)
	{
		while (_findnext(hFile, &fileinfo)  == 0)
		{
			if (fileinfo.attrib &  _A_SUBDIR) // _A_SUBDIR 表示是文件夹，遍历该文件夹
			{
				if (strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0)
				{
					GetFiles(currentPath.assign(filePath).append("/").append(fileinfo.name), fileType, files);
				}
			}
			else // 如果当前文件不是文件夹，则保存当前文件
			{
				if (IsSpecifiedFile(fileinfo.name, fileType))
				{
					files.push_back(currentPath.assign(filePath).append("/").append(fileinfo.name));
				}
			}
		}
		_findclose(hFile);
	}
}