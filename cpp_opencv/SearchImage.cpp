#include "SearchImage.h"

/*
* 功能：搜索指纹库
* 输入：image cv::Mat 待搜索图像
* 输出：hashDatabase unordered_multimap<uint64_t, string> 建立的指纹库
* 输出：searchResult vector<string> 查找到的指纹路径
*/
void SearchImage(cv::Mat image, hashMap hashDatabase, std::vector<std::string>& searchResult)
{
	//uint64_t hash = ImageHash(image); // 计算待搜索图像的指纹
	uint64_t hash = ImagePHash(image); // 计算待搜索图像的指纹
	//uint64_t hash = ImageDHash(image); // 计算待搜索图像的指纹

	auto range = hashDatabase.equal_range(hash);
	for (hashMap::iterator it = range.first; it!=range.second; ++it)
	{
		searchResult.push_back(it->second);
	}
}