clear;
close all;
clc;

database_dir = '../images_fond';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

pixels = [];

for i = 1:19
    I = double(imread(sprintf('%s/%s', database_dir, fnames(i).name))) / 255;
    [m, n, ~] = size(I);
    if i == 19
        I = I(1:4:m, 1:4:n, :);
    else
        I = I(1:10:m, 1:10:n, :);
    end
    
    Iycbcr = rgb2ycbcr(I);
    [m, n, ~] = size(Iycbcr);
    imshow(Iycbcr);
    
    % Pour chaque image on ajoute les pixels donnés par pixels2Mask
    pixels = [pixels, pixels2Mask(Iycbcr, ones(m, n))];
    
end

pixels = pixels * 255;

moy = mean(pixels, 2);
ect = std(pixels, 0, 2);

disp(moy)
disp(ect)