///
/// Created by Jajecnik Marcell on 2022. 11. 22..
/// @author Jajecnik Marcell
///

#include "beolvas.h"


//!Beolvassa egy sor elemeit egy láncolt listába
int beolvas(Kerdes* kerdes, FILE *f){
    char *sor = sor_be(f);/*!A fájlból beolvas egy sort és azt beteszi egy karaktertömbbbe */
    if (sor==NULL) return 2; /*!EOF-nál */
    if (strlen(sor)==1) return 1;/*!Sor csak a lezáró \0-at tartalmazza*/
    char *token_ptrek[8];/*!A tömb elemeire mutató pointereket tartalmazó tömb */
    int darabolas_eredmenye=token(sor, token_ptrek);/*!Sikerességre tesztelés a daraboláskor */
    if (darabolas_eredmenye==-1) return -1;/*!Memóriafoglalási hibánál */
    kerdes->nehezseg = atoi(token_ptrek[0]);/*!Int-té alakítja majd berakja a nehézséget a kérdés sturct nehézség elemébe */
    free(token_ptrek[0]);/*!Felszabadít mert nincs szükség már a rá mutató pointerre */
    //!A többi részelemet beteszi a nekik szánt helybe, mivel a beolvasás sorrendje ismert előre
    kerdes->kerdes = token_ptrek[1];
    kerdes->a = token_ptrek[2];
    kerdes->b = token_ptrek[3];
    kerdes->c = token_ptrek[4];
    kerdes->d = token_ptrek[5];
    kerdes->helyes = token_ptrek[6][0];/*!Mivel csak egy karaktert tárolunk így nincs szükség a lezáró 0-ra */
    free(token_ptrek[6]);/*!Ezt felszabadítja utána mivel a karakterre mutató pointerre később már nem lesz szükség */
    kerdes->kategoria = token_ptrek[7];
    /**
     * A pointereket később a teljes program lefutásának végén szabadítjuk fel
     */
    free(sor);/*!Felszabadítja a beolvasott sort */
    return 0;/*!Sikeres lefutáskor */
};


//!A beolvasott sort elemekre bontja és visszaadja a rájuk mutató pointereket tartalmazó tömböt
int token(char *sor, char *token_ptrek[]){
    int l= strlen(sor);/*!A beolvasott sor hossza */
    int jelen_resz_kezdo_index=0;/*!A jelenlegi rész kezdő indexe az eredeti karaktertömbben */
    int ptr_szamlalo=0;/*!indexelés a pointer tömbhöz */
    for (int i = 0; i < l; ++i) {/*!Addig amíg az összes karaktert nem rakta be a tömbbe */
        if (sor[i]==';'||sor[i]=='\r'){/*!Ha elválasztó karaktert találtunk, vagy a sor végén vagyunk */
            char* t=(char *) malloc(sizeof (char )*(i-jelen_resz_kezdo_index+1));/*!Új tömböt foglal a jelenlegi résznek */
            if (t==NULL) return -1;/*!Ha nem sikerült visszatér */
            for (int j = 0; j < i-jelen_resz_kezdo_index; ++j) {/*!Átmásolja az eddig beolvasott részekre mutató pointereket az új tömbbe */
                t[j]=sor[jelen_resz_kezdo_index+j];
            }
            t[i-jelen_resz_kezdo_index]='\0';/*!A rész végére beteszi a lezáró 0-át */
            token_ptrek[ptr_szamlalo]=t;/*!Átadja az eredeti tömbnek */
            jelen_resz_kezdo_index=i+1;/*!A kezdő indexet a következő elemre állítja a lezárt rész után */
            ptr_szamlalo++;/*!A beolvasott részek száma */
        }
    }
    return 0;/*!Sikeres lefutáskor */
};

//!A lácolt listában létrehoz egy új elemet a következő beolvasáshoz
void kerdest_beszur(Kerdes **peleje) {
    Kerdes *uj = (Kerdes *) malloc(sizeof(Kerdes));/*!Foglal az új elemre */
    if (peleje==NULL) uj->kov=NULL;/*!Üres listakor */
    else uj->kov=*peleje;/*!Berakja a láncolt lista eljére az új elemet */
    *peleje = uj;/*!A láncolt listára mutató pointert az új elemre állítja */
}


//!A fájlból beolvas egy sort és azt egy karaktertömben visszaadja
char* sor_be (FILE *f) {
    char c_in;/*!Beolvasott karakter */
    int db = 0;/*!Beolvasott karaktertömb hossza */
    /**
     * Nyújtással beolvas mindig egy karaktert majd új tömböt foglalva belerakja az új tömbbe az előzőleg beolvasott elemeket és az új elemet
     */
    char *sor = (char *) malloc(sizeof(char) * 1);
    sor[0] = '\0';
    while ((c_in = fgetc(f)) != '\n' && c_in != EOF) {

        char *ujtomb = (char *) malloc(sizeof(char) * (db + 1 + 1));
        for (int i = 0; i < db; ++i)
            ujtomb[i] = sor[i];
        free(sor);
        sor = ujtomb;
        ujtomb[db] = c_in;
        ujtomb[db + 1] = '\0';
        ++db;
    }/*!Eddig */

    if (c_in == EOF) {/*!Ha vége a fájlnak felszabadítja a sort és visszatér Nullal */
        free(sor);
        return NULL;
    }
    return sor;/*!Visszaadja a beolvasott karaktertömbre mutató pointert */
};

//!A forrásfájl összes sorát beolvassa és eltárolja egy láncolt listában és visszaadja a beolvasott kérdések darabszámát
int lancoltbaolvas(Kerdes **kerdesek_eredeti){
    Kerdes *kerdesek=NULL;/*!Létrehoz egy kérdés sturctot */
    FILE *fp;/*!Létrehoz egy változót a kérdések forrásfájljának kezeléséhez */
    fp= fopen("kerdes.csv","r");/*!Megnyitja olvasásra a kérdések forrásfájlját */
    if (fp==NULL) return -1;/*!Memóriafoglalási hibakor fut le */

    //!A forrásfájl elejében találtam 3 karaktert amit a szövegszerkesztők nem ismernek fel, ezért megnéztem hexaban és ott látszanak, de nem azonosíthatók, így ezek mentés nélküli beolvasással kiszűröm
    for (int i = 0; i < 3; ++i) {
        fgetc(fp);
    }

    int jo=0;/*!Beolvasás sikerességének tárolása */
    int db=0;/*!Beolvasott kérdések számának számlálásához */
    while (jo==0) {/*!Ciklus addig ameddig a beolvasás sikeres */
        kerdest_beszur(&kerdesek);/*!Beszúr egy üres elemet a láncolt lista elejére */
        jo=beolvas(kerdesek, fp);/*!Beolvassa egy sor tartalmát a létrehozott kerdes structba és visszaadja a sikerességet */
        db++;/*!Növeli a beolvasott kérdések számát */
    }
    db--;/*!Mivel az utolsó elemkor a beolvas függvény már nem 0-at ad vissza de utána még növeljük az értéket a ciklusból kilépés előtt így levonunk egyet */
    Kerdes *temp=kerdesek->kov;/*!A tempben eltárolja a kérdések következő elemére mutató pointert */
    free(kerdesek);/*!felszabadítja azt */
    kerdesek=temp;/*!Majd belerakja az eltárolt helycímet */

    printf("%d kérdés beolvasva láncolt listába\n",db);/*!Kiírja a láncolt listába olvasott kérdések számát */
    *kerdesek_eredeti=kerdesek;/*!A kérdések eredetijének első elemét beállítja a függvényen belüli kérdésekre */
    return db;/*!Visszaadja a beolvasott kérdések számát */
};

//!Megszámolja hogy hány nehézségfajta van és hogy a bizonyos nehézségfajtákból hány darab kérdés van
int* nehezsegeket_szamol(Kerdes* eleje, int *nehezsegfajtakszama){
    int *t=NULL;/*!Létrehoz egy integer pointert */
    Kerdes *mozgo;/*!Létrehoz egy helyi kérdés structot */
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){/*!Végigmegy a láncolt listán */
        if (*nehezsegfajtakszama<mozgo->nehezseg) {/*!Ha olyan nehézségi szinttel találkozik ami nagyobb mint az eddigiek */
            int *temp = (int *) malloc(sizeof(int) * mozgo->nehezseg);
            ///
            if (temp==NULL) return NULL;/*!Memóriafoglalási hiba */
            for (int i = 0; i < mozgo->nehezseg; ++i) {/*!A temp int tömb minden elemét 0ra állítja a memóriaszemét elkerülése végett */
                temp[i]=0;
            }
            for (int i = 0; i < *nehezsegfajtakszama; ++i) {/*!Belemásolja az eddig beolvasott adatokat */
                temp[i]=t[i];
            }
            temp[mozgo->nehezseg-1]=1;/*!Az aktuális nehézségi szint számlálóját egyre állítja mert ez az első alkalom hogy találkozott vele */
            *nehezsegfajtakszama=mozgo->nehezseg;/*!Feltételezzük, hogy a legnagyobb nehézségű kérdésnél minden kissebb nehézség létezik, de a kevés kérdést tartalmazó nehézségi szinteket később kiszűrjük*/
            free(t);/*!Felszabadítjuk az eredeti tömböt */
            t=temp;/*!És átállítjuk az eredeti helycímét a most létrehozottéra */
        }
        else t[mozgo->nehezseg-1]++;/*!Ha már ismeri a nehézségfajtát akkor növeli a hozzá tartozó számláló értékét 1-gyel */
    }
    return t;/*!Végül visszaadja a tömbre mutató helycímet */
};

//!A nehézségalapú csoportosítást letárolja és visszaadja a nehézségfajták számát
int kerdest_csoportosit (Kerdes *kerdesek, int **kerdesek_csoportositva){
    int *t;/*!A nehézségiszintekhez tartózó kérdések számát tároló tömbre mutató pointer */
    int nehezsegfajtakszama=0;/*!Az összes nehézségfajta száma */
    t=nehezsegeket_szamol(kerdesek,&nehezsegfajtakszama);/*!A visszakapott helycímre állítja a nehézségiszintekhez tartózó kérdések számát tároló tömb helycímét*/
    if (t==NULL) return -1;/*!Ha sikertelen a számlálás visszatér*/
    int osszeg=0;/*!A tömb által érintett kérdések száma */
    for (int i = 0; i < nehezsegfajtakszama; ++i) osszeg+=t[i];
    printf("%d db kérdés nehézség alapján csoportosítva\n",osszeg);
    *kerdesek_csoportositva=t;/*!Az eredeti tömbünk helycímét a most készítettre állítjuk */
    return nehezsegfajtakszama;/*! Visszaadja a legnagyobb nehézségi szint értékét*/
}

///A láncolt listában tárolt kérdéseket nehézség alapján csoportosítva belerakja egy 2 dimenziós tömbbe
ker_csop_tomben** csop_tomb_belerak(Kerdes *kerdesek_lancoltban, int nehezsegfajtak,int *kerdesek_csoportositva){
    ker_csop_tomben** t=(ker_csop_tomben**) malloc(sizeof(ker_csop_tomben*)*nehezsegfajtak);/*!Helyet foglal az 1. dimenziónak */
    if (t==NULL) return NULL;/*!Ha nem sikerül a foglalás visszatér*/
    for (int i = 0; i < nehezsegfajtak; ++i) {/*!Helyet foglal a 2. dimenzióelemeinek*/
        ker_csop_tomben *t_belso=(ker_csop_tomben*) malloc(sizeof(ker_csop_tomben)*kerdesek_csoportositva[i]);

        if(t_belso==NULL) return NULL;/*!Ha nem sikerül a foglalás akkor visszatér*/
        t[i]=t_belso;
    }
    int jelenhely[nehezsegfajtak];/*!Létrehoz egy integer tömböt ami indexeket tárol a nehézségi szintekhez és elsőként minden eleme 0*/
    for (int i = 0; i < nehezsegfajtak; ++i) {
        jelenhely[i]=0;
    }

    Kerdes *mozgo = kerdesek_lancoltban;/*!A láncolt lista végigjárásához*/
    while(mozgo != NULL) {/*!Amíg el nem ér az utolsó elemig*/
        Kerdes* kov = mozgo->kov;/*!Eltárolja a következő elemre mutató helycímet*/
        t[mozgo->nehezseg-1][jelenhely[mozgo->nehezseg-1]]=konvertal(mozgo);/*!A nehézségi szint szerinti legkisebb nem használt indexre berakja a láncolt lista elemét, amit a konvertáló függvény ad át módosítva*/
        (jelenhely[mozgo->nehezseg-1])++;/*!Növeli a nehézség indexjét*/
        free(mozgo); ///Felszabaditja a lancolt listat, de az elemek tartalma megmarad a konvertalt kerdesekben!
        mozgo = kov;/*!A következő elemre állítja a mozgo-t*/
    }
    printf("Kérdések használatra kész állapotban\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return t;/*!Visszaadja a 2 dimenziós tömböt ami a kérdésekre és azok tulajdonságaira mutató pointereket tárolja tárolja*/
}

//!A láncolt listában tárolt kérdéseknek nincs szükség minden elemére de szükség van a használtságára a kérdésgenerálásnál később
ker_csop_tomben konvertal(Kerdes* kerdes){
    ker_csop_tomben helyi;
    helyi.kerdes=kerdes->kerdes;
    helyi.a=kerdes->a;
    helyi.b=kerdes->b;
    helyi.c=kerdes->c;
    helyi.d=kerdes->d;
    helyi.helyes=kerdes->helyes;
    helyi.kategoria=kerdes->kategoria;
    helyi.hasznalt=false;
    return helyi;
}

//!Egy 2 dimenziós tömb kérdését tároló sturctot felszabadít
static void egy_kerdest_felszabadit(ker_csop_tomben *kerdes){
    free(kerdes->kerdes);
    free(kerdes->a);
    free(kerdes->b);
    free(kerdes->c);
    free(kerdes->d);
    free(kerdes->kategoria);
    return;
}

//!Felszabadítja a 2 dimenziós tömb összes elemét, majd magát a tömböt is
void kerdeseket_felszabadit(ker_csop_tomben **kerdesek, int *kerdesek_csoportositva, int nehezsegfajtak){
    for (int i = 0; i < nehezsegfajtak; ++i) {
        for (int j = 0; j < kerdesek_csoportositva[i]; ++j) {
            egy_kerdest_felszabadit(&kerdesek[i][j]);
        }
        free(kerdesek[i]);
    }
    free(kerdesek);
    free(kerdesek_csoportositva);
    return;
}