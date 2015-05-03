function allFiles = FileInAllOfSubdir(filePath, fileType)
% 作用：读取指定文件夹下的所有子文件夹内指定类型的文件
% 输入：filePath 字符串 文件路径
% 输入：fileType 字符串 文件类型
% 输出：allFiles 字符串数组 子文件路径+文件名

allFiles = cell(0);
subdir = dir(filePath); % 读取 filePath 下的所有文件和文件夹
isSubdir = [subdir(:).isdir]; % 检测是否是文件夹
subFoldNames = {subdir(isSubdir).name}'; % 删除非文件夹  
subFoldNames(ismember(subFoldNames, {'.','..'})) = []; % 删除 '.' 和 '..' 子目录

for i = 1:size(subFoldNames, 1) % 变量所有子目录
    subdirName = fullfile(filePath, subFoldNames(i)); % 路径
    allFilesOfSubdir = dir([subdirName{1}, '\*.', fileType]); % 当前子目录所有指定类型文件
    addSubdirName = repmat(strcat(subFoldNames(i), {'\'}), length(allFilesOfSubdir), 1); % 创建子目录路径
    allFiles = cat(1, allFiles, strcat(addSubdirName, cat(1, {}, allFilesOfSubdir.name))); % 为找到的文件添加子目录路径
end