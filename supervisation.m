clear;
close all;
clc;

database_dir='images_main';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

coul_main = zeros(3, 1);

for i = 1:min(10, num_files)
    I = imread(sprintf('images_main/%s', fnames(i).name));
end