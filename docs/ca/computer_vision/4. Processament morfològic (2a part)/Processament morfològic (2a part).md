# Processament morfològic d'imatges (2a part)

Carreguem les imatges en escala de grisos que farem servir durant la sessió pràctica

```matlab
plane = imread("Imagenes\airplane.tif");
cells = imread("Imagenes\bloodcells.tif");
cameraman = imread("Imagenes\cameraman.tif");
butterfly = imread("Imagenes\mariposa.jpg");

montage({plane,cells,cameraman,butterfly})
```

![figure_0.png](P4_media/figure_0.png)
# Operadors morfològics primaris

Definició de l’element estructural que s’utilitzarà

```matlab
SE = strel("disk",5);
```

Recordatori! Tipus d’elements estructurals: diamond, paràmetre \- distància de l’origen a l’extrem del diamant (1 per a creu); disk, paràmetre \- radi; line, paràmetres \- longitud i angle; rectangle, paràmetres \- longitud i altura; square, paràmetre \- costat; nhood, forma definida per una matriu de 0s i 1s.


Dilatació

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

Erosió

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
# Operadors secundaris

Obertura

```matlab
plane_open = imopen(plane,SE);

montage({plane,plane_open})
```

![figure_5.png](P4_media/figure_5.png)

Clausura

```matlab
plane_close = imclose(plane,SE);

montage({plane,plane_close})
```

![figure_6.png](P4_media/figure_6.png)

Un altre exemple:

```matlab
cells_open = imopen(cells,SE);
cells_close = imclose(cells,SE);

montage({cells,cells_open,cells_close})
```

![figure_7.png](P4_media/figure_7.png)

Comparació entre obertura i erosió i entre clausura i dilatació

```matlab
montage({plane,plane_erode,plane_open})
```

![figure_8.png](P4_media/figure_8.png)

```matlab
montage({plane,plane_dilate,plane_close})
```

![figure_9.png](P4_media/figure_9.png)

Provem l’efecte sobre elements clars o foscos mitjançant l’ús d’un element estructural més gran.

```matlab

SE = strel("disk",10);

cells_open = imopen(cells,SE);
cells_close = imclose(cells,SE);

montage({cells,cells_open,cells_close})
```

![figure_10.png](P4_media/figure_10.png)
# Filtratge morfològic

Filtres de suavitzat morfològic

```matlab
cameraman_sal_pimienta = imread("Imagenes\cameraman_ruido_sal_pimienta.png");

cameraman_gaussiano = imread("Imagenes\cameraman_ruido_gaussiano.png");

montage({cameraman_gaussiano,cameraman_sal_pimienta})
```

![figure_11.png](P4_media/figure_11.png)

Definim l’element estructural més utilitzat per a aquest tipus de filtres

```matlab
SE1 = strel("diamond",1);
```

Recordeu! Filtre de suavitzat morfològic: clausura de l’obertura

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

Com que encara hi ha soroll, apliquem la tècnica de filtratge seqüencial alternant.

```matlab
SE2 = strel("diamond",2);

cameraman_close1_open = imopen(cameraman_close1,SE2);
cameraman_close1_close = imclose(cameraman_close1_open,SE2);

montage({cameraman_sal_pimienta,cameraman_close1,cameraman_close1_close})
```

![figure_14.png](P4_media/figure_14.png)
# Filtres de realç morfològic o gradient morfològic

Definim l’element estructural més utilitzat en aquests casos

```matlab
SE3 = strel("square",3);
```

Primer gradient morfològic intern

```matlab
plane_realce_i = plane - imerode(plane,SE3);
```

Després, el gradient morfològic extern

```matlab
plane_realce_e = imdilate(plane,SE3) - plane;
```

I finalment, el gradient morfològic intern\-extern

```matlab
plane_realce = imdilate(plane,SE3)-imerode(plane,SE3);

montage({plane,plane_realce_i,plane_realce_e,plane_realce})
```

![figure_15.png](P4_media/figure_15.png)

Un altre exemple

```matlab
cells_realce_i = cells-imerode(cells,SE3);

cells_realce_e = imdilate(cells,SE3)-cells;

cells_realce = imdilate(cells,SE3)-imerode(cells,SE3);

montage({cells,cells_realce_i,cells_realce_e,cells_realce})
```

![figure_16.png](P4_media/figure_16.png)

Es pren la imatge negativa per a una millor visualització

```matlab
cells_realce_i_neg = 255 - cells_realce_i;
cells_realce_e_neg = 255 - cells_realce_e;
cells_realce_neg = 255 - cells_realce;

montage({cells,cells_realce_i_neg,cells_realce_e_neg,cells_realce_neg})
```

![figure_17.png](P4_media/figure_17.png)
# Transformades Top\-Hat i Bottom\-Hat
```matlab
cells = imread("Imagenes\cells_internet.jpg");

cells = rgb2gray(cells);

montage(cells)
```

![figure_18.png](P4_media/figure_18.png)

Es calcula la transformada Top\-Hat

```matlab
SE = strel("disk",30);

cells_top_hat = imtophat(cells,SE);

montage({cells,cells_top_hat})
```

![figure_19.png](P4_media/figure_19.png)

Es calcula la transformada Bottom\-Hat

```matlab
cells_bot_hat = imbothat(cells,SE);

montage({cells,cells_bot_hat})
```

![figure_20.png](P4_media/figure_20.png)

Amb una aplicació clara, la binarització per al posterior etiquetatge de components connexes

```matlab
cells_bin = imbinarize(cells);

cells_top_hat_bin = imbinarize(cells_top_hat);

cells_bot_hat_bin = imbinarize(cells_bot_hat);

montage({cells_bin,cells_top_hat_bin,cells_bot_hat_bin})
```

![figure_21.png](P4_media/figure_21.png)