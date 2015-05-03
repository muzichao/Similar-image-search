#ifndef BUILDDATABASEOFIMAGEFINGER_H
#define BUILDDATABASEOFIMAGEFINGER_H

#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <unordered_map>
#include "ImageHash.h"

#ifndef uint64_t
typedef unsigned long long int uint64_t; // 宏定义
#endif // uint64_t

#ifndef hashMap
typedef std::unordered_multimap<uint64_t, std::string> hashMap;
#endif // hashMap

/*
* 功能：建立指纹库
* 输入：files vector<string> 图像库的文件路径和文件名
* 输出：hashDatabase unordered_multimap<uint64_t, string> 利用哈希表建立的指纹库
*/
void BuildDatabaseOfImageFinger(std::vector<std::string>, hashMap&);

#endif //BUILDDATABASEOFIMAGEFINGER_H