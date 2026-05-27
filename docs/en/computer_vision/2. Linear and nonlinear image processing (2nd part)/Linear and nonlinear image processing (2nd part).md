# Linear and nonlinear image processing (2nd part)
# **Introduction**

In this practical assignment, different smoothing and enhancement filters applied to grayscale images are studied. The objective is to understand how these filters act, both mathematically and visually, and to analyze their behavior in the presence of noise.

# **Basic image manipulation**

We load the images that will be used throughout the practical assignment and convert them to grayscale when necessary, in order to work only with intensity levels.

```matlab
lena = imread("Imagenes\lena_gray_512.tif");

universo = imread("Imagenes\Universo.jpg");

universo = rgb2gray(universo);
```

We display the loaded images to check that they have been read correctly.

```matlab
montage({lena,universo})
```

![figure_0.png](P2_media/figure_0.png)
# **Smoothing filters**

Smoothing filters reduce noise and abrupt intensity variations, at the cost of losing fine detail in the image.


Convolution product. We define a 3x3 mean kernel, which assigns the same weight to all pixels in the neighborhood.

```matlab
w = (1./9.)*[1,1,1;1,1,1;1,1,1];
```

We apply the convolution using conv2. This function does not automatically handle borders, which causes visible artifacts.

```matlab
lena_conv = conv2(lena,w);

montage({lena,uint8(lena_conv)}) % Observe the borders
```

![figure_1.png](P2_media/figure_1.png)

Mean filter using imfilter. The imfilter function allows the same kernel to be applied, but with better border handling.

```matlab
lena_media = imfilter(lena,w);

montage({lena,lena_media})
```

![figure_2.png](P2_media/figure_2.png)

Padding in imfilter. By default, zero-padding is used, but other options can be used to improve the result at the borders.

```matlab
lena_media_r = imfilter(lena,w,'replicate');

lena_media_s = imfilter(lena,w,'symmetric');

montage({lena,lena_media,lena_media_r,lena_media_s}) % Compare especially the borders
```

![figure_3.png](P2_media/figure_3.png)

Gaussian filter. The Gaussian filter assigns more weight to the central pixel and smooths in a more natural way.


3x3 Gaussian kernel with sigma = 1

```matlab
w_gaussian = (1./16.)*[1,2,1;2,4,2;1,2,1];

lena_gaussian = imfilter(lena,w_gaussian);

montage({lena,lena_gaussian})
```

![figure_4.png](P2_media/figure_4.png)

Larger Gaussian filters using fspecial

```matlab
w_gaussian = fspecial("gaussian",5,5);

lena_gaussian = imfilter(lena,w_gaussian);

montage({lena,lena_gaussian})
```

![figure_5.png](P2_media/figure_5.png)

Generic mean filter with fspecial

```matlab
w_media = fspecial("average",5);

lena_media = imfilter(lena,w_media);

montage({lena,lena_media})
```

![figure_6.png](P2_media/figure_6.png)

Application of the mean filter for Gaussian noise reduction. First, we add Gaussian noise and then apply the filter to observe its effect.

```matlab
lena_ruido = imnoise(lena,"gaussian",0,0.01);

lena_ruido_fil = imfilter(lena_ruido,w_media);

montage({lena,lena_ruido,lena_ruido_fil})
```

![figure_7.png](P2_media/figure_7.png)

Pre-smoothing to improve binarization. Smoothing reduces small variations and enables more stable binarization.

```matlab
universo_bin = universo>200;

w_media = fspecial("average",25);

universo_fil = imfilter(universo,w_media);

universo_fil_bin = universo_fil>200;

montage({universo,universo_bin,universo_fil_bin})
```

![figure_8.png](P2_media/figure_8.png)

Application of the Gaussian filter to noise reduction

```matlab
w_gausiano = fspecial("gaussian",3,3);

lena_ruido_fil = imfilter(lena_ruido,w_gausiano);

montage({lena,lena_ruido,lena_ruido_fil})
```

![figure_9.png](P2_media/figure_9.png)

**Statistical filters**


These filters are based on local statistics of the neighborhood.


Maximum filter. It enhances bright areas and removes isolated dark points.

```matlab
w_estadistico = ones(3);

lena_max = ordfilt2(lena,numel(w_estadistico),w_estadistico);

montage({lena,lena_max})
```

![figure_10.png](P2_media/figure_10.png)

Minimum filter. It enhances dark areas and removes isolated bright points.

```matlab
lena_min = ordfilt2(lena,1,w_estadistico);

montage({lena,lena_min})
```

![figure_11.png](P2_media/figure_11.png)

Median filter. It is especially effective for removing impulse noise (salt and pepper).

```matlab
lena_mediana = medfilt2(lena,size(w_estadistico));

montage({lena,lena_mediana})
```

![figure_12.png](P2_media/figure_12.png)

Application of statistical filters to salt and pepper noise

```matlab
probabilidad = 0.05;

ruido_impulsional = rand(size(lena));

lena_con_ruido = lena;

lena_con_ruido(ruido_impulsional < probabilidad/2) = 0;

lena_con_ruido(ruido_impulsional > 1 - probabilidad/2) = 255;

lena_max = ordfilt2(lena_con_ruido,numel(w_estadistico),w_estadistico);

lena_min = ordfilt2(lena_con_ruido,1,w_estadistico);

lena_mediana = medfilt2(lena_con_ruido,size(w_estadistico));

montage({lena,lena_con_ruido,lena_max,lena_min,lena_mediana})
```

![figure_13.png](P2_media/figure_13.png)
# **Enhancement filters**

These filters highlight abrupt changes in intensity and allow edges to be detected.


Digital derivative by definition. The derivatives in the x and y directions are approximated using simple kernels.

```matlab
w_dx = [0,1,0;0,-1,0;0,0,0];
w_dy = [0,0,0;1,-1,0;0,0,0];
```

Digital gradient. The magnitude of the derivatives in both directions is combined.

```matlab
lena_gradiente = abs(imfilter(lena,w_dx)) + abs(imfilter(lena,w_dy));

lena_negativa = 255 - lena_gradiente;

montage({lena,lena_gradiente,lena_negativa})
```

![figure_14.png](P2_media/figure_14.png)

Roberts, Sobel and Prewitt filters. These filters calculate the gradient using different approximations.


Roberts filter

```matlab
wR_dx = [1,0;0,-1];
wR_dy = [0,1;-1,0];

lena_gradiente_roberts = abs(imfilter(lena,wR_dx)) + abs(imfilter(lena,wR_dy));

lena_negativa_roberts = 255 - lena_gradiente_roberts;

montage({lena,lena_gradiente_roberts,lena_negativa_roberts})
```

![figure_15.png](P2_media/figure_15.png)

Sobel filter

```matlab
w_sobel = fspecial("sobel");

lena_gradiente_sobel = abs(imfilter(lena,w_sobel)) + abs(imfilter(lena,w_sobel'));

lena_negativa_sobel = 255 - lena_gradiente_sobel;

montage({lena,lena_gradiente_sobel,lena_negativa_sobel})
```

![figure_16.png](P2_media/figure_16.png)

Prewitt filter

```matlab
w_prewitt = fspecial("prewitt");

lena_gradiente_prewitt = abs(imfilter(lena,w_prewitt)) + abs(imfilter(lena,w_prewitt'));

lena_negativa_prewitt = 255 - lena_gradiente_prewitt;

montage({lena,lena_gradiente_prewitt,lena_negativa_prewitt})
```

![figure_17.png](P2_media/figure_17.png)

Digital Laplacian. It detects intensity changes in all directions.

```matlab
w_laplaciano = [1,1,1;1,-8,1;1,1,1];

lena_laplaciano = imfilter(lena,w_laplaciano);

lena_laplaciano_negativo = 255 - lena_laplaciano;

montage({lena,lena_laplaciano,lena_laplaciano_negativo})
```

![figure_18.png](P2_media/figure_18.png)

Laplacian of Gaussian (LoG). It combines Gaussian smoothing and edge detection.

```matlab
w_ruido_gauss = fspecial('gaussian',3,1);

lena_ruido_gauss = imfilter(lena,w_ruido_gauss);

lena_log = imfilter(lena_ruido_gauss,w_laplaciano);

lena_log_negativo = 255 - lena_log;

montage({lena,lena_laplaciano,lena_laplaciano_negativo,lena_log,lena_log_negativo})
```

![figure_19.png](P2_media/figure_19.png)

Difference of Gaussians (DoG). The result of two Gaussian filters with different sigma values is subtracted.

```matlab
sigma1 = 0.5;
sigma2 = 2;

w_gaussiano1 = fspecial('gaussian',9,sigma1);
w_gaussiano2 = fspecial('gaussian',9,sigma2);

lena_gaussiano_1 = imfilter(lena,w_gaussiano1);
lena_gaussiano_2 = imfilter(lena,w_gaussiano2);

lena_dog = lena_gaussiano_2 - lena_gaussiano_1;

lena_dog_negativa = 255 - lena_dog;

montage({lena,lena_dog,lena_dog_negativa})
```

![figure_20.png](P2_media/figure_20.png)

Binarization of the DoG result to highlight significant edges

```matlab
lena_dog = lena_dog > 5;

lena_dog_negativa = lena_dog_negativa < 250;

montage({lena,lena_dog,lena_dog_negativa})
```

![figure_21.png](P2_media/figure_21.png)