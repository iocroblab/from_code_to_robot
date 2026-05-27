# Processament morfològic d'imatges (1a part)

Carreguem les imatges binàries que farem servir durant la sessió pràctica

```matlab
figures = imread("Imagenes\figures.png");
cap = imread("Imagenes\head.png");
forats = imread("Imagenes\agujeros.png");
simbols = imread("Imagenes\Simbols.jpg");
tisores = imread("Imagenes\scissors.tif");
```

Transformem en imatge binària totes aquelles imatges que no ho són

```matlab
figures = rgb2gray(figures);
figures = figures<128;

forats = forats>128;

simbols = rgb2gray(simbols);
simbols = imresize(simbols,[512,512]);
simbols = simbols<128;

montage({figures,cap,forats,simbols,tisores})
```

![figure_0.png](P3_media/figure_0.png)
# Operadors morfològics primaris

Definició d’elements estructurals. S’utilitza la comanda strel, que té com a input el tipus d’element estructural, que pot ser de tipus disc, diamant, recta, rectangle, quadrat i formes definides per matrius.

```matlab
SE = strel("diamond",1);

```

Tipus d’elements estructurals i els seus paràmetres:

-  diamond \-\- distància de l’origen a l’extrem del diamant (1 per a creu) 
-  disk \-\- radi 
-  line \-\- longitud i angle 
-  rectangle \-\- longitud i altura (introduir com a vector, és a dir, $begin:math:display$l\,a$end:math:display$) 
-  square \-\- costat 
-  nhood \-\- forma definida per una matriu de 0s i 1s 

Dilatació. S’utilitza la comanda imdilate, que té com a input la imatge binària a dilatar i l’element estructural pel qual es dilata. Provar amb diamant 1, quadrat 3, disc 10.

```matlab
SE = strel("square",4);

%SE = strel("disk",10);

tisores_dilate = imdilate(tisores,SE);

montage({tisores,tisores_dilate})
```

![figure_1.png](P3_media/figure_1.png)

```matlab
simbols_dilate = imdilate(simbols,SE);
```

L’efecte serà l’esperat, és a dir, dilatar els objectes de la imatge.

```matlab
montage({simbols,simbols_dilate})
```

![figure_2.png](P3_media/figure_2.png)

Erosió. S’utilitza la comanda imerode, que té com a input la imatge binària a erosionar i l’element estructural pel qual s’erosiona.

```matlab
simbols_erode = imerode(simbols,SE);
```

L’efecte és l’esperat: els objectes de la imatge es redueixen.

```matlab
montage({simbols,simbols_erode})
```

![figure_3.png](P3_media/figure_3.png)

Extracció de vores en imatges binàries.


Forma 1: imatge\-erosio(imatge)

```matlab

cap_erode = imerode(cap,SE);

cap_bordes = cap-cap_erode;

montage({cap,cap_bordes})
```

![figure_4.png](P3_media/figure_4.png)

Això es considera una vora interior, que prové d’un residu interior, que sempre es genera a partir de l’erosió per un element estructural.


Vora exterior, o residu exterior, que sempre es genera a partir de la dilatació per un element estructural.

```matlab
cap_dilate = imdilate(cap,SE);
```

Com que la dilatació d’una imatge és sempre més gran que la imatge, recordeu que, de fet, conté la imatge, en comptes de fer imatge \-dilatacio(imatge), hem de fer dilatacio(imatge)\-imatge.

```matlab
cap_bordes_2 = cap_dilate-cap;
```

Comparem els dos tipus de vores. Fixeu-vos en els petits detalls, com les pestanyes i els llavis, per entendre per què una s’anomena vora interior i l’altra exterior.

```matlab
montage({cap_bordes,cap_bordes_2})
```

![figure_5.png](P3_media/figure_5.png)

Residu intern\-extern, és a dir, tots dos junts. Es produeix en restar a la dilatació de la imatge l’erosió de la imatge.

```matlab
cap_bordes_3 = cap_dilate-cap_erode;
```

Fixeu-vos que aquesta vora és sempre més gruixuda que la vora interior o exterior. Això es deu al fet que aquesta vora conté les vores interior i exterior, ja que s’ha calculat amb els dos residus.

```matlab
montage({cap_bordes,cap_bordes_2,cap_bordes_3})
```

![figure_6.png](P3_media/figure_6.png)

Omplir forats i interiors. S’utilitza la comanda imfill, on l’input és la imatge amb forats. Cal afegir l’opció "holes".

```matlab
forats_fill = imfill(forats,"holes");
montage({forats,forats_fill})
```

![figure_7.png](P3_media/figure_7.png)

Reconstrucció de components connexes per dilatació.


Descomentar aquesta part quan s’arribi aquí. Aquesta comanda imprimeix la imatge en una pantalla independent perquè pugueu clicar en un dels símbols, que serà el que reconstruirem.

```matlab
% imshow(simbols)
```

Aquesta comanda es queda amb les coordenades, en double, del punt marcat amb el ratolí a la imatge simbols. Hem de seleccionar un punt per reconstruir la component connexa associada a aquest punt.

```matlab
%[x,y] = getpts;
```

Imatge binària de zeros. La comanda false crea una imatge binària de la mida de l’input. A aquesta imatge, en aquest cas de la mateixa mida que la imatge original, li canviarem només el valor d’un píxel, que serà el valor del píxel marcat amb el ratolí utilitzant la comanda getspts.

```matlab
%punter = false(size(simbols));
```

Assignem el punt seleccionat i el convertim en blanc. Recordeu que, per fer la reconstrucció de components connexes, l’algorisme començava amb un punt que sabem que pertany a la component connexa. En aquest cas, serà el punt marcat amb el ratolí.

```matlab
%punter(uint16(y),uint16(x)) = 1;
```

La comanda uint16 només converteix x i y en enters, perquè sapiguem quin píxel és el del marcador. No utilitzem uint8 perquè el marcador està en una escala més gran que 255, ja que la comanda getspts es pot utilitzar amb imatges de qualsevol tipus, en particular, de gran intensitat. Reconstruïm l’objecte connex al qual pertany el punt seleccionat. Per a això s’utilitza la comanda imreconstruct, que té com a paràmetres la imatge amb el punt o punts de les components connexes a reconstruir i la imatge original que servirà de patró en la reconstrucció.

```matlab
%simbols_recons = imreconstruct(punter,simbols);
```

Si amb el ratolí cliqueu en més d’un símbol, imreconstruct us els reconstruirà tots.

```matlab
%montage({simbols,simbols_recons});
```
# Operadors morfològics secundaris

Obertura. L’operador obertura s’aplica utilitzant la comanda imopen. Aquesta comanda té com a paràmetres la imatge que es vol obrir i l’element estructural que s’utilitzarà.

```matlab
SE = strel("disk",5);

figures_open = imopen(figures,SE);
```

Fixeu-vos que les cantonades exteriors del triangle i el pentàgon ara són romes en comptes de punxegudes. Aquest és un dels efectes típics d’aplicar l’operador obertura.

```matlab
montage({figures,figures_open})
```

![figure_8.png](P3_media/figure_8.png)

Clausura. Igual que l’operador obertura, aquest operador s’aplica utilitzant la comanda imclose, que té els mateixos inputs que l’operador obertura.

```matlab
figures_close = imclose(figures,SE);
```

Fixeu-vos que en aquest cas no s’observen canvis a la imatge. Això es deu al fet que l’operador clausura arrodoneix cantonades interiors, que en aquest cas no són presents. Busquem un altre exemple.

```matlab
montage({figures,figures_close})
```

![figure_9.png](P3_media/figure_9.png)

```matlab
tisores_close = imclose(tisores,SE);
```

Fixeu-vos que en aquest cas les cantonades interiors de l’objecte apareixen romes en comptes de punxegudes, cosa que és un efecte típic de l’operador clausura.

```matlab
montage({tisores,tisores_close})
```

![figure_10.png](P3_media/figure_10.png)

Filtratge morfològic. És un filtre de "suavitzat", però basat en operadors morfològics. En particular, és molt bo amb soroll de tipus sal i/o pebre.


Recordeu \-\-> Filtratge = Clausura de l’obertura de la imatge

```matlab
empremtes = imread("Imagenes\Huella.jpg");
```

Binaritzem la imatge Empremta

```matlab
empremtes = rgb2gray(empremtes);
empremtes = empremtes>128;

SE = strel('square',5);

empremtes_open = imopen(empremtes,SE);

empremtes_filt = imclose(empremtes_open,SE);

montage({empremtes,empremtes_filt})
```

![figure_11.png](P3_media/figure_11.png)

Transformada hit\-or\-miss i reconstrucció per dilatació. La transformada hit\-or\-miss pren un element estructural que sigui igual a la component connexa que es vol trobar a la imatge original, i retorna un punt de la component, per després reconstruir com hem vist abans. És una manera de detectar automàticament punts de les components connexes que volem reconstruir, sense haver de clicar amb el ratolí.


Prenem un element estructural que tingui la forma d’un dels símbols de la imatge.

```matlab
SE1 = simbols(25:110,285:335);

montage({simbols,SE1})
```

![figure_12.png](P3_media/figure_12.png)

Recordeu que el segon element estructural ha de ser el complementari del primer.

```matlab
SE2 = not(SE1);

montage({SE1,SE2})
```

![figure_13.png](P3_media/figure_13.png)

La transformada hit\-or\-miss s’aplica amb la comanda bwhitmis, que té com a inputs la imatge original i els dos elements estructurals.

```matlab
punter = bwhitmiss(simbols,SE1,SE2);
```

Una vegada obtingut el punt de la component connexa a reconstruir, reconstruïm com hem vist abans.

```matlab
simbols_re=imreconstruct(punter,simbols);

montage({simbols,punter,simbols_re})
```

![figure_14.png](P3_media/figure_14.png)

Esqueletització. Una de les aplicacions de la transformada hit\-or\-miss és calcular l’esquelet dels elements en una imatge binària. Hi ha principalment dues formes.


1a forma, utilitzant la comanda bwskel, l’input de la qual és la imatge original.

```matlab
figures_sk = bwskel(figures);
```

2a forma, utilitzant la comanda bwmorph, els inputs de la qual són la imatge original, "skel" per indicar que la transformació morfològica que volem fer és obtenir l’esquelet, i Inf, que poda elements espuris, és a dir, branques de l’esquelet que no hi haurien de ser.

```matlab
figures_ske = bwmorph(figures,'skel',Inf);
```

Comparem ambdues formes. Encara que sembli que bwmorph produeix un millor resultat, en general, la millor manera de calcular l’esquelet és amb bwskel. Vegem altres exemples.

```matlab
montage({figures,figures_sk,figures_ske})
```

![figure_15.png](P3_media/figure_15.png)

```matlab
tisores_sk = bwskel(tisores);

tisores_ske = bwmorph(tisores,'skel',Inf);
```

Aquí s’observa que bwmorph produeix un resultat pitjor, i amb elements espuris malgrat la comanda Inf.

```matlab
montage({tisores,tisores_sk,tisores_ske})
```

![figure_16.png](P3_media/figure_16.png)

```matlab
cap_sk = bwskel(cap);

cap_ske = bwmorph(cap,'skel',Inf);
```

Mateix comentari que abans.

```matlab
montage({cap,cap_sk,cap_ske})
```

![figure_17.png](P3_media/figure_17.png)

En casos com els anteriors, en què bwmorph mostra un esquelet amb elements indesitjables, espuris, hi ha una comanda per podar encara més l’esquelet. Es tracta de nou de bwmorph. En aquest cas, l’únic que canvia és que en comptes de demanar "skel" perquè ens faci l’esquelet, demanem "spur" perquè ens podi elements espuris.

```matlab
tisores_poda = bwmorph(tisores_ske,"spur",Inf);
cap_poda = bwmorph(cap_ske,"spur",Inf);
```

En ambdós casos el resultat continua sent dolent, cosa que confirma que l’opció bwskel és la millor.

```matlab
montage({tisores_ske,tisores_poda})
```

![figure_18.png](P3_media/figure_18.png)

```matlab
montage({cap_ske,cap_poda})
```

![figure_19.png](P3_media/figure_19.png)

El càlcul d’esquelets també es pot utilitzar per segmentar la imatge, si és binària. Per a això, el primer pas és fer not() de la imatge, ja que l’esquelet sempre es calcula a la zona amb píxels de valor u, blancs aquí.

```matlab
figures = not(figures);

forat = not(forats_fill);

montage({figures,forat})
```

![figure_20.png](P3_media/figure_20.png)

Com que la imatge forat té dues franges negres al voltant, utilitzem un petit truc. Aquest consisteix a definir un marc blanc al voltant de la imatge i aplicar l’operador clausura. Aquest, automàticament, convertirà en blanc tot el fons que encara no ho era.


Comanda per fer que la vora exterior de la imatge sigui blanca.

```matlab
forat(1,:)=1; forat(end,:)=1; forat(:,1)=1; forat(:,end)=1;

forat = imclose(forat,SE);
```

Resultat.

```matlab
montage(forat)
```

![figure_21.png](P3_media/figure_21.png)

Ara sí, esqueletitzem amb bwskel i veiem que ens ha delimitat les àrees en què es troba cadascuna de les figures o cadascun dels objectes, cosa que de fet és segmentar la imatge en àrees diferents, atenent als objectes.

```matlab
figures_sk = bwskel(figures);

forat_sk = bwskel(forat);

montage({figures,figures_sk})
```

![figure_22.png](P3_media/figure_22.png)

```matlab
montage({forat,forat_sk})
```

![figure_23.png](P3_media/figure_23.png)

bwmorph també es pot utilitzar per fer totes les altres operacions que hem vist abans, dilatació, erosió, obertura, etc., però només amb elements estructurals quadrats 3x3, per la qual cosa a la pràctica no s’utilitza.


Si ara volguéssim segmentar una imatge binària amb elements a la vora, com la mostrada a continuació, descobriríem que la segmentació no funciona. Un truc per arreglar aquest problema consisteix a eliminar els elements de la vora.

```matlab
test_morph = imread("Morfologia_I.jpg");

test_morph = rgb2gray(test_morph);
test_morph = test_morph > 128;

montage(test_morph)
```

![figure_24.png](P3_media/figure_24.png)

Per a això, crearem una imatge binària que només tindrà valor blanc a la vora i la reconstruirem basant-nos en la imatge original. Això ens donarà els elements de la vora, que simplement hem de sostreure de la imatge original.

```matlab
punter = false(size(test_morph));
```

Definim vores blanques

```matlab
punter(1,:)=1; punter(:,1)=1; punter(end,:)=1; punter(:,end)=1;
```

Reconstruïm

```matlab
test_morph_recon = imreconstruct(punter,test_morph);
```

Restem per quedar-nos amb els elements de l’interior.

```matlab
test_morph_no_bordes = test_morph - test_morph_recon;

montage({test_morph,test_morph_recon,test_morph_no_bordes})
```

![figure_25.png](P3_media/figure_25.png)
# Transformada de la distància

Transformada de la distància. Aquesta calcula la distància a la vora més propera de cada element blanc de la imatge original. D’aquesta manera, convertim la imatge binària en una imatge en escala de grisos. L’element més allunyat de les vores serà un 255, i així en proporció, a mesura que ens acostem a les vores.


Com que volem aplicar-ho a la silueta, hem de convertir la silueta en blanc i el fons en negre.

```matlab
cap_neg = not(cap);

imshow(cap_neg)
```

![figure_26.png](P3_media/figure_26.png)

La transformada de la distància s’aplica amb la comanda bwdist, on l’únic input és la imatge original que es vol transformar.

```matlab
cap_d = bwdist(cap_neg);
```

Per veure les imatges, necessitem afegir $begin:math:display$$end:math:display$

```matlab
imshow(uint8(cap_d))
```

![figure_27.png](P3_media/figure_27.png)

Altres distàncies: cityblock \-\- Manhattan o d4, chessboard \-\- tauler d’escacs o d8.

```matlab
cap_d4 = bwdist(cap_neg,"cityblock");
cap_d8 = bwdist(cap_neg,"chessboard");
imshow(uint8(cap_d4))
```

![figure_28.png](P3_media/figure_28.png)

```matlab
imshow(uint8(cap_d8))
```

![figure_29.png](P3_media/figure_29.png)