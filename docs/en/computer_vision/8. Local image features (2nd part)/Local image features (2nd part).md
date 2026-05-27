# Local image features (2nd part)

We load the images that we will use in the practical session

```matlab
cocacola_lata_1 = imread("Imagenes\coca_cola_1.jpg");
cocacola_lata_2 = imread("Imagenes\coca_cola_2.jpg");
frame1 = imread("Imagenes\Frame 1.tif");
```

We convert the images to grayscale (for better feature detection)

```matlab
cocacola_lata_1 = rgb2gray(cocacola_lata_1);
cocacola_lata_2 = rgb2gray(cocacola_lata_2);

montage({cocacola_lata_1,cocacola_lata_2})
```

![figure_0.png](P8_media/figure_0.png)
# SIFT-type features

We use the detectSIFTFeatures command to obtain all SIFT-type interest points together with their descriptors. Then we display them over the original image to see what type of features this algorithm detects.

```matlab
SIFT_features_lata_2 = detectSIFTFeatures(cocacola_lata_2);
puntos_SIFT_lata_2 = SIFT_features_lata_2.Location;

imshow(cocacola_lata_2)
hold on
plot(puntos_SIFT_lata_2(:,1),puntos_SIFT_lata_2(:,2),'+',Color='r');
hold off
```

![figure_1.png](P8_media/figure_1.png)

Analysis of the input parameters: threshold for the maxima and minima, that is, for non-maximum suppression, threshold to remove interest points belonging to lines, definition of the number of layers in the octaves and of the initial value of the variance.


Another example

```matlab
SIFT_features_frame_1 = detectSIFTFeatures(frame1);

puntos_SIFT_frame_1 = SIFT_features_frame_1.selectStrongest(550);

puntos_SIFT_frame_1 = puntos_SIFT_frame_1.Location;

imshow(frame1);
hold on
plot(puntos_SIFT_frame_1(:,1),puntos_SIFT_frame_1(:,2),'o',Color='r')
hold off
```

![figure_2.png](P8_media/figure_2.png)
# FAST-type features

We use the detectFASTFeatures command to obtain all FAST-type interest points. Then we display them over the original image to see what type of features this algorithm detects.

```matlab
FAST_features_lata_2 = detectFASTFeatures(cocacola_lata_2);

puntos_FAST_lata_2 = FAST_features_lata_2.Location;

imshow(cocacola_lata_2)
hold on
plot(puntos_FAST_lata_2(:,1),puntos_FAST_lata_2(:,2),'o',Color='r');
hold off
```

![figure_3.png](P8_media/figure_3.png)

Another example

```matlab
FAST_features_frame_1 = detectFASTFeatures(frame1);

puntos_FAST_frame_1 = FAST_features_frame_1.Location;

imshow(frame1)
hold on
plot(puntos_FAST_frame_1(:,1),puntos_FAST_frame_1(:,2),'+',Color='r')
hold off
```

![figure_4.png](P8_media/figure_4.png)
# ORB-type features

We use the detectORBFeatures command to obtain all ORB-type interest points together with their descriptors. Then we display them over the original image to see what type of features this algorithm detects.

```matlab
ORB_features_lata_2 = detectORBFeatures(cocacola_lata_2);

puntos_ORB_lata_2 = ORB_features_lata_2.selectStrongest(1000);

puntos_coordenadas_ORB_lata_2 = puntos_ORB_lata_2.Location;

imshow(cocacola_lata_2)
hold on
plot(puntos_coordenadas_ORB_lata_2(:,1),puntos_coordenadas_ORB_lata_2(:,2),'o',Color='r');
hold off
```

![figure_5.png](P8_media/figure_5.png)

Analysis of the input parameters: scale factor for improving the FAST part of the algorithm, number of octaves, and a region of interest in case the features should be detected in a subregion of the original image.


Another example

```matlab
ORB_features_frame_1 = detectORBFeatures(frame1);

puntos_ORB_frame_1 = ORB_features_frame_1.selectStrongest(1000);

puntos_coordenadas_ORB_frame_1 = puntos_ORB_frame_1.Location;

imshow(frame1)
hold on
plot(puntos_coordenadas_ORB_frame_1(:,1),puntos_coordenadas_ORB_frame_1(:,2),'+',Color='r')
hold off
```

![figure_6.png](P8_media/figure_6.png)
# Extract features of a certain type and compare them

The extractFeatures command allows the descriptor vector of the features introduced as an argument to be extracted.

```matlab
[descriptor_lata_2, SIFT_features_lata_2] = extractFeatures(cocacola_lata_2,SIFT_features_lata_2);
```

To compare objects with each other, we repeat the process with the other image containing a can.

```matlab
SIFT_features_lata_1 = detectSIFTFeatures(cocacola_lata_1);

[descriptor_lata_1, SIFT_features_lata_1] = extractFeatures(cocacola_lata_1,SIFT_features_lata_1);
```

We compare the two descriptor vectors with the matchFeatures command. If it is binary, the Hamming distance is used, and if not, the normalized Euclidean distance is used. The function returns the indices of the matched features for the two images, and the length command applied to that vector tells us how many features have been matched.

```matlab
[indices_pares_features,metrica] = matchFeatures(descriptor_lata_2,descriptor_lata_1,"MatchThreshold",10);

length(indices_pares_features)
```

```matlabTextOutput
ans = 71
```

We keep only the matched features

```matlab
matched_SIFT_features_lata_2 = SIFT_features_lata_2(indices_pares_features(:,1),:);
matched_SIFT_features_lata_1 = SIFT_features_lata_1(indices_pares_features(:,2),:);
```

We display the matching between those features

```matlab
figure
showMatchedFeatures(cocacola_lata_2,cocacola_lata_1, matched_SIFT_features_lata_2,matched_SIFT_features_lata_1,"montage");
```

![figure_7.png](P8_media/figure_7.png)

We calculate the geometric transformation (via RANSAC) that allows the geometric alignment between the two images based on the matched features. We use that transformation to transform one of the images and compare the result.

```matlab
T = estimateGeometricTransform(matched_SIFT_features_lata_2,matched_SIFT_features_lata_1,"affine");

T.T
```

```matlabTextOutput
ans = 3x3 single matrix
   -0.6308   -0.2532         0
    0.2542   -0.6325         0
  329.8466  431.7157    1.0000

```

```matlab

cocacola_lata_2_T = imwarp(cocacola_lata_2,T);

montage({cocacola_lata_2_T,cocacola_lata_1})
```

![figure_8.png](P8_media/figure_8.png)