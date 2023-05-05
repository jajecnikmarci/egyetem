# MVM
**<h1 align="center">Házi Feladat </h1>**

<h2 align = "center">Specifikáció</h2>
<h2 align = "center">Jajecnik Marcell- DMB3AD</h3>
<h2 align = "center">2023. 04. 24.</h2>

<h3>Feladat leírás</h3>
Tervezze meg a Meseországi Villamos Művek (MVM) nyilvántartási rendszerének egyszerűsített objektummodelljét, majd valósítsa azt meg! A rendszerrel minimum a következő műveleteket kívánjuk elvégezni:

- ügyfél adatinak felvétele
- szolgáltatási szerződés kötése
- szolgáltatási díj előírása (számlázás)
- szolgáltatási díj befizetése
- egyenleg lekérdezése
- fogyasztás bejelentése

A rendszer lehet bővebb funkcionalitású, ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét.
Demonstrálja a működést külön modulként fordított tesztprogrammal! A megoldáshoz ne használjon STL tárolót!

<h3>Bemenetek</h3>

#### Forras.txt fájl ami tartalmazza az ügyfél adatait a következő sorrendben
- ügyfél neve
- ügyfél típus
- szerződéstípus (enum)
- szerződött időszak
- tarifa
- egyenleg

#### Adatfelvitel parancssorból, egy információ, 1 sor
- ügyfél neve
- ügyfél típus
- szerződéstípus (enum)
- szerződéshossz
- tarifa
- egyenleg

#### Parancssoros adatkezelés
- egyenleglekérdezés
- számlakészítés
- befizetés
- fogyasztás bejelentése

#### Tesztesetek futtatása fájlból
- egyenleglekérdezés
- számlakészítés
- befizetés
- fogyasztás bejelentése

<h3>Kimenetek</h3>

#### Számlakészítés fájlba
- Kinek a számlája
- Milyen időszakról
- Mekkora összeg

#### Számlakészítés parancssorba
- Kinek a számlája
- Milyen időszakról
- Mekkora összeg

#### Egyenleglekérdezés
- Függvényvisszaadja a jelenlegi egyenleget

#### Biztonsági mentés (a jelenlegi összes szerződés fájlba mentése)
##
#### Teszt tesztesetekkel tesztfájlal