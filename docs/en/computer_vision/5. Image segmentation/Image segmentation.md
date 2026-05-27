# Image segmentation

We load the images that we will use during this part of the practical session.

```matlab
objetos = imread("Imagenes\objects.tif");
monedas = imread("Imagenes\coins.png");
lake = imread("Imagenes\lake.tif");
cameraman = imread("Imagenes\cameraman.tif");
```

Since lake has two channels, we take one!

```matlab
lake = lake(:,:,1);
```

We display the images

```matlab
montage({objetos,monedas,lake,cameraman})
```

![figure_0.png](P5_media/figure_0.png)
# Segmentation by thresholding

Threshold selection through direct study of the histogram

```matlab
h_objetos = imhist(objetos);

bar(h_objetos)
```

![figure_1.png](P5_media/figure_1.png)

Threshold (estimated visually from the histogram)

```matlab
T=75;

objetos_bin = objetos>T;
```

The imbinarize command can also be used if we use T/255.

```matlab
montage({objetos,objetos_bin})
```

![figure_2.png](P5_media/figure_2.png)

Another example

```matlab
h_lake = imhist(lake);

bar(h_lake)
```

![figure_3.png](P5_media/figure_3.png)

Thresholds (estimated visually from the histogram)

```matlab
T1 = 130;
T2 = 205;

lake_bin = imquantize(lake,[0,T1,T2,255]);

imshow(lake_bin,[])
```

![figure_4.png](P5_media/figure_4.png)

Otsu method

```matlab
T_otsu = graythresh(objetos);

objetos_bin = imbinarize(objetos,T_otsu);

montage({objetos,objetos_bin})
```

![figure_5.png](P5_media/figure_5.png)

Labeling and coloring connected components


First we apply not(objetos), since we want the connected components to be white on a black background.

```matlab
objetos_neg = not(objetos_bin);
```

We use the bwlabel command, which labels the connected components in a binary image.

```matlab
comps_conexas = bwlabel(objetos_neg);
```

To visualize the result (which is completely optional), we use label2rgb, which colors each connected component according to a color palette.

```matlab
objetos_col = label2rgb(comps_conexas,"jet","k","shuffle");

montage({objetos,objetos_neg,objetos_col})
```

![figure_6.png](P5_media/figure_6.png)
# Segmentation methods based on edge detection

Line detection using the Laplacian

```matlab
lineas = imread("Imagenes\lineas.png");
lineas = rgb2gray(lineas);
```

Laplacian kernel to detect vertical lines

```matlab
w_verticales = [-1,2,-1;-1,2,-1;-1,2,-1];

lineas_filt = abs(imfilter(lineas,w_verticales));
```

Threshold to discriminate the calculated lines and remove the weakest ones (which will probably either not be lines or not be vertical lines).

```matlab
maxi = max(lineas_filt(:));

lineas_filt_bin = lineas_filt>=maxi;

montage({lineas,lineas_filt,lineas_filt_bin})
```

![figure_7.png](P5_media/figure_7.png)

The edge command is used for edge detection with the digital gradient and as an alternative to the specific Roberts/Sobel and Prewitt commands obtained with the fspecial command.

```matlab
objetos_contornos_roberts = edge(objetos,"roberts");

objetos_contornos_sobel = edge(objetos,"sobel");

objetos_contornos_prewitt = edge(objetos,"prewitt");

montage({objetos,objetos_contornos_roberts,objetos_contornos_sobel,objetos_contornos_prewitt})
```

![figure_8.png](P5_media/figure_8.png)

Marr\-Hildreth method or zero-crossing method for edge detection

```matlab
house = imread("Imagenes\house.tif");
house = house(:,:,1);
w_log = fspecial("log",25,1);
```

T = 0.018 (empirical, that is, calculated by trial and error).

```matlab
T = 0.018;
```

edge is used for MH with the zerocross option, adding the threshold T and the kernel of a filter, in this case a Laplacian of Gaussian (LoG) filter.

```matlab
house_contornos = edge(house,"zerocross",T,w_log);

montage({house,house_contornos})
```

![figure_9.png](P5_media/figure_9.png)

Canny method


We define the lower and upper thresholds (also calculated empirically).

```matlab
T_canny = [0.04,0.2];
```

The edge command is used to apply the Canny method (with the "canny" option). As extra inputs, a threshold must be added (in this case a vector of two thresholds, lower and upper) and the variance of the first step, which is used to smooth the image with a Gaussian filter.

```matlab
sigma = 4;

house_canny = edge(house,"canny",T_canny,sigma);

montage({house,house_canny})
```

![figure_10.png](P5_media/figure_10.png)

We experiment with the lower and upper thresholds (Important! T1 must always be less than T2 and T2<1)

```matlab
T1 = 0.01:0.03:0.07;
T2 = 0.1:0.2:0.9;
sigma = 4;

% for i = 1:length(T1)
% 
%     for j = 1:length(T2)
% 
%         if T1(i)<T2(j)
% 
%             house_canny_loop = edge(house,"canny",[T1(i),T2(j)],sigma);
% 
%             figure;
%             imshow(house_canny_loop)
% 
%         end
% 
%     end
%
% end

```
# Segmentation methods based on similarity

We load the image that we will use.

```matlab
monedas = imread("Imagenes\coins.png");

imshow(monedas)
```

![figure_11.png](P5_media/figure_11.png)

Watershed \-\-> Segmentation method based on a basin flooding process, that is, from the different minima of the image, and on the construction of dams, that is, edges, separating the different regions.

```matlab
monedas_watershed = watershed(monedas);
```

We keep the separation lines (which are black) in the output of the watershed command. That is, "bordes" is a binary image that has all the black pixels of the output, "monedas\_watershed", which are precisely those separation lines, as pixels with intensity value 1, that is, white.

```matlab
bordes = monedas_watershed == 0;
```

We merge it with the original image and convert the separation lines into white lines so that they stand out when they are superimposed on the original image. First we make a copy of the original image so as not to alter it.

```matlab
monedas_copia = monedas;
```

And then we change the pixels that in the binary image "bordes" do not belong to the image background to white pixels, that is, with intensity level 255.

```matlab
monedas_copia(bordes) = 255;
```

Finally, we display the result.

```matlab
montage({monedas,monedas_copia})
```

![figure_12.png](P5_media/figure_12.png)

There is clearly oversegmentation, so we try different ways to solve this oversegmentation.


1st method \-\-> connectivity option. The "watershed" command accepts a second input, which is the connectivity of the original image. This connectivity can improve the result by removing the dams associated with connected components that are not compatible with the imposed connectivity.

```matlab
monedas_watershed_2 = watershed(monedas,8);

bordes_2 = monedas_watershed_2 == 0;

monedas_copia_2 = monedas;

monedas_copia_2(bordes_2) = 255;

montage({monedas_copia_2})
```

![figure_13.png](P5_media/figure_13.png)

2nd method \-\-> use of the distance transform. The distance transform allows the geometric center of the objects to be found (not of the connected components, but of the objects (two objects touching each other can form a single connected component)). In fact, this is one of the great advantages of watershed, which allows images with touching or partially overlapping objects to be segmented.


To apply the distance transform, we need a binary image. To do this, we binarize using Otsu's method.

```matlab
T_otsu_monedas = graythresh(monedas);

monedas_bin = imbinarize(monedas,T_otsu_monedas);
```

We calculate the distance transform.

```matlab
D = bwdist(monedas_bin);
```

We apply the watershed algorithm to the result.

```matlab
D_watershed = watershed(D);

bordes_D = D_watershed == 0;

monedas_copia_3 = monedas;

monedas_copia_3(bordes_D) = 255;

montage(monedas_copia_3)
```

![figure_14.png](P5_media/figure_14.png)

3rd method \-\-> use of the gradient. The gradient magnitude of the image allows ALL the minima of the image to be detected (the real ones and those that produce oversegmentation).

```matlab
w_sobel = fspecial("sobel");

gradient_mag = abs(imfilter(double(monedas),w_sobel))+abs(imfilter(double(monedas),w_sobel'));
```

We filter the minima so that only the deepest ones survive. The "imextendedmin" command takes an image of regional minima (like the one returned by the gradient) and removes all pixels with an intensity value greater than the second input. The output of the command is a binary image with the deepest minima.

```matlab
minimos = imextendedmin(gradient_mag, 200);
```

We force the gradient minima to be only those that survive the previous command. To do this, the "imimposemin" command is used, which imposes on the first input a set of minima, which is the second input.

```matlab
minimos_forzados = imimposemin(gradient_mag, minimos);

monedas_watershed_3 = watershed(minimos_forzados);

bordes_3 = monedas_watershed_3 == 0;

monedas_copia_3 = monedas;

monedas_copia_3(bordes_3) = 255;

montage({bordes_3,monedas_copia_3})
```

![figure_15.png](P5_media/figure_15.png)