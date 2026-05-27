# Morphological image processing (2nd part)

We load the grayscale images that we will use during the practical session

```matlab
plane = imread("Imagenes\airplane.tif");
cells = imread("Imagenes\bloodcells.tif");
cameraman = imread("Imagenes\cameraman.tif");
butterfly = imread("Imagenes\mariposa.jpg");

montage({plane,cells,cameraman,butterfly})
```

![figure_0.png](P4_media/figure_0.png)
# Primary morphological operators

Definition of the structuring element to be used

```matlab
SE = strel("disk",5);
```

Reminder! Types of structuring elements: diamond, parameter \- distance from the origin to the end of the diamond (1 for cross); disk, parameter \- radius; line, parameters \- length and angle; rectangle, parameters \- length and height; square, parameter \- side; nhood, shape defined by a matrix of 0s and 1s.


Dilation

```matlab
butterfly_dilate = imdilate(butterfly,SE);

montage({butterfly,butterfly_dilate})
```

![figure_1.png](P4_media/figure_1.png)

```matlab
plane_dilate = imdilate(plane,SE);

montage({plane,plane_dilate})
```

![figure_2.png](P4_media/figure_2.png)

Erosion

```matlab
butterfly_erode = imerode(butterfly,SE);

montage({butterfly,butterfly_erode})
```

![figure_3.png](P4_media/figure_3.png)

```matlab
plane_erode = imerode(plane,SE);

montage({plane,plane_erode})
```

![figure_4.png](P4_media/figure_4.png)
# Secondary operators

Opening

```matlab
plane_open = imopen(plane,SE);

montage({plane,plane_open})
```

![figure_5.png](P4_media/figure_5.png)

Closing

```matlab
plane_close = imclose(plane,SE);

montage({plane,plane_close})
```

![figure_6.png](P4_media/figure_6.png)

Another example:

```matlab
cells_open = imopen(cells,SE);
cells_close = imclose(cells,SE);

montage({cells,cells_open,cells_close})
```

![figure_7.png](P4_media/figure_7.png)

Comparison between opening and erosion, and between closing and dilation

```matlab
montage({plane,plane_erode,plane_open})
```

![figure_8.png](P4_media/figure_8.png)

```matlab
montage({plane,plane_dilate,plane_close})
```

![figure_9.png](P4_media/figure_9.png)

We test the effect on bright or dark elements by using a larger structuring element.

```matlab

SE = strel("disk",10);

cells_open = imopen(cells,SE);
cells_close = imclose(cells,SE);

montage({cells,cells_open,cells_close})
```

![figure_10.png](P4_media/figure_10.png)
# Morphological filtering

Morphological smoothing filters

```matlab
cameraman_sal_pimienta = imread("Imagenes\cameraman_ruido_sal_pimienta.png");

cameraman_gaussiano = imread("Imagenes\cameraman_ruido_gaussiano.png");

montage({cameraman_gaussiano,cameraman_sal_pimienta})
```

![figure_11.png](P4_media/figure_11.png)

We define the structuring element most commonly used for this type of filter

```matlab
SE1 = strel("diamond",1);
```

Remember! Morphological smoothing filter: Closing of the opening

```matlab
cameraman_open1 = imopen(cameraman_sal_pimienta,SE1);
cameraman_close1 = imclose(cameraman_open1,SE1);

cameraman_open2 = imopen(cameraman_gaussiano,SE1);
cameraman_close2 = imclose(cameraman_open2,SE1);

montage({cameraman_sal_pimienta,cameraman_close1})
```

![figure_12.png](P4_media/figure_12.png)

```matlab
montage({cameraman_gaussiano,cameraman_close2})
```

![figure_13.png](P4_media/figure_13.png)

Since there is still noise, we apply the alternating sequential filtering technique.

```matlab
SE2 = strel("diamond",2);

cameraman_close1_open = imopen(cameraman_close1,SE2);
cameraman_close1_close = imclose(cameraman_close1_open,SE2);

montage({cameraman_sal_pimienta,cameraman_close1,cameraman_close1_close})
```

![figure_14.png](P4_media/figure_14.png)
# Morphological enhancement filters or morphological gradient

We define the structuring element most commonly used in these cases

```matlab
SE3 = strel("square",3);
```

First, the internal morphological gradient

```matlab
plane_realce_i = plane - imerode(plane,SE3);
```

Then, the external morphological gradient

```matlab
plane_realce_e = imdilate(plane,SE3) - plane;
```

And finally, the internal\-external morphological gradient

```matlab
plane_realce = imdilate(plane,SE3)-imerode(plane,SE3);

montage({plane,plane_realce_i,plane_realce_e,plane_realce})
```

![figure_15.png](P4_media/figure_15.png)

Another example

```matlab
cells_realce_i = cells-imerode(cells,SE3);

cells_realce_e = imdilate(cells,SE3)-cells;

cells_realce = imdilate(cells,SE3)-imerode(cells,SE3);

montage({cells,cells_realce_i,cells_realce_e,cells_realce})
```

![figure_16.png](P4_media/figure_16.png)

The negative image is taken for better visualization

```matlab
cells_realce_i_neg = 255 - cells_realce_i;
cells_realce_e_neg = 255 - cells_realce_e;
cells_realce_neg = 255 - cells_realce;

montage({cells,cells_realce_i_neg,cells_realce_e_neg,cells_realce_neg})
```

![figure_17.png](P4_media/figure_17.png)
# Top\-Hat and Bottom\-Hat transforms
```matlab
cells = imread("Imagenes\cells_internet.jpg");

cells = rgb2gray(cells);

montage(cells)
```

![figure_18.png](P4_media/figure_18.png)

The Top\-Hat transform is calculated

```matlab
SE = strel("disk",30);

cells_top_hat = imtophat(cells,SE);

montage({cells,cells_top_hat})
```

![figure_19.png](P4_media/figure_19.png)

The Bottom\-Hat transform is calculated

```matlab
cells_bot_hat = imbothat(cells,SE);

montage({cells,cells_bot_hat})
```

![figure_20.png](P4_media/figure_20.png)

With a clear application: binarization for the subsequent labeling of connected components

```matlab
cells_bin = imbinarize(cells);

cells_top_hat_bin = imbinarize(cells_top_hat);

cells_bot_hat_bin = imbinarize(cells_bot_hat);

montage({cells_bin,cells_top_hat_bin,cells_bot_hat_bin})
```

![figure_21.png](P4_media/figure_21.png)