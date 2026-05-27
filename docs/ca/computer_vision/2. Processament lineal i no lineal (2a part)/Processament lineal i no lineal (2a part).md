# Processament lineal i no lineal de la imatge (2a part)
# **Introducció**

En aquesta pràctica s’estudien diferents filtres de suavitzat i realçament aplicats a imatges en escala de grisos. L’objectiu és comprendre com actuen aquests filtres, tant a nivell matemàtic com visual, i analitzar el seu comportament davant del soroll.

# **Manipulació bàsica d’imatges**

Carreguem les imatges que s’utilitzaran al llarg de la pràctica i les convertim a escala de grisos quan és necessari, per treballar únicament amb nivells d’intensitat.

```matlab
lena = imread("Imagenes\lena_gray_512.tif");

univers = imread("Imagenes\Universo.jpg");

univers = rgb2gray(univers);
```

Mostrem les imatges carregades per comprovar que s’han llegit correctament.

```matlab
montage({lena,univers})
```

![figure_0.png](P2_media/figure_0.png)
# **Filtres de suavitzat**

Els filtres de suavitzat redueixen el soroll i les variacions brusques d’intensitat, a costa de perdre detall fi en la imatge.


Producte de convolució. Definim un kernel de la mitjana 3x3, que assigna el mateix pes a tots els píxels del veïnat.

```matlab
w = (1./9.)*[1,1,1;1,1,1;1,1,1];
```

Apliquem la convolució utilitzant conv2. Aquesta funció no gestiona automàticament les vores, cosa que provoca artefactes visibles.

```matlab
lena_conv = conv2(lena,w);

montage({lena,uint8(lena_conv)}) % Observa les vores
```

![figure_1.png](P2_media/figure_1.png)

Filtre de la mitjana utilitzant imfilter. La funció imfilter permet aplicar el mateix kernel, però gestionant millor les vores.

```matlab
lena_mitjana = imfilter(lena,w);

montage({lena,lena_mitjana})
```

![figure_2.png](P2_media/figure_2.png)

Padding en imfilter. Per defecte s’utilitza zero\-padding, però es poden utilitzar altres opcions per millorar el resultat a les vores.

```matlab
lena_mitjana_r = imfilter(lena,w,'replicate');

lena_mitjana_s = imfilter(lena,w,'symmetric');

montage({lena,lena_mitjana,lena_mitjana_r,lena_mitjana_s}) % Comparar especialment les vores
```

![figure_3.png](P2_media/figure_3.png)

Filtre gaussià. El filtre gaussià assigna més pes al píxel central i suavitza de manera més natural.


Kernel gaussià 3x3 amb sigma = 1

```matlab
w_gaussia = (1./16.)*[1,2,1;2,4,2;1,2,1];

lena_gaussia = imfilter(lena,w_gaussia);

montage({lena,lena_gaussia})
```

![figure_4.png](P2_media/figure_4.png)

Filtres gaussianos de mida més gran utilitzant fspecial

```matlab
w_gaussia = fspecial("gaussian",5,5);

lena_gaussia = imfilter(lena,w_gaussia);

montage({lena,lena_gaussia})
```

![figure_5.png](P2_media/figure_5.png)

Filtre de la mitjana genèric amb fspecial

```matlab
w_mitjana = fspecial("average",5);

lena_mitjana = imfilter(lena,w_mitjana);

montage({lena,lena_mitjana})
```

![figure_6.png](P2_media/figure_6.png)

Aplicació del filtre de la mitjana per a la reducció de soroll gaussià. Primer afegim soroll gaussià i després apliquem el filtre per observar-ne l’efecte.

```matlab
lena_soroll = imnoise(lena,"gaussian",0,0.01);

lena_soroll_fil = imfilter(lena_soroll,w_mitjana);

montage({lena,lena_soroll,lena_soroll_fil})
```

![figure_7.png](P2_media/figure_7.png)

Suavitzat previ per millorar la binarització. El suavitzat redueix petites variacions i facilita una binarització més estable.

```matlab
univers_bin = univers>200;

w_mitjana = fspecial("average",25);

univers_fil = imfilter(univers,w_mitjana);

univers_fil_bin = univers_fil>200;

montage({univers,univers_bin,univers_fil_bin})
```

![figure_8.png](P2_media/figure_8.png)

Aplicació del filtre gaussià a la reducció de soroll

```matlab
w_gaussia = fspecial("gaussian",3,3);

lena_soroll_fil = imfilter(lena_soroll,w_gaussia);

montage({lena,lena_soroll,lena_soroll_fil})
```

![figure_9.png](P2_media/figure_9.png)

**Filtres estadístics**


Aquests filtres es basen en estadístiques locals del veïnat.


Filtre del màxim. realçamenta les zones brillants i elimina punts foscos aïllats.

```matlab
w_estadistic = ones(3);

lena_max = ordfilt2(lena,numel(w_estadistic),w_estadistic);

montage({lena,lena_max})
```

![figure_10.png](P2_media/figure_10.png)

Filtre del mínim. realçamenta les zones fosques i elimina punts brillants aïllats.

```matlab
lena_min = ordfilt2(lena,1,w_estadistic);

montage({lena,lena_min})
```

![figure_11.png](P2_media/figure_11.png)

Filtre de la mediana. És especialment eficaç per eliminar soroll impulsional, sal i pebre.

```matlab
lena_mediana = medfilt2(lena,size(w_estadistic));

montage({lena,lena_mediana})
```

![figure_12.png](P2_media/figure_12.png)

Aplicació de filtres estadístics a soroll sal i pebre

```matlab
probabilitat = 0.05;

soroll_impulsional = rand(size(lena));

lena_amb_soroll = lena;

lena_amb_soroll(soroll_impulsional < probabilitat/2) = 0;

lena_amb_soroll(soroll_impulsional > 1 - probabilitat/2) = 255;

lena_max = ordfilt2(lena_amb_soroll,numel(w_estadistic),w_estadistic);

lena_min = ordfilt2(lena_amb_soroll,1,w_estadistic);

lena_mediana = medfilt2(lena_amb_soroll,size(w_estadistic));

montage({lena,lena_amb_soroll,lena_max,lena_min,lena_mediana})
```

![figure_13.png](P2_media/figure_13.png)
# **Filtres de realçament**

Aquests filtres destaquen canvis bruscos d’intensitat i permeten detectar vores.


Derivada digital per definició. S’aproximen les derivades en les direccions x i y mitjançant kernels simples.

```matlab
w_dx = [0,1,0;0,-1,0;0,0,0];
w_dy = [0,0,0;1,-1,0;0,0,0];
```

Gradient digital. Es combina la magnitud de les derivades en ambdues direccions.

```matlab
lena_gradient = abs(imfilter(lena,w_dx)) + abs(imfilter(lena,w_dy));

lena_negativa = 255 - lena_gradient;

montage({lena,lena_gradient,lena_negativa})
```

![figure_14.png](P2_media/figure_14.png)

Filtres de Roberts, Sobel i Prewitt. Aquests filtres calculen el gradient utilitzant diferents aproximacions.


Filtre de Roberts

```matlab
wR_dx = [1,0;0,-1];
wR_dy = [0,1;-1,0];

lena_gradient_roberts = abs(imfilter(lena,wR_dx)) + abs(imfilter(lena,wR_dy));

lena_negativa_roberts = 255 - lena_gradient_roberts;

montage({lena,lena_gradient_roberts,lena_negativa_roberts})
```

![figure_15.png](P2_media/figure_15.png)

Filtre de Sobel

```matlab
w_sobel = fspecial("sobel");

lena_gradient_sobel = abs(imfilter(lena,w_sobel)) + abs(imfilter(lena,w_sobel'));

lena_negativa_sobel = 255 - lena_gradient_sobel;

montage({lena,lena_gradient_sobel,lena_negativa_sobel})
```

![figure_16.png](P2_media/figure_16.png)

Filtre de Prewitt

```matlab
w_prewitt = fspecial("prewitt");

lena_gradient_prewitt = abs(imfilter(lena,w_prewitt)) + abs(imfilter(lena,w_prewitt'));

lena_negativa_prewitt = 255 - lena_gradient_prewitt;

montage({lena,lena_gradient_prewitt,lena_negativa_prewitt})
```

![figure_17.png](P2_media/figure_17.png)

Laplacià digital. Detecta canvis d’intensitat en totes les direccions.

```matlab
w_laplacia = [1,1,1;1,-8,1;1,1,1];

lena_laplacia = imfilter(lena,w_laplacia);

lena_laplacia_negatiu = 255 - lena_laplacia;

montage({lena,lena_laplacia,lena_laplacia_negatiu})
```

![figure_18.png](P2_media/figure_18.png)

Laplacian of Gaussian (LoG). Combina suavitzat gaussià i detecció de vores.

```matlab
w_soroll_gauss = fspecial('gaussian',3,1);

lena_soroll_gauss = imfilter(lena,w_soroll_gauss);

lena_log = imfilter(lena_soroll_gauss,w_laplacia);

lena_log_negatiu = 255 - lena_log;

montage({lena,lena_laplacia,lena_laplacia_negatiu,lena_log,lena_log_negatiu})
```

![figure_19.png](P2_media/figure_19.png)

Difference of Gaussians (DoG). Es resta el resultat de dos filtres gaussianos amb sigma diferent.

```matlab
sigma1 = 0.5;
sigma2 = 2;

w_gaussia1 = fspecial('gaussian',9,sigma1);
w_gaussia2 = fspecial('gaussian',9,sigma2);

lena_gaussia_1 = imfilter(lena,w_gaussia1);
lena_gaussia_2 = imfilter(lena,w_gaussia2);

lena_dog = lena_gaussia_2 - lena_gaussia_1;

lena_dog_negativa = 255 - lena_dog;

montage({lena,lena_dog,lena_dog_negativa})
```

![figure_20.png](P2_media/figure_20.png)

Binarització del resultat DoG per ressaltar vores significatives

```matlab
lena_dog = lena_dog > 5;

lena_dog_negativa = lena_dog_negativa < 250;

montage({lena,lena_dog,lena_dog_negativa})
```

![figure_21.png](P2_media/figure_21.png)