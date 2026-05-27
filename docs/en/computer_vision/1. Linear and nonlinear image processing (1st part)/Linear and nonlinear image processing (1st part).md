# Linear and nonlinear image processing (1st part)
# Basic image manipulation

We load the images

```matlab
I = imread("Imagenes\lena_gray_512.tif");
F = imread("Imagenes\lena_color_512.tif");
```

We display the images

```matlab
imshow(I)
```

![figure_0.png](P1_media/figure_0.png)

```matlab
imshow(F)
```

![figure_1.png](P1_media/figure_1.png)

We calculate the spatial resolution of each image

```matlab
size(I)
```

```matlabTextOutput
ans = 1x2
   512   512

```

```matlab
size(F)
```

```matlabTextOutput
ans = 1x3
   512   512     3

```

We calculate the intensity resolution, or quantization, of each image

```matlab
max(max(I))
```

```matlabTextOutput
ans = uint8245
```

```matlab
max(max(F))
```

```matlabTextOutput
ans = 1x1x3 uint8 array
ans(:,:,1) =

   255

ans(:,:,2) =

   248

ans(:,:,3) =

   225

```

We spatially rescale the image

```matlab
I = imresize(I,[128,128]);
imshow(I)
```

![figure_2.png](P1_media/figure_2.png)

```matlab
I = imresize(I,[64,64]);
imshow(I)
```

![figure_3.png](P1_media/figure_3.png)

```matlab
I = imresize(I,[16,16]);
imshow(I)
```

![figure_4.png](P1_media/figure_4.png)

```matlab
I = imread("Imagenes\lena_gray_512.tif");
I = imresize(I,[1028,1028]);
imshow(I)
```

![figure_5.png](P1_media/figure_5.png)

We rescale the intensity levels of the image

```matlab
levels_gray = [128,32,4];

I_128 = imquantize(I, linspace(0, 255, levels_gray(1)));
I_32 = imquantize(I, linspace(0, 255, levels_gray(2)));
I_4 = imquantize(I, linspace(0, 255, levels_gray(3)));

imshow(I_128,[])
```

![figure_6.png](P1_media/figure_6.png)

```matlab
imshow(I_32,[])
```

![figure_7.png](P1_media/figure_7.png)

```matlab
imshow(I_4,[])
```

![figure_8.png](P1_media/figure_8.png)

We calculate the histogram

```matlab
histograma = imhist(I);
```

We visualize the histogram

```matlab
bar(histograma)
```

![figure_9.png](P1_media/figure_9.png)

We calculate each of the color channels of the image by "removing" the other two 

```matlab
F_rojo = F;
F_rojo(:,:,2)=0;
F_rojo(:,:,3)=0;

F_verde = F;
F_verde(:,:,1)=0;
F_verde(:,:,3)=0;

F_azul = F;
F_azul(:,:,1)=0;
F_azul(:,:,2)=0;

imshow(F_rojo)
```

![figure_10.png](P1_media/figure_10.png)

```matlab
imshow(F_verde)
```

![figure_11.png](P1_media/figure_11.png)

```matlab
imshow(F_azul)
```

![figure_12.png](P1_media/figure_12.png)

We convert the image from RGB to grayscale

```matlab
F_gris = rgb2gray(F);
imshow(F_gris)
```

![figure_13.png](P1_media/figure_13.png)

We convert the image from RGB to HSV

```matlab
F_hsi = rgb2hsv(F);
imshow(F_hsi)
```

![figure_14.png](P1_media/figure_14.png)

We calculate the H, S and V channels

```matlab
imshow(F_hsi(:,:,1))
```

![figure_15.png](P1_media/figure_15.png)

```matlab
imshow(F_hsi(:,:,2))
```

![figure_16.png](P1_media/figure_16.png)

```matlab
imshow(F_hsi(:,:,3))
```

![figure_17.png](P1_media/figure_17.png)
# Gaussian noise

We define the Gaussian noise parameters, that is, the mean and variance

```matlab
media = 0;
varianza = 0.01;
```

The imnoise function adds multiplicative Gaussian noise, which can be easily detected by its grainy appearance

```matlab
I_gaussian_mult = imnoise(I,"gaussian",media,varianza);

imshow(I_gaussian_mult)
```

![figure_18.png](P1_media/figure_18.png)

Whereas additive Gaussian noise, which is added directly to the image, only slightly blurs the details

```matlab
ruido_gaussiano = uint8(randn(size(I)) * sqrt(varianza) + media);

I_gaussian_add = I + ruido_gaussiano;

imshow(I_gaussian_add)
```

![figure_19.png](P1_media/figure_19.png)
# Salt and pepper noise

We define the parameters of salt and pepper noise, namely, the probability that a given pixel becomes a salt or pepper grain

```matlab
probabilidad = 0.05;
```

Generate a random image that we use to change the pixels of the original image to salt or pepper points (if a random pixel is above or below the defined probability, the corresponding pixel in the original image is changed)

```matlab

ruido_sal_pimienta = rand(size(I));
I_ruido = I;

I_ruido(ruido_sal_pimienta < probabilidad/2) = 0; % "salt" noise
I_ruido(ruido_sal_pimienta > 1 - probabilidad/2) = 255; % "pepper" noise

imshow(I_ruido)
```

![figure_20.png](P1_media/figure_20.png)
# Arithmetic operations
```matlab
I = imread("Imagenes\lena_gray_512.tif");

F = imread("Imagenes\Contornos.tif");

G = imread("Imagenes\Office1.png");

H = imread("Imagenes\Office2.png");

G = rgb2gray(G);

H = rgb2gray(H);

montage({I,F,G,H})
```

![figure_21.png](P1_media/figure_21.png)

Arithmetic addition by a constant

```matlab
I_50 = I + 50;
```

We rescale so that we can operate with the images and use the add function to add them

```matlab
s = size(G);

H = imresize(H,[s(1),s(2)]);

GH_add = imadd(G,H);

montage({I_50,GH_add})
```

![figure_22.png](P1_media/figure_22.png)

Subtraction by a constant

```matlab
I_75 = I - 75;
```

We rescale so that we can operate with the images and use the subtract function to subtract them

```matlab
F = rgb2gray(imresize(F,[512,512]));

IF_resta = imsubtract(I,F);

montage({I_75,IF_resta})
```

![figure_23.png](P1_media/figure_23.png)

Product by a constant

```matlab
I_2 = I.*2;
```

We rescale so that we can operate with the images and use the immultiply function to multiply them

```matlab
IG_prod = immultiply(I,imresize(G,[512,512]));

montage({I_2,IG_prod})
```

![figure_24.png](P1_media/figure_24.png)

Division by a constant

```matlab
I__2 = I./2;
```

We rescale so that we can operate with the images and use the imdivide function to divide them

```matlab
I_div = imdivide(I,imresize(G,[512,512]));

montage({I__2,I_div})
```

![figure_25.png](P1_media/figure_25.png)
# Logical operations

We binarize the images by thresholding

```matlab
G_bin = G>128;

H_bin = H>128;
```

We calculate the logical AND (equivalent to the intersection if the objects are defined by 1)

```matlab
A = and(G_bin,H_bin);

imshow(A
```

![figure_26.png](P1_media/figure_26.png)

We calculate the logical OR (equivalent to the union if the objects are defined by 1)

```matlab
O = or(G_bin,H_bin);

imshow(O)
```

![figure_27.png](P1_media/figure_27.png)

We calculate the logical XOR

```matlab
X = xor(G_bin,H_bin);

imshow(X)
```

![figure_28.png](P1_media/figure_28.png)

We calculate the logical NOT

```matlab
N = not(G_bin);

imshow(N)
```

![figure_29.png](P1_media/figure_29.png)
# Operations with pixel intensity

We calculate the negative image

```matlab
I_neg = 255-I;

imshow(I_neg)
```

![figure_30.png](P1_media/figure_30.png)

We calculate the logarithmic transformation (with constant c = L\-1/log(L) and L gray levels of the image). The logarithmic transformation brightens dark areas while preserving areas that were already bright.

```matlab
imagen = imread("Imagenes\Espalda.jpg");
imagen = rgb2gray(imagen);
imshow(imagen)
```

![figure_31.png](P1_media/figure_31.png)

```matlab
imagen_log = (255/(log(256)))*log(double(imagen) + 1);

imshow(uint8(imagen_log))
```

![figure_32.png](P1_media/figure_32.png)

We calculate the exponential transformation (with constant c = L\-1/log(L) and L gray levels of the image). The exponential transformation darkens bright areas while preserving areas that were already dark. It is the inverse of the logarithmic transformation.

```matlab
imagen_1 = imread("Imagenes\cells_internet.jpg");

imshow(imagen_1)
```

![figure_33.png](P1_media/figure_33.png)

```matlab
imagen_exp = exp((log(256)/255)*double(imagen_1))-1;

imshow(uint8(imagen_exp))
```

![figure_34.png](P1_media/figure_34.png)

Power-root transformation or gamma correction: It combines and generalizes the logarithmic and exponential transformations


First step: I transform the intensity values from the interval $begin:math:display$0\,255$end:math:display$ to $begin:math:display$0\,1$end:math:display$

```matlab
imagen_1_gamma = (1./255.)*double(imagen_1);
```

Second step: I define the gamma value and transform


Third step: I transform the intensity values back to the interval $begin:math:display$0\,255$end:math:display$

```matlab
gamma = 20;

imagen_1_gamma = uint8(imagen_1_gamma.^gamma * 255);

imshow(imagen_1_gamma)
```

![figure_35.png](P1_media/figure_35.png)
# Histogram expansion and equalization

We calculate the histogram

```matlab
h = imhist(I);
bar(h)
```

![figure_36.png](P1_media/figure_36.png)

We calculate the maximum and minimum intensity values to expand the histogram

```matlab
maxi = double(max(max(I)));
mini = double(min(min(I)));
I_exp = 255.*(double(I)-mini)./(maxi-mini);

imshow(uint8(I_exp))
```

![figure_37.png](P1_media/figure_37.png)

```matlab
h_exp = imhist(uint8(I_exp));
bar(h_exp)
```

![figure_38.png](P1_media/figure_38.png)

We equalize the histogram, which uniformly distributes the intensity values across the entire interval

```matlab
I_eq = histeq(I,256);

imshow(I_eq)
```

![figure_39.png](P1_media/figure_39.png)

```matlab
h_eq = imhist(I_eq);
bar(h_eq)
```

![figure_40.png](P1_media/figure_40.png)
# Geometric operations

Rotation by angle theta

```matlab
I_rot = imrotate(I,45);

imshow(I_rot)
```

![figure_41.png](P1_media/figure_41.png)

Translation in the (x,y) direction

```matlab
I_tras = imtranslate(I,[50,150]);

imshow(I_tras)
```

![figure_42.png](P1_media/figure_42.png)

Translation with full image

```matlab
I_tras = imtranslate(I,[50,150],'OutputView','full');

imshow(I_tras)
```

![figure_43.png](P1_media/figure_43.png)

Vertical and horizontal symmetries

```matlab
I_simv = flip(I,1);
I_simh = flip(I,2);

montage({I_simv,I_simh})
```

![figure_44.png](P1_media/figure_44.png)

Dilation and reduction by factors d and r.

```matlab
dilatacion_factor = 2;
reduccion_factor = 0.5;

I_dil = imresize(I,dilatacion_factor);
I_red = imresize(I,reduccion_factor);

montage({I_dil,I_red})
```

![figure_45.png](P1_media/figure_45.png)

For some of the geometric transformations, the interpolation method must be chosen (e.g., rotations and translations)

```matlab
I_rot_n = imrotate(I,45,'nearest');
I_rot_b = imrotate(I,45,'bilinear');
I_rot_bb = imrotate(I,45,'bicubic');

imshow(I_rot_n)
```

![figure_46.png](P1_media/figure_46.png)

```matlab
imshow(I_rot_b)
```

![figure_47.png](P1_media/figure_47.png)

```matlab
imshow(I_rot_bb)
```

![figure_48.png](P1_media/figure_48.png)