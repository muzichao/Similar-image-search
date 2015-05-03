#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "GetFilesPath.h"
#include "ImageHash.h"
#include "BuildDatabaseOfImageFinger.h"
#include "SearchImage.h"

using namespace std;
using namespace cv;

int main()
{
	string filePath("D:/Document/vidpic/pictures/101_ObjectCategories"); // 文件目录
	string fileType("jpg"); // 文件类型
	
	vector<string> files; // 文件路径
	GetFiles(filePath, fileType, files); // 读取文件路径

	unordered_multimap<uint64_t, string> hashDatabase; // 图像指纹库
	BuildDatabaseOfImageFinger(files, hashDatabase); // 建立图像指纹库

	//int multiResult = 0;
	//for (int i = 0; i < files.size(); i++)
	//{
	//	cout << i << endl;
	//	string filePaths = files[i];
	//	Mat image = imread(filePaths);
	//	vector<string> searchResult; // 搜索结果
	//	SearchImage(image, hashDatabase, searchResult); // 在数据库中搜索图像
	//	if (searchResult.size() > 1)
	//		multiResult++;
	//}
	//cout << multiResult << endl;

	// 待查询图像
	string filePaths = filePath + "/Leopards/image_0008." + fileType;
	cout << filePaths.c_str() << endl;
	Mat image = imread(filePaths);
	namedWindow("Figure");
	imshow("Figure", image);
	waitKey();

	vector<string> searchResult; // 搜索结果
	SearchImage(image, hashDatabase, searchResult); // 在数据库中搜索图像
	for (int i = 0; i < searchResult.size(); i++)
	{
		string findImagePath = searchResult[i];
		cout << findImagePath.c_str() << endl;
	}

	return 0;
}