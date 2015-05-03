% 以图搜图
% 基于hash指纹
% 比较汉明距离
% 2015 4 30
% by lichao

clc
clear all
close all

%% 路径
addpath('.\codes\')
addpath('.\data\')
filePath = 'D:\Document\vidpic\pictures\101_ObjectCategories\'; % 文件目录
fileType = 'jpg'; % 文件类型

%% 提取路径下的文件
% 存在则读入，否则生成，避免重复计算
if(~exist('allFiles.mat', 'file'))
    allFiles = FileInAllOfSubdir(filePath, fileType); % 读取指定目录下所有指定类型的文件
    save ('.\data\allFiles.mat', 'allFiles')
else
    load allFiles
end

%% 分别计算每一幅图像的哈希值
% 存在则读入，否则生成，避免重复计算
if(~exist('hashFinger.mat', 'file'))
    hashFinger = cell(size(allFiles, 1), 1);
    for i = 1:size(allFiles, 1)
        image = imread(char(strcat(filePath, allFiles(i))));
        hashFinger(i) = {ImageHash(image)};
    end
    save ('.\data\hashFinger.mat', 'hashFinger')
else
    load hashFinger
end

%% 测试效果

searchImageIndex = randi([1, size(allFiles, 1)]);
imageSearch = imread(char(strcat(filePath, allFiles(searchImageIndex))));
hashValue = ImageHash(imageSearch);
resultImageIndex = SearchImage(hashFinger, hashValue);




