#ifndef IMAGEHASH_H
#define IMAGEHASH_H

#ifndef uint64_t
typedef unsigned long long int uint64_t; // 宏定义
#endif // uint64_t

#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

/*
* 功能：利用 hash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImageHash(cv::Mat);

/*
* 功能：利用 phash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImagePHash(cv::Mat);

/*
* 功能：利用 dhash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImageDHash(cv::Mat);

#endif // IMAGEHASH_H