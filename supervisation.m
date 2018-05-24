clear;
close all;
clc;

database_dir='images_main';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

coul_main = zeros(3, 10);

for i = 1:min(10, num_files)
    I = imread(sprintf('images_main/%s', fnames(i).name));
    imycbcr = rgb2ycbcr(I);
    figure;
    imshow(imycbcr,[]);
    
    I_centre = SelectPixelsCentre(sprintf('images_main/%s', fnames(i).name), 0.2);
    
    imycbcr_centre = rgb2ycbcr(I_centre);
    figure;
    imshow(imycbcr_centre,[]);
    [Yc,Cbc,Crc] = AttributMoyenneMarginale(imycbcr_centre)
    coul_main(:,i) = [Yc,Cbc,Crc];
    [Y,Cb,Cr] = AttributMoyenneMarginale(imycbcr)
    
end

coul_main

