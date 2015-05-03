% 测试hash、phash、dhash的效果
% 运行此测试之前需先运行 mainHash.m、mainpHash.m、maindHash.m，产生相应指纹

clc
clear all
close all

%% 路径
addpath('.\codes\')
addpath('.\data\')
filePath = 'D:\Document\vidpic\pictures\101_ObjectCategories\'; % 文件目录
fileType = 'jpg'; % 文件类型

load allFiles

%% 产生随机测试值
% 存在则读入，否则生成，避免重复计算
testSize = 1000; % 测试图像个数
if(~exist('searchImageIndex.mat', 'file'))
    searchImageIndex = unique(sort(randi(size(allFiles, 1), [1, testSize]))); % 产生不重复随机数
    save('.\data\searchImageIndex.mat', 'searchImageIndex')
else
    load searchImageIndex
end

testSize = size(searchImageIndex, 2);
resultImageIndex = cell(testSize, 4);
resultImageIndex(:, 1) = num2cell(searchImageIndex'); % 第一列为搜索索引
%% hash

load hashFinger

for i = 1:testSize
    hashValue = ImageHash(imread(char(strcat(filePath, allFiles(searchImageIndex(i))))));
    resultImageIndex(i, 2) = {SearchImage(hashFinger, hashValue)}; % 第二列为 hash 结果
end

%% phash

load phashFinger

for i = 1:testSize
    hashValue = ImagePHash(imread(char(strcat(filePath, allFiles(searchImageIndex(i))))));
    resultImageIndex(i, 3) = {SearchImage(hashFinger, hashValue)}; % 第三列为 phash 结果
end
%% dhash

load dhashFinger

for i = 1:testSize
    hashValue = ImageDHash(imread(char(strcat(filePath, allFiles(searchImageIndex(i))))));
    resultImageIndex(i, 4) = {SearchImage(hashFinger, hashValue)}; % 第四列为 dhash 结果
end

%% 挑选不一样的搜索结果

differentSearchResult = cell(0);

for i = 1:testSize
   if(~(size(resultImageIndex{i, 2}, 1) == size(resultImageIndex{i, 3}, 1) && size(resultImageIndex{i, 2}, 1) == size(resultImageIndex{i, 4}, 1))) 
       differentSearchResult = cat(1, differentSearchResult, resultImageIndex(i, :));
   end
end