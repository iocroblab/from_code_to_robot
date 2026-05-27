# PROCESSAMENT LINEAL I NO LINEAL DE LA IMATGE DIGITAL (1a PART)
# Manipulació bàsica d’imatges

Carreguem les imatges

```matlab
I = imread("Imagenes\lena_gray_512.tif");
F = imread("Imagenes\lena_color_512.tif");
```

Mostrem les imatges

```matlab
imshow(I)
```

![figure_0.png](P1_media/figure_0.png)

```matlab
imshow(F)
```

![figure_1.png](P1_media/figure_1.png)

Calculem la resolució espacial de cada imatge

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

Calculem la resolució d’intensitat, o quantificació, de cada imatge

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

Reescalem espacialment la imatge

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

Reescalem els nivells d’intensitat de la imatge

```matlab
nivells_gris = [128,32,4];

I_128 = imquantize(I, linspace(0, 255, nivells_gris(1)));
I_32 = imquantize(I, linspace(0, 255, nivells_gris(2)));
I_4 = imquantize(I, linspace(0, 255, nivells_gris(3)));

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

Calculem l’histograma

```matlab
histograma = imhist(I);
```

Visualitzem l’histograma

```matlab
bar(histograma)
```

![figure_9.png](P1_media/figure_9.png)

Calculem cadascun dels canals de color de la imatge mitjançant “eliminar” els altres dos

```matlab
F_vermell = F;
F_vermell(:,:,2)=0;
F_vermell(:,:,3)=0;

F_verd = F;
F_verd(:,:,1)=0;
F_verd(:,:,3)=0;

F_blau = F;
F_blau(:,:,1)=0;
F_blau(:,:,2)=0;

imshow(F_vermell)
```

![figure_10.png](P1_media/figure_10.png)

```matlab
imshow(F_verd)
```

![figure_11.png](P1_media/figure_11.png)

```matlab
imshow(F_blau)
```

![figure_12.png](P1_media/figure_12.png)

Convertim la imatge de RGB a escala de grisos

```matlab
F_gris = rgb2gray(F);
imshow(F_gris)
```

![figure_13.png](P1_media/figure_13.png)

Convertim la imatge de RGB a HSV

```matlab
F_hsi = rgb2hsv(F);
imshow(F_hsi)
```

![figure_14.png](P1_media/figure_14.png)

Calculem els canals H, S i V

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

# Soroll gaussià

Definim els paràmetres del soroll gaussià, és a dir, la mitjana i la variància

```matlab
mitjana = 0;
variancia = 0.01;
```

La funció imnoise afegeix soroll gaussià multiplicatiu, cosa que es pot detectar fàcilment pel seu aspecte granulat

```matlab
I_gaussian_mult = imnoise(I,"gaussian",mitjana,variancia);

imshow(I_gaussian_mult)
```

![figure_18.png](P1_media/figure_18.png)

Mentre que el soroll gaussià additiu, que s’afegeix tal qual a la imatge, només difumina lleugerament els detalls

```matlab
soroll_gaussia = uint8(randn(size(I)) * sqrt(variancia) + mitjana);

I_gaussian_add = I + soroll_gaussia;

imshow(I_gaussian_add)
```

![figure_19.png](P1_media/figure_19.png)

# Soroll sal i pebre

Definim els paràmetres del soroll sal i pebre, és a dir, la probabilitat que un cert píxel passi a ser un gra de sal o de pebre

```matlab
probabilitat = 0.05;
```

Generem una imatge aleatòria que fem servir per canviar els píxels de la imatge original per punts de sal o pebre. Si un píxel aleatori està per sobre o per sota de la probabilitat definida, el píxel corresponent de la imatge original es canvia.

```matlab

soroll_sal_pebre = rand(size(I));
I_soroll = I;

I_soroll(soroll_sal_pebre < probabilitat/2) = 0; % Soroll "sal"
I_soroll(soroll_sal_pebre > 1 - probabilitat/2) = 255; % Soroll "pebre"

imshow(I_soroll)
```

![figure_20.png](P1_media/figure_20.png)

# Operacions aritmètiques

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

Suma aritmètica per una constant

```matlab
I_50 = I + 50;
```

Reescalem per poder operar amb les imatges i fem servir la funció add per sumar-les

```matlab
s = size(G);

H = imresize(H,[s(1),s(2)]);

GH_add = imadd(G,H);

montage({I_50,GH_add})
```

![figure_22.png](P1_media/figure_22.png)

Resta per una constant

```matlab
I_75 = I - 75;
```

Reescalem per poder operar amb les imatges i fem servir la funció substract per restar-les

```matlab
F = rgb2gray(imresize(F,[512,512]));

IF_resta = imsubtract(I,F);

montage({I_75,IF_resta})
```

![figure_23.png](P1_media/figure_23.png)

Producte per una constant

```matlab
I_2 = I.*2;
```

Reescalem per poder operar amb les imatges i fem servir la funció immultiply per multiplicar-les

```matlab
IG_prod = immultiply(I,imresize(G,[512,512]));

montage({I_2,IG_prod})
```

![figure_24.png](P1_media/figure_24.png)

Divisió per una constant

```matlab
I__2 = I./2;
```

Reescalem per poder operar amb les imatges i fem servir la funció imdivide per dividir-les

```matlab
I_div = imdivide(I,imresize(G,[512,512]));

montage({I__2,I_div})
```

![figure_25.png](P1_media/figure_25.png)

# Operacions lògiques

Binaritzem les imatges per llindarització

```matlab
G_bin = G>128;

H_bin = H>128;
```

Calculem l’AND lògic, equivalent a la intersecció si els objectes estan definits per 1

```matlab
A = and(G_bin,H_bin);

imshow(A
```

![figure_26.png](P1_media/figure_26.png)

Calculem l’OR lògic, equivalent a la unió si els objectes estan definits per 1

```matlab
O = or(G_bin,H_bin);

imshow(O)
```

![figure_27.png](P1_media/figure_27.png)

Calculem l’XOR lògic

```matlab
X = xor(G_bin,H_bin);

imshow(X)
```

![figure_28.png](P1_media/figure_28.png)

Calculem el NOT lògic

```matlab
N = not(G_bin);

imshow(N)
```

![figure_29.png](P1_media/figure_29.png)

# Operacions amb la intensitat dels píxels

Calculem la imatge negativa

```matlab
I_neg = 255-I;

imshow(I_neg)
```

![figure_30.png](P1_media/figure_30.png)

Calculem la transf. logarítmica, amb constant c = L\-1/log(L) i L nivells de gris de la imatge. La transf. logarítmica aclareix zones fosques respectant les zones que ja eren clares.

```matlab
imatge = imread("Imagenes\Espalda.jpg");
imatge = rgb2gray(imatge);
imshow(imatge)
```

![figure_31.png](P1_media/figure_31.png)

```matlab
imatge_log = (255/(log(256)))*log(double(imatge) + 1);

imshow(uint8(imatge_log))
```

![figure_32.png](P1_media/figure_32.png)

Calculem la transf. exponencial, amb constant c = L\-1/log(L) i L nivells de gris de la imatge. La transf. exponencial enfosqueix zones clares respectant les zones que ja eren fosques. És la inversa de la transf. logarítmica.

```matlab
imatge_1 = imread("Imagenes\cells_internet.jpg");

imshow(imatge_1)
```

![figure_33.png](P1_media/figure_33.png)

```matlab
imatge_exp = exp((log(256)/255)*double(imatge_1))-1;

imshow(uint8(imatge_exp))
```

![figure_34.png](P1_media/figure_34.png)

Transf. potència\-arrel o correcció gamma: aglutina i generalitza les transf. logarítmica i exponencial


Primer pas: transformo els valors d’intensitat de l’interval $begin:math:display$0\,255$end:math:display$ a $begin:math:display$0\,1$end:math:display$

```matlab
imatge_1_gamma = (1./255.)*double(imatge_1);
```

Segon pas: defineixo el valor de gamma i transformo


Tercer pas: transformo els valors d’intensitat de nou a l’interval $begin:math:display$0\,255$end:math:display$

```matlab
gamma = 20;

imatge_1_gamma = uint8(imatge_1_gamma.^gamma * 255);

imshow(imatge_1_gamma)
```

![figure_35.png](P1_media/figure_35.png)

# Expansió i equalització de l’histograma

Calculem l’histograma

```matlab
h = imhist(I);
bar(h)
```

![figure_36.png](P1_media/figure_36.png)

Calculem els valors d’intensitat màxim i mínim per expandir l’histograma

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

Equalitzem l’histograma, cosa que distribueix de manera uniforme els valors d’intensitat en tot l’interval

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

# Operacions geomètriques

Rotació d’angle theta

```matlab
I_rot = imrotate(I,45);

imshow(I_rot)
```

![figure_41.png](P1_media/figure_41.png)

Traslació en la direcció (x,y)

```matlab
I_tras = imtranslate(I,[50,150]);

imshow(I_tras)
```

![figure_42.png](P1_media/figure_42.png)

Traslació amb imatge completa

```matlab
I_tras = imtranslate(I,[50,150],'OutputView','full');

imshow(I_tras)
```

![figure_43.png](P1_media/figure_43.png)

Simetries vertical i horitzontal

```matlab
I_simv = flip(I,1);
I_simh = flip(I,2);

montage({I_simv,I_simh})
```

![figure_44.png](P1_media/figure_44.png)

Dilatació i reducció de factors d i r.

```matlab
dilatacio_factor = 2;
reduccio_factor = 0.5;

I_dil = imresize(I,dilatacio_factor);
I_red = imresize(I,reduccio_factor);

montage({I_dil,I_red})
```

![figure_45.png](P1_media/figure_45.png)

Per a algunes de les transformacions geomètriques, cal escollir el mètode d’interpolació, per exemple, rotacions i traslacions

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