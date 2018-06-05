clear;
close all;
clc;

I = double(imread('Alata1.jpg')) / 255;

imshow(I);

Itf = abs(fftshift(fft2(I)));

imshow(Itf);

imwrite(Itf, 'fftAlata1.png');

