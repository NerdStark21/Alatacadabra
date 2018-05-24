function If = handFilter(I)

Ilab = rgb2lab(I);

Ibw = imbinarize(Ilab(:, :, 2), multithresh(Ilab(:, :, 2), 1));

[m, n, ~] = size(I);
Imark = zeros(m, n);
Imark(round(4 * m / 10) : round(6 * m / 10), round(4 * n / 10) : round(6 * n / 10)) = 1;
Imark = imbinarize(Imark .* Ibw);

Irec = imreconstruct(Imark, Ibw);

If = imfill(Irec, 'holes');

end