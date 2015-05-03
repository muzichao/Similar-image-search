function resultImageIndex = SearchImage(hashFinger, hashValue)
% 根据哈希值搜索图像
% 输入：hashFinger cell数组 保存图像库
% 输入：hashValue 哈希值 待搜索图像的哈希值
% 输出：resultImageIndex 矩阵 匹配图像的索引
resultImageIndex = [];
threshold = 1; % 匹配阈值，哈希值中不匹配数小于等于阈值则认为相似
for i = 1:size(hashFinger, 1)
    if(sum(sum(bitxor(hashFinger{i, 1}, hashValue)))  <= threshold)
        resultImageIndex = cat(1, resultImageIndex, i);
    end
end
    