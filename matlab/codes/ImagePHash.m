function imageHashValue = ImagePHash(image)
% 计算图形的哈希值，返回一个64位字符串
% 输入：image 矩阵 输入图像
% 输出：imageHashValue 字符串 图像对应的哈希值

hashFingerSize = 8; % 决定哈希值的长度
dctSize = 32; % DCT 变换矩阵大小
if(size(image, 3) == 3)
    image = rgb2gray(image); % rgb转为灰度
end
image = dct2(double(imresize(image, [dctSize, dctSize]))); % 调整大小并进行DCT变换
image = image(1:hashFingerSize, 1:hashFingerSize); % 取左上的低频部分
image = log(abs(image)); % 取对数
imageHashValue = image(:) > mean(image(:)); % 计算哈希值