clear;
close all;
clc;

database_dir='../images_main';
fnames = dir(fullfile(database_dir, '*.jpg'));
num_files = size(fnames,1);

coul_main = zeros(3, 1);

for i = 1:min(10, num_files)
    I = imread(sprintf('%s/%s', database_dir, fnames(i).name));
end

