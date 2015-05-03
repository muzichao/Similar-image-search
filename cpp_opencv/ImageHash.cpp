#include "ImageHash.h"

/*
* 功能：利用 hash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImageHash(cv::Mat image)
{
	uint64_t hash = 0; // 用于保存hash值
	cv::Mat imageGray; // 转换后的灰度图像
	cv::Mat imageFinger; // 缩放后的8x8的指纹图像
	int fingerSize = 8; // 指纹图像的大小

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(fingerSize, fingerSize)); // 图像缩放
	imageFinger.convertTo(imageFinger, CV_32F); // 转换为浮点型
	cv::Scalar imageMean = cv::mean(imageFinger); // 求均值

	/* 计算图像哈希指纹，小于等于均值为0，大于为1 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > imageMean[0])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}

/*
* 功能：利用 phash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImagePHash(cv::Mat image)
{
	uint64_t hash = 0; // 用于保存hash值
	cv::Mat imageGray; // 转换后的灰度图像
	cv::Mat imageFinger; // 缩放后的8x8的指纹图像
	int fingerSize = 8; // 指纹图像的大小
	int dctSize = 32; // dct变换的尺寸大小

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(dctSize, dctSize)); // 图像缩放
	imageFinger.convertTo(imageFinger, CV_32F); // 转换为浮点型
	cv::dct(imageFinger, imageFinger); // 对缩放后的图像进行dct变换
	imageFinger = imageFinger(cv::Rect(0, 0, fingerSize, fingerSize)); // 取低频区域

	/* 对dct变换后的系数取对数 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			data[j] = logf(abs(data[j]));
		}
	}

	cv::Scalar imageMean = cv::mean(imageFinger); // 求均值

	/* 计算图像哈希指纹，小于等于均值为0，大于为1 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > imageMean[0])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}

/*
* 功能：利用 dhash 法计算图像指纹
* 输入：image cv::Mat 输入图像
* 输出：hash uint64_t 计算得到的指纹
*/
uint64_t ImageDHash(cv::Mat image)
{
	uint64_t hash = 0; // 用于保存hash值
	cv::Mat imageGray; // 转换后的灰度图像
	cv::Mat imageFinger; // 缩放后的8x8的指纹图像
	int fingerSize = 8; // 指纹图像的大小

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(fingerSize+1, fingerSize)); // 图像缩放

	/* 计算图像哈希指纹，对于前八列的点，如果某个点大于它右侧的点，则为1，否则为0 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > data[j+1])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}