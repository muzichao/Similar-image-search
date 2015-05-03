#include "BuildDatabaseOfImageFinger.h"

/*
* 功能：建立指纹库
* 输入：files vector<string> 图像库的文件路径和文件名
* 输出：hashDatabase unordered_multimap<uint64_t, string> 利用哈希表建立的指纹库
*/
void BuildDatabaseOfImageFinger(std::vector<std::string> files, hashMap& hashDatabase)
{
	if (files.empty())
		return;

	for (int i = 0; i < files.size(); i++)
	{
		std::string filePath = files[i];
		cv::Mat image = cv::imread(filePath); // 读入图像
		//uint64_t hash = ImageHash(image); // 计算图像hash指纹
		uint64_t hash = ImagePHash(image); // 计算图像dhash指纹
		//uint64_t hash = ImageDHash(image); // 计算图像dhash指纹
		hashDatabase.insert(std::make_pair(hash, filePath)); // 指纹添加到数据库
	}
}