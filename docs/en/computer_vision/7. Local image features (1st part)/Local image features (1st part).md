# Local image features (1st part)

We load the images that we will use in the practical assignment.

```matlab
lena = imread("Imagenes\lena_color_512.tif");
mandril = imread("Imagenes\mandril_color.tif");
malla = imread("Imagenes\patron_malla.jpg");
textura = imread("Imagenes\astablet.tif");
chessboard = imread("Imagenes\chessboardpattern.jpg");
chessboard_inclinado = imread("Imagenes\esquinas_perspectiva.jpg");

malla = rgb2gray(malla);
chessboard_inclinado = rgb2gray(chessboard_inclinado);

montage({lena,mandril,malla,textura,chessboard,chessboard_inclinado})
```

![figure_0.png](P7_media/figure_0.png)
# Histogram-based features

Color histogram


First example: Lena image


We separate the image into the three color channels

```matlab
red = lena(:,:,1);
green = lena(:,:,2);
blue = lena(:,:,3);
```

And we obtain the histograms of each channel

```matlab
h_red = imhist(red);
h_green = imhist(green);
h_blue = imhist(blue);

bar(h_red)
```

![figure_1.png](P7_media/figure_1.png)

```matlab
bar(h_green)
```

![figure_2.png](P7_media/figure_2.png)

```matlab
bar(h_blue)
```

![figure_3.png](P7_media/figure_3.png)

Another example: Mandrill image

```matlab
red = mandril(:,:,1);
green = mandril(:,:,2);
blue = mandril(:,:,3);

h_red = imhist(red);
h_green = imhist(green);
h_blue = imhist(blue);

bar(h_red)
```

![figure_4.png](P7_media/figure_4.png)

```matlab
bar(h_green)
```

![figure_5.png](P7_media/figure_5.png)

```matlab
bar(h_blue)
```

![figure_6.png](P7_media/figure_6.png)

We calculate the similarity measures to compare histograms. To simplify, we are going to compare only one histogram per image.

```matlab
lena_gris = rgb2gray(lena);
mandril_gris = rgb2gray(mandril);

h_lena = imhist(lena_gris);
h_mandril = imhist(mandril_gris);
```

We normalize the histogram

```matlab
h_lena_n = h_lena/numel(lena_gris);
h_mandril_n = h_mandril/numel(mandril_gris);
bar(h_lena_n)
```

![figure_7.png](P7_media/figure_7.png)

```matlab
bar(h_mandril_n)
```

![figure_8.png](P7_media/figure_8.png)

Euclidean distance

```matlab
dist_euclidea = sqrt(sum((h_lena_n - h_mandril_n).^2))
```

```matlabTextOutput
dist_euclidea = 0.0533
```

Chi-square distance

```matlab
dist_xicuadrado = sum(((h_lena_n - h_mandril_n).^2) ./ (h_lena_n + h_mandril_n + eps))
```

```matlabTextOutput
dist_xicuadrado = 0.2997
```

Jeffrey divergence distance

```matlab
divergence_jeffrey = sum(h_lena_n.*log((h_lena_n./(h_mandril_n + eps))+eps))
```

```matlabTextOutput
divergence_jeffrey = 2.1436
```

Histogram of oriented gradients


First example: Lena image


Command: extractHOGFeatures

```matlab
[feature_vector,hog] = extractHOGFeatures(lena);

imshow(lena); 
hold on;
plot(hog);
hold off
```

![figure_9.png](P7_media/figure_9.png)

Another example: Mandrill image

```matlab
[feature_vector_mandril,hog_mandril] = extractHOGFeatures(mandril);
imshow(mandril);
hold on
plot(hog_mandril);
hold off
```

![figure_10.png](P7_media/figure_10.png)
# Hough transform-based features

Obtaining lines via the Hough transform


First we obtain the image edges

```matlab
malla_edge = edge(malla,"canny");
```

Command: hough. It gives as output the discretization of the Hough plane H, with the values of theta T and rho R

```matlab
[H,T,R] = hough(malla_edge);
```

We calculate the peaks (points with higher value) in that discretization of the Hough plane. In particular, we keep the 16 highest-value peaks that are above 35% of the maximum value.

```matlab
P = houghpeaks(H, 16,'threshold',ceil(0.35*max(H(:))));
```

We calculate the lines with those peaks and their associated theta and rho values (which define the corresponding lines).

```matlab
lines = houghlines(malla_edge,T,R,P);

imshow(malla)
hold on

for k = 1:length(lines)
   
    xy = [lines(k).point1; lines(k).point2];
    plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','red');

end
hold off
```

![figure_11.png](P7_media/figure_11.png)

We obtain the circles in the image via the Hough transform. To do this, we use the imfindcircles command, which searches for circles with a radius whose value is within the range defined as the second input.

```matlab
[centers, radii] = imfindcircles(textura,[10 30]);
imshow(textura)
viscircles(centers, radii,'EdgeColor','b');
```

![figure_12.png](P7_media/figure_12.png)
# Vertices

The Harris detector is used to identify corners and vertices in the images.

```matlab
corners = detectHarrisFeatures(chessboard);

imshow(chessboard); 
hold on
plot(corners.Location(:,1),corners.Location(:,2),'o','Color','r','LineWidth',2);
hold off
```

![figure_13.png](P7_media/figure_13.png)

Another example. Note that in this case several false positives are detected. A more detailed analysis shows that their metric is very low, so they can be easily removed by selecting the strongest ones, that is, those with a more robust detection.

```matlab

corners_alt = detectHarrisFeatures(chessboard_inclinado);

imshow(chessboard_inclinado); 
hold on
plot(corners_alt.Location(:,1),corners_alt.Location(:,2),'o',"color",'r','LineWidth',2);
hold off
```

![figure_14.png](P7_media/figure_14.png)

```matlab
imshow(chessboard_inclinado)

strongest = corners_alt.selectStrongest(20);

hold on
plot(strongest.Location(:,1),strongest.Location(:,2),'o','color','r','LineWidth',2)
hold off
```

![figure_15.png](P7_media/figure_15.png)