function ycbcr = mean2Mask(Iycbcr, M)

somme = [0, 0, 0];

pixels = zeros(3, sum(sum(M)));
indicePixels = 1;

[m, n, ~] = size(Iycbcr);

for i = 1:m
    for j = 1:n
        if M(i, j) == 1
            pixels(1, indicePixels) = Iycbcr(i, j, 1);
            pixels(2, indicePixels) = Iycbcr(i, j, 2);
            pixels(3, indicePixels) = Iycbcr(i, j, 3);
            somme(1) = somme(1) + Iycbcr(i, j, 1);
            somme(2) = somme(2) + Iycbcr(i, j, 2);
            somme(3) = somme(3) + Iycbcr(i, j, 3);
        end
    end
end

%ycbcr = somme / sum(sum(M));
disp(somme / sum(sum(M)));
disp(sum(sum(M)));
disp(size(pixels));

ycbcr = mean(pixels, 2);

end