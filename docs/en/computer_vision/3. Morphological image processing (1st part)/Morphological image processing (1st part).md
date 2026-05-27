# Morphological image processing (1st part)

We load the binary images that we will use during the practical session

```matlab
figuras = imread("Imagenes\figures.png");
head = imread("Imagenes\head.png");
agujeros = imread("Imagenes\agujeros.png");
simbolos = imread("Imagenes\Simbols.jpg");
scissors = imread("Imagenes\scissors.tif");
```

We transform all images that are not binary into binary images

```matlab
figuras = rgb2gray(figuras);
figuras = figuras<128;

agujeros = agujeros>128;

simbolos = rgb2gray(simbolos);
simbolos = imresize(simbolos,[512,512]);
simbolos = simbolos<128;

montage({figuras,head,agujeros,simbolos,scissors})
```

![figure_0.png](P3_media/figure_0.png)
# Primary morphological operators

Definition of structuring elements. The strel command is used, whose input is the type of structuring element, which can be a disk, diamond, line, rectangle, square, and shapes defined by matrices.

```matlab
SE = strel("diamond",1);

```

Types of structuring elements and their parameters:

-  diamond \-\- distance from the origin to the end of the diamond (1 for cross) 
-  disk \-\- radius 
-  line \-\- length and angle 
-  rectangle \-\- length and height (enter as a vector, that is, $begin:math:display$l\,a$end:math:display$) 
-  square \-\- side 
-  nhood \-\- shape defined by a matrix of 0s and 1s 

Dilation. The imdilate command is used, whose input is the binary image to be dilated and the structuring element by which it is dilated. Try diamond 1, square 3, disk 10.

```matlab
SE = strel("square",4);

%SE = strel("disk",10);

scissor_dilate = imdilate(scissors,SE);

montage({scissors,scissor_dilate})
```

![figure_1.png](P3_media/figure_1.png)

```matlab
simbolos_dilate = imdilate(simbolos,SE);
```

The effect will be the expected one, that is, dilating the objects in the image.

```matlab
montage({simbolos,simbolos_dilate})
```

![figure_2.png](P3_media/figure_2.png)

Erosion. The imerode command is used, whose input is the binary image to be eroded and the structuring element by which it is eroded.

```matlab
simbolos_erode = imerode(simbolos,SE);
```

The effect is the expected one: the objects in the image are reduced.

```matlab
montage({simbolos,simbolos_erode})
```

![figure_3.png](P3_media/figure_3.png)

Edge extraction in binary images.


Method 1: image\-erosion(image)

```matlab

head_erode = imerode(head,SE);

head_bordes = head-head_erode;

montage({head,head_bordes})
```

![figure_4.png](P3_media/figure_4.png)

This is considered an inner edge (which comes from an inner residue, which is always generated from erosion by a structuring element).


Outer edge (outer residue, which is always generated from dilation by a structuring element).

```matlab
head_dilate = imdilate(head,SE);
```

Since the dilation of an image is always larger than the image (remember that, in fact, it contains the image), instead of doing image \-dilation(image), we have to do dilation(image)\-image.

```matlab
head_bordes_2 = head_dilate-head;
```

We compare the two types of edges. Pay attention to the small details (such as the eyelashes and lips) to understand why one is called an inner edge and the other an outer edge.

```matlab
montage({head_bordes,head_bordes_2})
```

![figure_5.png](P3_media/figure_5.png)

Internal\-external residue (that is, both together). It is produced by subtracting the erosion of the image from the dilation of the image.

```matlab
head_bordes_3 = head_dilate-head_erode;
```

Notice that this edge is always thicker than the inner or outer edge. This is because this edge contains the inner and outer edges, since it has been calculated with both residues.

```matlab
montage({head_bordes,head_bordes_2,head_bordes_3})
```

![figure_6.png](P3_media/figure_6.png)

Filling holes and interiors. The imfill command is used, where the input is the image with holes. The "holes" option must be added.

```matlab
agujeros_fill = imfill(agujeros,"holes");
montage({agujeros,agujeros_fill})
```

![figure_7.png](P3_media/figure_7.png)

Reconstruction of connected components by dilation.


Uncomment this part when you get here. This command displays the image in an independent window so that you can click on one of the symbols, which will be the one we reconstruct.

```matlab
% imshow(simbolos)
```

This command keeps the coordinates (in double) of the point marked with the mouse in the simbolos image. We have to select a point to reconstruct the connected component associated with that point.

```matlab
%[x,y] = getpts;
```

Binary image of zeros. The false command creates a binary image of the size of the input. In this image, in this case of the same size as the original image, we will only change the value of one pixel, which will be the value of the pixel marked with the mouse using the getspts command.

```matlab
%pointer = false(size(simbolos));
```

We assign the selected point and turn it white. Remember that to reconstruct connected components, the algorithm started with a point that we know belongs to the connected component. In this case, it will be the point marked with the mouse.

```matlab
%pointer(uint16(y),uint16(x)) = 1;
```

The uint16 command only converts x and y into integers, so that we know which pixel is the marker. We do not use uint8 because the marker is on a scale greater than 255 (because the getspts command can be used with images of any type, in particular, high-intensity images). We reconstruct the connected object to which the selected point belongs. To do this, the imreconstruct command is used, whose parameters are the image with the point or points of the connected components to be reconstructed and the original image that will serve as the pattern in the reconstruction.

```matlab
%simbolos_recons = imreconstruct(pointer,simbolos);
```

If you click on more than one symbol with the mouse, imreconstruct will reconstruct all of them.

```matlab
%montage({simbolos,simbolos_recons});
```
# Secondary morphological operators

Opening. The opening operator is applied using the imopen command. This command has as parameters the image to be opened and the structuring element that will be used.

```matlab
SE = strel("disk",5);

figures_open = imopen(figuras,SE);
```

Notice that the outer corners of the triangle and the pentagon are now rounded instead of pointed. This is one of the typical effects of applying the opening operator.

```matlab
montage({figuras,figures_open})
```

![figure_8.png](P3_media/figure_8.png)

Closing. Like the opening operator, this operator is applied using the imclose command, which has the same inputs as the opening operator.

```matlab
figures_close = imclose(figuras,SE);
```

Notice that in this case no changes are observed in the image. This is because the closing operator rounds inner corners, which are not present in this case. Let us look for another example.

```matlab
montage({figuras,figures_close})
```

![figure_9.png](P3_media/figure_9.png)

```matlab
scissors_close = imclose(scissors,SE);
```

Notice that in this case, the inner corners of the object appear rounded instead of pointed, which is a typical effect of the closing operator.

```matlab
montage({scissors,scissors_close})
```

![figure_10.png](P3_media/figure_10.png)

Morphological filtering. It is a "smoothing" filter but based on morphological operators. In particular, it is very good with salt and/or pepper noise.


Remember \-\-> Filtering = Closing of the opening of the image

```matlab
huellas = imread("Imagenes\Huella.jpg");
```

We binarize the Huella image

```matlab
huellas = rgb2gray(huellas);
huellas = huellas>128;

SE = strel('square',5);

huellas_open = imopen(huellas,SE);

huellas_filt = imclose(huellas_open,SE);

montage({huellas,huellas_filt})
```

![figure_11.png](P3_media/figure_11.png)

Hit\-or\-miss transform and reconstruction by dilation. The hit\-or\-miss transform takes a structuring element that is equal to the connected component that you want to find in the original image, and returns a point of the component, to then reconstruct it as we have seen before. It is a way of automatically detecting points of the connected components that we want to reconstruct, without having to click with the mouse.


We take a structuring element that has the shape of one of the symbols in the image.

```matlab
SE1 = simbolos(25:110,285:335);

montage({simbolos,SE1})
```

![figure_12.png](P3_media/figure_12.png)

Remember that the second structuring element must be the complement of the first one.

```matlab
SE2 = not(SE1);

montage({SE1,SE2})
```

![figure_13.png](P3_media/figure_13.png)

The hit\-or\-miss transform is applied with the bwhitmis command, whose inputs are the original image and the two structuring elements.

```matlab
pointer = bwhitmiss(simbolos,SE1,SE2);
```

Once the point of the connected component to be reconstructed has been obtained, we reconstruct it as we have seen before.

```matlab
simbolos_re=imreconstruct(pointer,simbolos);

montage({simbolos,pointer,simbolos_re})
```

![figure_14.png](P3_media/figure_14.png)

Skeletonization. One of the applications of the hit\-or\-miss transform is to calculate the skeleton of the elements in a binary image. There are mainly two ways.


1st method, using the bwskel command, whose input is the original image.

```matlab
figures_sk = bwskel(figuras);
```

2nd method, using the bwmorph command, whose inputs are the original image, "skel" to indicate that the morphological transformation we want to perform is to obtain the skeleton, and Inf, which prunes spurious elements (that is, branches of the skeleton that should not be there).

```matlab
figures_ske = bwmorph(figuras,'skel',Inf);
```

We compare both methods. Although it may seem that bwmorph produces a better result, in general, the best way to calculate the skeleton is with bwskel. Let us see other examples.

```matlab
montage({figuras,figures_sk,figures_ske})
```

![figure_15.png](P3_media/figure_15.png)

```matlab
scissors_sk = bwskel(scissors);

scissors_ske = bwmorph(scissors,'skel',Inf);
```

Here we can observe that bwmorph produces a worse result (and with spurious elements despite the Inf command).

```matlab
montage({scissors,scissors_sk,scissors_ske})
```

![figure_16.png](P3_media/figure_16.png)

```matlab
head_sk = bwskel(head);

head_ske = bwmorph(head,'skel',Inf);
```

Same comment as before.

```matlab
montage({head,head_sk,head_ske})
```

![figure_17.png](P3_media/figure_17.png)

In cases like the previous ones where bwmorph shows a skeleton with undesirable (spurious) elements, there is a command to prune the skeleton even more. It is again bwmorph. In this case, the only thing that changes is that instead of asking for "skel" so that it makes the skeleton, we ask for "spur" so that it prunes spurious elements.

```matlab
scissors_poda = bwmorph(scissors_ske,"spur",Inf);
head_poda = bwmorph(head_ske,"spur",Inf);
```

In both cases the result is still poor, which confirms that the bwskel option is the best.

```matlab
montage({scissors_ske,scissors_poda})
```

![figure_18.png](P3_media/figure_18.png)

```matlab
montage({head_ske,head_poda})
```

![figure_19.png](P3_media/figure_19.png)

Skeleton calculation can also be used to segment the image (if it is binary). To do this, the first step is to apply not() to the image, since the skeleton is always calculated in the area with pixels of value one (white here).

```matlab
figuras = not(figuras);

agujero = not(agujeros_fill);

montage({figuras,agujero})
```

![figure_20.png](P3_media/figure_20.png)

Since the agujero image has two black strips around it, we use a small trick. This consists of defining a white frame around the image and applying the closing operator. This will automatically turn all the background that was not yet white into white.


Command to make the outer border of the image white.

```matlab
agujero(1,:)=1; agujero(end,:)=1; agujero(:,1)=1; agujero(:,end)=1;

agujero = imclose(agujero,SE);
```

Result.

```matlab
montage(agujero)
```

![figure_21.png](P3_media/figure_21.png)

Now, we skeletonize with bwskel and see that it has delimited the areas where each of the figures or each of the objects is located, which is in fact segmenting the image into different areas according to the objects.

```matlab
figuras_sk = bwskel(figuras);

agujero_sk = bwskel(agujero);

montage({figuras,figuras_sk})
```

![figure_22.png](P3_media/figure_22.png)

```matlab
montage({agujero,agujero_sk})
```

![figure_23.png](P3_media/figure_23.png)

bwmorph can also be used to perform all the other operations we have seen before (dilation, erosion, opening, etc.) but only with 3x3 square structuring elements, so in practice it is not used.


If now we wanted to segment a binary image with elements on the border, such as the one shown below, we would discover that the segmentation does not work. A trick to fix this problem consists of removing the border elements.

```matlab
test_morph = imread("Morfologia_I.jpg");

test_morph = rgb2gray(test_morph);
test_morph = test_morph > 128;

montage(test_morph)
```

![figure_24.png](P3_media/figure_24.png)

To do this, we are going to create a binary image that will only have white values on the border and reconstruct it based on the original image. This will give us the border elements, which we simply have to subtract from the original image.

```matlab
pointer = false(size(test_morph));
```

We define white borders

```matlab
pointer(1,:)=1; pointer(:,1)=1; pointer(end,:)=1; pointer(:,end)=1;
```

We reconstruct

```matlab
test_morph_recon = imreconstruct(pointer,test_morph);
```

We subtract to keep the interior elements.

```matlab
test_morph_no_bordes = test_morph - test_morph_recon;

montage({test_morph,test_morph_recon,test_morph_no_bordes})
```

![figure_25.png](P3_media/figure_25.png)
# Distance transform

Distance transform. This calculates the distance to the nearest border of each white element in the original image. In this way, we convert the binary image into a grayscale image. The element furthest from the borders will be 255, and so on proportionally as we get closer to the borders.


Since we want to apply it to the silhouette, we have to convert the silhouette to white and the background to black.

```matlab
head_neg = not(head);

imshow(head_neg)
```

![figure_26.png](P3_media/figure_26.png)

The distance transform is applied with the bwdist command, where the only input is the original image to be transformed.

```matlab
head_d = bwdist(head_neg);
```

To view the images, we need to add $begin:math:display$$end:math:display$

```matlab
imshow(uint8(head_d))
```

![figure_27.png](P3_media/figure_27.png)

Other distances (cityblock \-\- Manhattan or d4, chessboard \-\- chessboard or d8).

```matlab
head_d4 = bwdist(head_neg,"cityblock");
head_d8 = bwdist(head_neg,"chessboard");
imshow(uint8(head_d4))
```

![figure_28.png](P3_media/figure_28.png)

```matlab
imshow(uint8(head_d8))
```

![figure_29.png](P3_media/figure_29.png)