clear;
close all;
clc;

database_dir = '../images_main';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

pixels = [];

for i = 1:20
    I = double(imread(sprintf('%s/%s', database_dir, fnames(i).name))) / 255;
    [m, n, ~] = size(I);
    I = I(1:10:m, 1:10:n, :);
    Iycbcr = rgb2ycbcr(I);
    
    M = handFilter(I);
    
    imshow(M);
    
    % Pour chaque image on ajoute les pixels donnés par pixels2Mask
    pixels = [pixels, pixels2Mask(Iycbcr, imerode(M, strel('disk', 10)))];
    
end

pixels = pixels * 255;

moy = mean(pixels, 2);
ect = std(pixels, 0, 2);

disp(moy)
disp(ect)