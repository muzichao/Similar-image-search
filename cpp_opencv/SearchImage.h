#ifndef SEARCHIMAGE_H
#define SEARCHIMAGE_H

#include <iostream>
#include <unordered_map>
#include <opencv2\highgui\highgui.hpp>
#include "ImageHash.h"

#ifndef uint64_t
typedef unsigned long long int uint64_t; // 宏定义
#endif // uint64_t

#ifndef hashMap
typedef std::unordered_multimap<uint64_t, std::string> hashMap; // 宏定义
#endif // hashMap

/*
* 功能：搜索指纹库
* 输入：image cv::Mat 待搜索图像
* 输出：hashDatabase unordered_multimap<uint64_t, string> 建立的指纹库
* 输出：searchResult vector<string> 查找到的指纹路径
*/
void SearchImage(cv::Mat, hashMap, std::vector<std::string>&);

#endif // SEARCHIMAGE_H