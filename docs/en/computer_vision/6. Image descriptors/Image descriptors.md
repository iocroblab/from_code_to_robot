# Image descriptors

We load the images that we will use in this practical session

```matlab
monedas = imread("Imagenes\monedas_color.jpg");

monedas = imresize(monedas,[400,400]);

monedas = rgb2gray(monedas);

montage(monedas)
```

![figure_0.png](P6_media/figure_0.png)

We segment the image. We want a black background, so we take the negative image.

```matlab
monedas = 255-monedas;
```

And we binarize using the OTSU method

```matlab
T_otsu = graythresh(monedas);

monedas_bin = imbinarize(monedas,T_otsu);

montage(monedas_bin)
```

![figure_1.png](P6_media/figure_1.png)

We improve the segmentation using morphological methods for binary images

```matlab
monedas_bin = imfill(monedas_bin,"holes");

SE = strel("disk",5);

monedas_bin = imclose(monedas_bin,SE);

montage(monedas_bin)
```

![figure_2.png](P6_media/figure_2.png)
# Topological descriptors

Number of connected components.

```matlab
numero_componentes_conexas = bwconncomp(monedas_bin).NumObjects
```

```matlabTextOutput
numero_componentes_conexas = 8
```

```matlab
comp_conexas = bwlabel(monedas_bin);
```

Another way to count connected components

```matlab
numero_componentes_conexas_2 = max(comp_conexas(:))
```

```matlabTextOutput
numero_componentes_conexas_2 = 8
```

```matlab
montage({label2rgb(comp_conexas,"jet","k","shuffle")})
```

![figure_3.png](P6_media/figure_3.png)

Number of holes. Matlab extracts the borders of each connected component; if there are two borders, it is because one of the borders is internal and surrounds a hole.


We define an empty vector that will keep count of the holes of each connected component.

```matlab
agujeros = [];
```

We iterate through each labeled object or connected component to see if it has holes

```matlab
for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    borde = bwboundaries(comp_i);

    if length(borde) > 1

        agujeros = [agujeros,length(borde)-1];

    end
end

agujeros
```

```matlabTextOutput
agujeros =

     []
```

Euler characteristic. Remember that the Euler characteristic is the number of connected components that are not black (background) minus the number of holes.


We define an empty vector that will keep count of the Euler characteristic of each connected component.

```matlab
caracteristica_euler = [];
```

We iterate through each labeled object or connected component to see what its Euler characteristic is

```matlab
for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    borde = bwboundaries(comp_i);

    caracteristica_euler = [caracteristica_euler,1-(length(borde)-1)];
    
end

caracteristica_euler
```

```matlabTextOutput
caracteristica_euler = 1x8
     1     1     1     1     1     1     1     1

```

Another example

```matlab
figuras_agujeros = imread("Imagenes\figuras_agujeros.png");

figuras_agujeros = rgb2gray(figuras_agujeros);

T_otsu_figuras = graythresh(figuras_agujeros);

figuras_agujeros_bin = imbinarize(figuras_agujeros,T_otsu_figuras);

montage(figuras_agujeros_bin)
```

![figure_4.png](P6_media/figure_4.png)

```matlab
numero_comps_conexas = bwconncomp(figuras_agujeros_bin).NumObjects
```

```matlabTextOutput
numero_comps_conexas = 6
```

```matlab
comp_conexas_figuras = bwlabel(figuras_agujeros_bin);

montage({label2rgb(comp_conexas_figuras,"jet","k","shuffle")})
```

![figure_5.png](P6_media/figure_5.png)

```matlab
agujeros_2 = [];
caracteristica_euler_2 = [];

for i = 1:numero_comps_conexas

    comp_i = (comp_conexas_figuras == i);
   
    borde = bwboundaries(comp_i);

    if length(borde) > 1

        agujeros_2 = [agujeros_2,length(borde)-1];
        caracteristica_euler_2 = [caracteristica_euler_2,1-(length(borde)-1)];

    end
end

agujeros_2
```

```matlabTextOutput
agujeros_2 = 1x6
     1     2     2     1     2     2

```

```matlab
caracteristica_euler_2
```

```matlabTextOutput
caracteristica_euler_2 = 1x6
     0    -1    -1     0    -1    -1

```

Skeleton calculation. Calculation based on the distance transform

```matlab
monedas_skel = bwskel(monedas_bin);
```

Calculation based on thinning with morphological operators

```matlab
monedas_skel_2 = bwmorph(monedas_bin,"skeleton",Inf);

montage({monedas_bin,monedas_skel,monedas_skel_2})
```

![figure_6.png](P6_media/figure_6.png)

Calculation of the distance transform

```matlab
D = bwdist(~monedas_bin);

imshow(D,[])
```

![figure_7.png](P6_media/figure_7.png)
# Geometric descriptors
```matlab
montage(monedas_bin)
```

![figure_8.png](P6_media/figure_8.png)

Area calculation.


We define an empty vector that will calculate the area of each connected component.

```matlab
area = [];
```

We iterate through each labeled object or connected component to see what its area is

```matlab
for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    area = [area,sum(comp_i(:))];
    
end

area
```

```matlabTextOutput
area = 1x8
        5453        5074        3563        2436        7174        3047        8253        8731

```

Perimeter calculation.

```matlab
perimetro = [];

for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    perimetro = [perimetro,regionprops(comp_i, 'Perimeter').Perimeter];

end

perimetro
```

```matlabTextOutput
perimetro = 1x8
  258.9320  250.6950  209.2860  175.7500  301.8050  196.0870  320.1980  332.9510

```

Like the perimeter, the area can also be calculated with the command regionprops(comp\_i, 'Area').Area\]


Centroid or center of mass calculation

```matlab
centroide = [];

for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    centroide = [centroide;regionprops(comp_i, 'Centroid').Centroid];

end

centroide
```

```matlabTextOutput
centroide = 8x2
   86.5034  185.0011
   85.0530  305.2221
   94.6444   91.2088
  171.4179  240.7373
  192.8400  143.6901
  211.6853  320.4207
  302.5620  252.9773
  305.9201  101.5368

```

Compactness calculation

```matlab
compacidad = perimetro.*perimetro./area
```

```matlabTextOutput
compacidad = 1x8
   12.2952   12.3863   12.2932   12.6798   12.6967   12.6190   12.4230   12.6969

```

Diameter calculation

```matlab
diametro = [];

for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    diametro = [diametro,regionprops(comp_i, 'MajorAxisLength').MajorAxisLength];

end

diametro
```

```matlabTextOutput
diametro = 1x8
   83.5045   80.6870   67.6135   56.6321   96.2877   63.1585  104.0661  106.1058

```

Eccentricity calculation (that is, the major axis\-minor axis ratio)

```matlab
diametro_menor = [];

for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    diametro_menor = [diametro_menor,regionprops(comp_i, 'MinorAxisLength').MinorAxisLength];

end

excentricidad = diametro./diametro_menor
```

```matlabTextOutput
excentricidad = 1x8
1.0041    1.0074    1.0074    1.0328    1.0146    1.0274    1.0304    1.0124

```

Bounding box calculation

```matlab
imshow(monedas_bin);
hold on;

for i = 1:numero_componentes_conexas

    comp_i = (comp_conexas == i);
   
    bounding_box = regionprops(comp_i, 'boundingbox').BoundingBox;

    rectangulo = rectangle('Position', bounding_box, 'EdgeColor', 'r', 'LineWidth', 2);

end

hold off
```

![figure_9.png](P6_media/figure_9.png)