# Segmentació d'imatges

Carreguem les imatges que farem servir durant aquesta part de la sessió pràctica.

```matlab
objectes = imread("Imagenes\objects.tif");
monedes = imread("Imagenes\coins.png");
lake = imread("Imagenes\lake.tif");
cameraman = imread("Imagenes\cameraman.tif");
```

Com que lake té dos canals, n’agafem un!

```matlab
lake = lake(:,:,1);
```

Mostrem les imatges

```matlab
montage({objectes,monedes,lake,cameraman})
```

![figure_0.png](P5_media/figure_0.png)
# Segmentació per llindarització

Selecció de llindars mitjançant l’estudi directe de l’histograma

```matlab
h_objectes = imhist(objectes);

bar(h_objectes)
```

![figure_1.png](P5_media/figure_1.png)

Llindar, calculat a ull a partir de l’histograma

```matlab
T=75;

objectes_bin = objectes>T;
```

També es pot utilitzar la comanda imbinarize si fem T/255.

```matlab
montage({objectes,objectes_bin})
```

![figure_2.png](P5_media/figure_2.png)

Un altre exemple

```matlab
h_lake = imhist(lake);

bar(h_lake)
```

![figure_3.png](P5_media/figure_3.png)

Llindars, calculats a ull a partir de l’histograma

```matlab
T1 = 130;
T2 = 205;

lake_bin = imquantize(lake,[0,T1,T2,255]);

imshow(lake_bin,[])
```

![figure_4.png](P5_media/figure_4.png)

Mètode d’Otsu

```matlab
T_otsu = graythresh(objectes);

objectes_bin = imbinarize(objectes,T_otsu);

montage({objectes,objectes_bin})
```

![figure_5.png](P5_media/figure_5.png)

Etiquetar i acolorir components connexes


Primer fem not(objectes), ja que volem que les components connexes siguin blanques sobre fons negre.

```matlab
objectes_neg = not(objectes_bin);
```

Utilitzem la comanda bwlabel, que etiqueta les components connexes en una imatge binària.

```matlab
comps_connexes = bwlabel(objectes_neg);
```

Per visualitzar el resultat, cosa que és totalment opcional, fem label2rgb, que acoloreix cada component connexa segons una paleta de colors.

```matlab
objectes_col = label2rgb(comps_connexes,"jet","k","shuffle");

montage({objectes,objectes_neg,objectes_col})
```

![figure_6.png](P5_media/figure_6.png)
# Mètodes de segmentació basats en la detecció de vores

Detecció de rectes utilitzant el Laplacià

```matlab
linies = imread("Imagenes\lineas.png");
linies = rgb2gray(linies);
```

Kernel Laplacià per detectar rectes verticals

```matlab
w_verticals = [-1,2,-1;-1,2,-1;-1,2,-1];

linies_filt = abs(imfilter(linies,w_verticals));
```

Llindar per discriminar les rectes calculades i eliminar les més febles, que probablement o no seran rectes o no seran rectes verticals.

```matlab
maxi = max(linies_filt(:));

linies_filt_bin = linies_filt>=maxi;

montage({linies,linies_filt,linies_filt_bin})
```

![figure_7.png](P5_media/figure_7.png)

S’utilitza la comanda edge per a la detecció de vores amb el gradient digital i com a alternativa a les comandes específiques de Roberts/Sobel i Prewitt que s’obtenien amb la comanda fspecial.

```matlab
objectes_contorns_roberts = edge(objectes,"roberts");

objectes_contorns_sobel = edge(objectes,"sobel");

objectes_contorns_prewitt = edge(objectes,"prewitt");

montage({objectes,objectes_contorns_roberts,objectes_contorns_sobel,objectes_contorns_prewitt})
```

![figure_8.png](P5_media/figure_8.png)

Mètode de Marr\-Hildreth o de pas per zero per detectar vores

```matlab
house = imread("Imagenes\house.tif");
house = house(:,:,1);
w_log = fspecial("log",25,1);
```

T = 0.018, empíric, és a dir, calculat mitjançant prova i error.

```matlab
T = 0.018;
```

S’utilitza edge per a MH amb l’opció zerocross afegint el llindar T i el kernel d’un filtre, en aquest cas un filtre Laplacian of a Gaussian (LoG).

```matlab
house_contorns = edge(house,"zerocross",T,w_log);

montage({house,house_contorns})
```

![figure_9.png](P5_media/figure_9.png)

Mètode de Canny


Definim els llindars inferior i superior, també calculats empíricament.

```matlab
T_canny = [0.04,0.2];
```

S’utilitza la comanda edge per aplicar el mètode de Canny, amb l’opció "canny". Com a inputs extra, cal afegir un llindar, en aquest cas un vector de dos llindars, inferior i superior, i la variància del primer pas, que serveix per suavitzar la imatge amb un filtre Gaussià.

```matlab
sigma = 4;

house_canny = edge(house,"canny",T_canny,sigma);

montage({house,house_canny})
```

![figure_10.png](P5_media/figure_10.png)

Juguem amb els llindars inferior i superior. Important! T1 sempre ha de ser menor que T2 i T2<1.

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
# Mètodes de segmentació basats en la similitud

Carreguem la imatge que farem servir.

```matlab
monedes = imread("Imagenes\coins.png");

imshow(monedes)
```

![figure_11.png](P5_media/figure_11.png)

Watershed \-\-> Mètode de segmentació basat en un procés d’inundació de conques, és a dir, dels diferents mínims de la imatge, i de construcció de dics, és a dir, vores, separant les diferents regions.

```matlab
monedes_watershed = watershed(monedes);
```

Ens quedem amb les línies de separació, que són negres, en l’output de la comanda watershed. És a dir, "vores" és una imatge binària que té tots els píxels negres de l’output, "monedes\_watershed", que són precisament aquestes línies de separació, com a píxels amb valor d’intensitat 1, és a dir, blancs.

```matlab
vores = monedes_watershed == 0;
```

Ho ajuntem amb la imatge original i convertim les línies de separació en línies blanques perquè destaquin quan siguin superposades a la imatge original. Primer fem una còpia de la imatge original per no alterar-la.

```matlab
monedes_copia = monedes;
```

I després canviem els píxels que en la imatge binària "vores" no pertanyen al fons de la imatge per píxels blancs, és a dir, amb nivell d’intensitat 255.

```matlab
monedes_copia(vores) = 255;
```

Finalment, mostrem el resultat.

```matlab
montage({monedes,monedes_copia})
```

![figure_12.png](P5_media/figure_12.png)

Clarament hi ha sobresegmentació; provem maneres diferents de resoldre aquesta sobresegmentació.


1a forma \-\-> opció connectivitat. La comanda "watershed" accepta un segon input, que és la connectivitat de la imatge original. Aquesta connectivitat pot millorar el resultat, mitjançant l’eliminació dels dics associats a components connexes no afins amb la connectivitat imposada.

```matlab
monedes_watershed_2 = watershed(monedes,8);

vores_2 = monedes_watershed_2 == 0;

monedes_copia_2 = monedes;

monedes_copia_2(vores_2) = 255;

montage({monedes_copia_2})
```

![figure_13.png](P5_media/figure_13.png)

2a forma \-\-> ús de la transformada de la distància. La transformada de la distància permet trobar el centre geomètric dels objectes, no de les components connexes, sinó dels objectes; dos objectes que es toquen poden conformar una única component connexa. De fet, aquesta és una de les grans avantatges del watershed, que permet segmentar imatges amb objectes que es toquen o estan parcialment solapats.


Per aplicar la transformada de la distància, necessitem una imatge binària. Per a això, binaritzem utilitzant el mètode d’Otsu.

```matlab
T_otsu_monedes = graythresh(monedes);

monedes_bin = imbinarize(monedes,T_otsu_monedes);
```

Calculem la transformada de la distància.

```matlab
D = bwdist(monedes_bin);
```

Apliquem al resultat l’algorisme watershed.

```matlab
D_watershed = watershed(D);

vores_D = D_watershed == 0;

monedes_copia_3 = monedes;

monedes_copia_3(vores_D) = 255;

montage(monedes_copia_3)
```

![figure_14.png](P5_media/figure_14.png)

3a forma \-\-> ús del gradient. La magnitud del gradient de la imatge permet detectar TOTS els mínims de la imatge, els reals i els que produeixen la sobresegmentació.

```matlab
w_sobel = fspecial("sobel");

gradient_mag = abs(imfilter(double(monedes),w_sobel))+abs(imfilter(double(monedes),w_sobel'));
```

Filtrem els mínims de manera que només sobrevisquin els més profunds. La comanda "imextendedmin" pren una imatge de mínims regionals, com la que retorna el gradient, i elimina tots els píxels amb un valor d’intensitat més gran que el segon input. L’output de la comanda és una imatge binària amb els mínims més profunds.

```matlab
minims = imextendedmin(gradient_mag, 200);
```

Forcem que els mínims del gradient siguin només els que sobreviuen a la comanda anterior. Per a això s’utilitza la comanda "imimposemin", que imposa al primer input un conjunt de mínims, que és el segon input.

```matlab
minims_forcats = imimposemin(gradient_mag, minims);

monedes_watershed_3 = watershed(minims_forcats);

vores_3 = monedes_watershed_3 == 0;

monedes_copia_3 = monedes;

monedes_copia_3(vores_3) = 255;

montage({vores_3,monedes_copia_3})
```

![figure_15.png](P5_media/figure_15.png)