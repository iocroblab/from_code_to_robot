# Característiques locals de la imatge (1a part)

Carreguem les imatges que utilitzarem en la pràctica.

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
# Característiques basades en l’histograma

Histograma del color


Primer exemple: imatge Lena


Separem la imatge en els tres canals de color

```matlab
vermell = lena(:,:,1);
verd = lena(:,:,2);
blau = lena(:,:,3);
```

I obtenim els histogrames de cada canal

```matlab
h_vermell = imhist(vermell);
h_verd = imhist(verd);
h_blau = imhist(blau);

bar(h_vermell)
```

![figure_1.png](P7_media/figure_1.png)

```matlab
bar(h_verd)
```

![figure_2.png](P7_media/figure_2.png)

```matlab
bar(h_blau)
```

![figure_3.png](P7_media/figure_3.png)

Un altre exemple: imatge mandril

```matlab
vermell = mandril(:,:,1);
verd = mandril(:,:,2);
blau = mandril(:,:,3);

h_vermell = imhist(vermell);
h_verd = imhist(verd);
h_blau = imhist(blau);

bar(h_vermell)
```

![figure_4.png](P7_media/figure_4.png)

```matlab
bar(h_verd)
```

![figure_5.png](P7_media/figure_5.png)

```matlab
bar(h_blau)
```

![figure_6.png](P7_media/figure_6.png)

Calculem les mesures de similitud per comparar histogrames. Per simplificar, compararem només un histograma per imatge.

```matlab
lena_gris = rgb2gray(lena);
mandril_gris = rgb2gray(mandril);

h_lena = imhist(lena_gris);
h_mandril = imhist(mandril_gris);
```

Normalitzem l’histograma

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

Distància euclidiana

```matlab
dist_euclidiana = sqrt(sum((h_lena_n - h_mandril_n).^2))
```

```matlabTextOutput
dist_euclidiana = 0.0533
```

Distància khi quadrat

```matlab
dist_khi_quadrat = sum(((h_lena_n - h_mandril_n).^2) ./ (h_lena_n + h_mandril_n + eps))
```

```matlabTextOutput
dist_khi_quadrat = 0.2997
```

Distància de la divergència de Jeffrey

```matlab
divergencia_jeffrey = sum(h_lena_n.*log((h_lena_n./(h_mandril_n + eps))+eps))
```

```matlabTextOutput
divergencia_jeffrey = 2.1436
```

Histograma dels gradients orientats


Primer exemple: imatge Lena


Comanda: extractHOGFeatures

```matlab
[vector_caracteristiques,hog] = extractHOGFeatures(lena);

imshow(lena); 
hold on;
plot(hog);
hold off
```

![figure_9.png](P7_media/figure_9.png)

Un altre exemple: imatge mandril

```matlab
[vector_caracteristiques_mandril,hog_mandril] = extractHOGFeatures(mandril);
imshow(mandril);
hold on
plot(hog_mandril);
hold off
```

![figure_10.png](P7_media/figure_10.png)
# Característiques basades en la transformada de Hough

Obtenció de rectes mitjançant la transformada de Hough


Primer obtenim les vores de la imatge

```matlab
malla_edge = edge(malla,"canny");
```

Comanda: hough. Dona com a input la discretització del pla de Hough H, amb els valors de theta T i rho R

```matlab
[H,T,R] = hough(malla_edge);
```

Calculem els pics, punts amb més valor, en aquesta discretització del pla de Hough. En particular, ens quedem amb els 16 pics de més valor que estiguin per sobre del 35% del valor màxim.

```matlab
P = houghpeaks(H, 16,'threshold',ceil(0.35*max(H(:))));
```

Calculem les rectes amb aquests pics i els seus valors theta i rho associats, que defineixen les rectes corresponents.

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

Obtenim els cercles en la imatge mitjançant la transformada de Hough. Per a això, utilitzem la comanda imfindcircles, que busca cercles amb un radi de valor comprès en el rang que es defineix com a segon input.

```matlab
[centers, radii] = imfindcircles(textura,[10 30]);
imshow(textura)
viscircles(centers, radii,'EdgeColor','b');
```

![figure_12.png](P7_media/figure_12.png)
# Vèrtexs

S’utilitza el detector de Harris per identificar cantonades i vèrtexs en les imatges.

```matlab
corners = detectHarrisFeatures(chessboard);

imshow(chessboard); 
hold on
plot(corners.Location(:,1),corners.Location(:,2),'o','Color','r','LineWidth',2);
hold off
```

![figure_13.png](P7_media/figure_13.png)

Un altre exemple. Noteu que en aquest cas es detecten diversos falsos positius. Una anàlisi més detallada mostra que la mètrica d’aquests és molt baixa, de manera que es poden eliminar fàcilment seleccionant els més forts, és a dir, els que tenen una detecció més robusta.

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