function stdycbcr = std2Mask(Iycbcr, M, mean2)

somme = [0, 0, 0];

pixels = zeros(sum(sum(M)));

[m, n, ~] = size(Iycbcr);

for i = 1:m
    for j = 1:n
        if M(i, j) == 1
            somme(1) = somme(1) + Iycbcr(i, j, 1);
            somme(2) = somme(2) + Iycbcr(i, j, 2);
            somme(3) = somme(3) + Iycbcr(i, j, 3);
        end
    end
end

ycbcr = somme / sum(sum(M));

end