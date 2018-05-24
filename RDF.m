clear;
close all;
clc;

%28052536_1708293429218686_767694331_n
%28000789_1708293702551992_1264660463_n
%28001319_1708293325885363_1585034742_n
%28080124_1708293462552016_10489864_o
%28080637_1708293365885359_1365892258_o

database_dir = '../images_main/';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames, 1);
I = double(imread(sprintf('%s%s', database_dir, fnames(1).name))) / 255;

figure;
imshow(I, []);

Ilab = rgb2lab(I);

figure;
imshow(Ilab(:, :, 2), []);

Ibw = imbinarize(Ilab(:, :, 2), multithresh(Ilab(:, :, 2), 1));

figure;
imshow(Ibw);

[m, n, ~] = size(I);
Imark = zeros(m, n);
Imark(round(4 * m / 10) : round(6 * m / 10), round(4 * n / 10) : round(6 * n / 10)) = 1;
Imark = imbinarize(Imark .* Ibw);

figure;
imshow(Imark, []);

Irec = imreconstruct(Imark, Ibw);

figure;
imshow(Irec, []);

Iseg = imfill(Irec, 'holes');

figure;
imshow(I .* Iseg, []);