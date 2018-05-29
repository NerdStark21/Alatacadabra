function pixels = pixels2Mask(I, M)

% Renvoie l'ensemble des pixels d'une image qui sont à 1 dans le masque. Le
% masque et l'image sont donc de même taille.

% input
% I : image d'entrée
% M : masque d'entrée

% output
% pixels : ensemble des pixels de I qui sont à 1 dans M

pixels = zeros(3, sum(sum(M)));
indicePixels = 1;

[m, n, ~] = size(I);

for i = 1:m
    for j = 1:n
        if M(i, j) == 1
            pixels(1, indicePixels) = I(i, j, 1);
            pixels(2, indicePixels) = I(i, j, 2);
            pixels(3, indicePixels) = I(i, j, 3);
            indicePixels = indicePixels + 1;
        end
    end
end

end