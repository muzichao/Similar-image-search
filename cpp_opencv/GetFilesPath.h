#ifndef GETFILESPATH_h
#define GETFILESPATH_h

#include <io.h>
#include <iostream>
#include <vector>

/*
* 功能：读取指定目录下（包括子目录）的所有文件，并保存对应的文件路径
* 输入：filePath string 指定的目录
* 输入：fileType string 文件类型
* 输出：files vector<string> 保存所有文件路径和文件名
*/
void GetFiles(std::string, std::string, std::vector<std::string>&);

#endif // GETFILESPATH_h