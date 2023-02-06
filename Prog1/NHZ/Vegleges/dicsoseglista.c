//
// Created by Jajecnik Marcell on 2022. 12. 02..
//

#include "dicsoseglista.h"

static const int DICSOSEGLISTA_MERET = 10;/*!Constans érték mivel fixen 10 szereplős a dicsőséglista*/

//!Beolvassa a dicsőséglistát fájlból és azt belerakja a dicsoseglistaba
static void dicsoseglista_beolvas(FILE* fp, Eredmeny dicsoseglista[]) {
    for(int i = 0; i < DICSOSEGLISTA_MERET; i++) {
        char* sor = sor_be(fp);/*!Beolvas egy sort*/
        dicsoseglista[i].jatekosnev = sor;/*!A helycímét a soréra állítja*/
        sor = sor_be(fp);/*!beolvas egy sort*/
        dicsoseglista[i].megvalaszolt = atoi(sor);/*!Beleteszi a megválaszoltakhoz*/
        free(sor);/*!És fel is szabadítja, mivel a pointerre már nincs szükség*/
        sor = sor_be(fp);/*!Beolvas egy sort*/
        dicsoseglista[i].ido = atoi(sor);/*!A másodpercben tárolt értéket beleteszi a tömbbe*/
        free(sor);/*!És fel is szabadítja, mert a pointerre nincs szükség*/
    }
}

//!A játékos végeredményét berakja a dicsoseglista legutolsó indexére
static void dicsoseglistabarak(Eredmeny eredmeny, Eredmeny dicsoseglista[]){
    dicsoseglista[DICSOSEGLISTA_MERET].jatekosnev = eredmeny.jatekosnev;
    dicsoseglista[DICSOSEGLISTA_MERET].megvalaszolt = eredmeny.megvalaszolt;
    dicsoseglista[DICSOSEGLISTA_MERET].ido=eredmeny.ido;
}

//!Az újonnan berakott
static void rendez(Eredmeny dicsoseglista[]) {
    int index = -1;/*!Eltárolja az i ciklusváltozó értékét ha bármelyik ha függvény igaz*/
    for (int i = 0; i < DICSOSEGLISTA_MERET; ++i) {
        if (dicsoseglista[i].megvalaszolt==dicsoseglista[DICSOSEGLISTA_MERET].megvalaszolt && dicsoseglista[i].ido > dicsoseglista[DICSOSEGLISTA_MERET].ido ){
            /**
             * Ha az utolsó elem (ami a játékos végeredménye) megválaszoltak száma megegyezik
             * És az időkevesebb mint a vizsgált elemé
             * Akkor megjegyezzük az indexét és majd később a helyére rakjuk be játékos eredményét
             */
            index = i;
            break;
        } else if (dicsoseglista[i].megvalaszolt<dicsoseglista[DICSOSEGLISTA_MERET].megvalaszolt){
            /**
             * Ha már a játékos megválaszolt kérdéseinek száma nagyobb mint a vizsgálté
             * akkor nem kell ellenőrizni az időre sem
             * csak simán megjegyezni az indexét
             * És később ennek helyére másoljuk be a játékos eredményét
             */
            index = i;
            break;
        }
    }
    //!Az 'Utolsó utáni' helyre nem írjuk be az eredményt, és ha egyik eredménynél se volt jobb, akkor nem kerül a dicsőséglistába
    if(index == DICSOSEGLISTA_MERET || index == -1) return;


    Eredmeny temp = dicsoseglista[index];/*!Eltárolja az az eredményt aminél már jobb volt a mostani játékos*/
    dicsoseglista[index]=dicsoseglista[DICSOSEGLISTA_MERET]; /*!A játékos eredményét bemásolja a megjegyzett helyre*/
    //!A mögötte lévő elemeket pedig egyel elcsúsztatja
    for (int i = index + 1; i < DICSOSEGLISTA_MERET; ++i) {

        //!A dicsoseglista utolso elemét lokális változóként használva elmenti az aktuális eredményt
        dicsoseglista[DICSOSEGLISTA_MERET]=dicsoseglista[i];

        //!Belerakja a már rendezetteb dicsőséglistába az eltárolt elemet
        dicsoseglista[i] = temp;

        //!Eltárolja a lokális változó értékét
        temp = dicsoseglista[DICSOSEGLISTA_MERET];
    }
}

//!Létrehoz egy 11 hosszúságú dicsőséglistát mivel az utolsó helyre a játékos eredményei kerülnek majd
static void dicsoseglistat_deklaral(Eredmeny dicsoseglista[]){
    for (int i = 0; i < DICSOSEGLISTA_MERET+1; ++i) {
        /**
         * Minden elemet 0ra állít kivéve a megválaszolt kérdések számát, hogy később azt ki lehesse szűrni
         */
        dicsoseglista[i].jatekosnev='\0';
        dicsoseglista[i].megvalaszolt=-1;
        dicsoseglista[i].ido=0;
    }
}

//!Kiírja a már rendezett dicsőséglistát a képernyőre
static void dicsoseglistatkiir(Eredmeny dicsoseglista[], int nyeremenyek[], int nehezsegiszint){
    printf("\n\n%d. nehézségi szinten\n",nehezsegiszint);
    //!Az utolsó elemet nem kell kiírni mivel az már nem szerepel a dicsőséglista TOP10-jében
    for (int i = 0; i < DICSOSEGLISTA_MERET; ++i) {
        if (dicsoseglista[i].megvalaszolt==-1) break;
        printf("%d. helyezett: %s, %d Ft nyert összeg, %d másodperc alatt\n",
               i+1,
               dicsoseglista[i].jatekosnev,
               dicsoseglista[i].megvalaszolt > 0 ? nyeremenyek[dicsoseglista[i].megvalaszolt-1] : 0,/*!Ha több mint egy kérdést válaszolt meg, kap csak nyereményt*/
               dicsoseglista[i].ido);
    }
}

//!A "dicsoseglista.txt" fajlban tarolja a 10 legjobb idot nehézségi szint alapján
void dicsoseglistat_kezel(Eredmeny eredmeny, int nehezsegiszint, int nyeremenyek[]) {
    Eredmeny dicsoseglista[DICSOSEGLISTA_MERET + 1];/*!Mivel egy új elemet akarunk belerakni, és a végén csak a TOP 10 íródik ki*/
    dicsoseglistat_deklaral(dicsoseglista);/*!Minden elemet alaphelyzetbe állít*/

    ///Fájlnév beállítás
    FILE *fp;
    char fajlnev_format[] = "dicsoseglista_%d";/*!A fájlnév formátuma tartalmazza az utolsó karakterekben a nehézséget, ez alapján azonosítható*/
    char fajlnev[] = "dicsoseglista_00";
    sprintf(fajlnev, fajlnev_format, nehezsegiszint);/*!Létrehozza a kívánt fájlnevet*/

    ///Fájlból olvasás
    fp = fopen(fajlnev, "r+");
    /**Ha sikerült megnyitni beolvas,
     * ha nem akkor még nem létezett ilyen fájl
     * és majd később a kiírásnál jön létre*/
    if (fp != NULL) {
        dicsoseglista_beolvas(fp, dicsoseglista);
        fclose(fp);
    }

    //!Belerakja a játékos eredményét a dicsőséglista utolsó helyére
    dicsoseglistabarak(eredmeny, dicsoseglista);

    //!Rendezi a dicsőséglistát a végső sorrendre
    rendez(dicsoseglista);

    //!Kiírja a consolra a végső dicsőséglistát
    dicsoseglistatkiir(dicsoseglista, nyeremenyek, nehezsegiszint);

    ///Fájlba kiír
    fp = fopen(fajlnev, "w");
    if (fp == NULL) return; /*!Hiba*/
    for (int i = 0; i < DICSOSEGLISTA_MERET; ++i) {
        fprintf(fp, "%s\n", dicsoseglista[i].jatekosnev);
        free(dicsoseglista[i].jatekosnev);/*!Mivel volt neki memória foglalva felszabadít*/
        fprintf(fp, "%d\n", dicsoseglista[i].megvalaszolt);
        fprintf(fp, "%d\n", dicsoseglista[i].ido);
    }
    fclose(fp);

    free(dicsoseglista[DICSOSEGLISTA_MERET].jatekosnev);/*!És mivel már a továbbiakban nincs szükség a dicsőséglistára így felszabadít*/
};

