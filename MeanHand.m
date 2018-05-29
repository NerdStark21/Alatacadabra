clear;
close all;
clc;

database_dir='../images_main';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

somme = 0;

for i = 1:1
    I = double(imread(sprintf('%s/%s', database_dir, fnames(i).name))) / 255;
    [m, n, ~] = size(I);
    I = I(1:10:m, 1:10:n, :);
    Iycbcr = rgb2ycbcr(I);
    
    M = handFilter(I);
    
    somme = somme + mean2Mask(Iycbcr, imerode(M, strel('disk', 10)));
    
end

display(somme / 1);
    