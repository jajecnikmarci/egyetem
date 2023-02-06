///
/// Created by Jajecnik Marcell on 2022. 12. 01..
///@author Jajecnik Marcell
///

#include "jatek.h"

//!Bekér egy nehézségi szintet a játékostól és ellenőrzi, hogy azon a nehézségi szinten játszható-e a játék
int kivant_nehezsegi_szint (int kerdesek_csoportositva[], int nehezsegfajtak){///A játékos kiválasztja az általa kívánt nehézségi szintet amin a játék futni fog
    printf("Milyen nehézségi szinten szeretne játszani? Adjon meg egy számot 1 és %d között\n", nehezsegfajtak);
    int nehezsegi_szint;/*!A bekért nehézségi szintet tárolja*/
    char* sor = sor_be(stdin);/*!Beolvassa a consolra írt sort az enterig */
    nehezsegi_szint = atoi(sor);/*!Átalakítja integerré a beolvasott adatot, ha sikertelen 0-at vissza*/
    free(sor);/*!Majd a sort felszabadítja*/

    if (nehezsegi_szint <= nehezsegfajtak && nehezsegi_szint > 0) {/*!Ha a formátum helyes */
        if (kerdesek_csoportositva[nehezsegi_szint-1] >=15){/*!És van elég kérdés a játékhoz*/

                return nehezsegi_szint;/*!Visszaadja a bekért nehézségi szintet*/
        }
    }

    //!Ha nem lehet a bekért nehézségi szinten játszani
    printf("Ilyen nehézségi szinten sajnos jelenleg nem tud játszani, kérem válasszon egy másik nehézségiszintet\n");
    return kivant_nehezsegi_szint(kerdesek_csoportositva, nehezsegfajtak);/*!Rekurzívan addig kér be amíg futtatható értéket nem kap*/
};

//!Kiír a consol-ra egy kérdést és a hozzá tartózó válaszlehetőségeket
ker_csop_tomben kerdes_felteves (ker_csop_tomben *kerdesektarhaza[], int kerdesek_csoportositva[], int nehezsegi_szint){
    int index;/*!Az adott nehézségi szinthez tartózó kérdések közül kisorsol egy indexet*/
    ///
    /// Megfelelően sok kérdéssel véges időn belül véget ér a ciklus.
    ///
    do {
        index = rand() % (kerdesek_csoportositva[nehezsegi_szint - 1]);/*!Belerakja a generált maximálisan a nehézségi kérdéshez tartozó maximális nagyságú számot*/
    } while (kerdesektarhaza[nehezsegi_szint-1][index].hasznalt);/*!Addig ameddig olyat nem talál amit még nem használt*/

    ker_csop_tomben kerdes = kerdesektarhaza[nehezsegi_szint-1][index];/*!A kisorsolt kérdést eltárolja helyileg*/
    printf("%s\n", kerdes.kerdes);
    printf("A: %s     B:%s\nC: %s     D:%s\n", kerdes.a, kerdes.b, kerdes.c, kerdes.d);
    kerdesektarhaza[nehezsegi_szint-1][index].hasznalt=true;
    return kerdes;
};


//!Bekér egy sort és visszatér az első karakterével. A hibás felhasználói bemenet kezelése miatt szükséges.
static char karakter_beker() {
    char* sor = sor_be(stdin);
    if (strlen(sor)>1){
        free(sor);
        printf("Érvénytelen válasz! Kérem próbálkozzon újra!\n");
        return karakter_beker();/*!Rekurzív amíg nem kap helyes értéket*/
    }
    char c = sor[0];
    free(sor);
    return c;/*!Visszaadja a sort*/
}

//!A felezés segítség kérése esetéán fut le és eltűntet 2 rossz válaszlehetőséget
static void felezes(ker_csop_tomben kerdes){
    int helyes = kerdes.helyes - 'A';/*!ASCII alapján 0-3ig kap egy számot ami a helyes válaszé*/
    char valaszok[4]={'A','B','C','D'};/*!A valid válaszlehetőségeket tárolja*/
    char rosszak[3];/*!Mivel 3 rossz válaszlehetőség van*/
    int j = 0;/*!A rosszak indexeléséhez számláló*/
    for (int i = 0; i < 4; ++i) {/*!Mindegyik válaszlehetőségre*/
        if (i != helyes) {
            rosszak[j]=valaszok[i];/*!Ha nem a helyesnél vagyunk akkor belemásolja a j helyre a rossz válaszlehetőséget*/
            j++;
        }
    }
    int kiirasi_sorrend = rand() % 2;/*!Sorsolás a kiírási sorrendhez*/
    int rosszkerdes = rand() % 3;/*!Sorsolás hogy melyik rosz válaszlehetőséget írja ki a jó mellé*/
    char out[2];/*!Kiíráshoz tárolja véletlen sorrendben a jó és a rossz választ*/
    out[kiirasi_sorrend]=rosszak[rosszkerdes];/*!A rossz kérdést belerakja a random indexű helyre*/
    out[1-kiirasi_sorrend]=kerdes.helyes;/*!Mivel 1 és 0 lehet a random szám így ha 1 volt a rossz index akkor 1-1=0, ha pedig 0 akkor 1-0=0 lesz a jó indexe*/
    printf("%c és %c között van a jó válasz\n", out[0], out[1]);
}

//!A közönség szavazata segítség kérésekor százalékosan kiír 4 számot melyek összege 100, és a legmagasabb szám a helyes megoldásé
static void kozonseg_szavazata(ker_csop_tomben kerdes){
    int szazalekok[4]; /*! A 4. elem biztosan a jo valasz*/
    int r=rand()%100;/*!0 és 99 közötti random szám*/
    //!Mindenképpen egy 50-nél nagyobb számot kap a helyes megoldás
    if (r<50) szazalekok[3]=100-r;
    else szazalekok[3]=r;

    int maradek=100-szazalekok[3];/*!A helyes megoldás által hagyott maradék százalék a további felosztáshoz*/
    for (int i = 0; i < 2; ++i) {/*!A maradék válaszlehetőségek-1 szer fut le*/
        szazalekok[i]=rand()%maradek;/*!max maradék nagyságú számot kap az i indexű válaszlehetőség*/
        maradek-=szazalekok[i];/*!A maradék százalékot csökkenti az előbb kisorsolt számmal*/
    }
    szazalekok[2]=maradek;/*!Az utolsó rossz megoldáshoz pedig a maradékot rendeli*/

    printf("A nézők szavazatai: \n");

    int j=0;/*!Változó a rossz válaszlehetőségekhez tartozó százalékok indexeléséhez*/

    //!Kiírja az össues válaszlehetőséget és a hozzájuk társított százalékokat
    for(int i = 0; i < 4; i++) {
        if(kerdes.helyes - 'A' == i) {
            printf("%c: %d%% ", kerdes.helyes, szazalekok[3]);
        }
        else {
            printf("%c: %d%%  ", i + 'A', szazalekok[j]);
            j++;
        }
    }
    printf("\n");
}

//!A segítségkérések vezérlése
void segitseg_keres(ker_csop_tomben kerdes, bool *felezes_hasznaltsag, bool *kozonseg_szavazata_hasznaltsag){
    if (*felezes_hasznaltsag && *kozonseg_szavazata_hasznaltsag) return;/*!Ha már nincs lehetősége segítséget hazsnálni akkor nem fut le*/
    printf("Szeretne segítséget használni? (F ha a felezést, K ha a közönség szavazatát és N ha nem szeretne segítséget használni)\n");
    char in = (char)toupper(karakter_beker());/*!Bekér egy karaktert amit naggyá alakít*/
    switch (in) {
        case 'F':
            if(!(*felezes_hasznaltsag)){
                /**
                 * Ha van még lehetősége felezést használni akkor végrehajtja és a használtságot igazra állítja
                 */
                felezes(kerdes);
                *felezes_hasznaltsag = true;
            } else{
                printf("Ezt a segítséget már használta\n");
                segitseg_keres(kerdes, felezes_hasznaltsag, kozonseg_szavazata_hasznaltsag);/*!Ha nincs, akkor rekurzív*/
            }
            break;
        case 'K':
            if (!(*kozonseg_szavazata_hasznaltsag)) {
                /**
                 * Ha van még lehetősége használni akkor végrehajtja és a használtságot igazra állítja
                 */
                kozonseg_szavazata(kerdes);
                *kozonseg_szavazata_hasznaltsag = true;
            } else {
                printf("Ezt a segítséget már használta\n");
                segitseg_keres(kerdes, felezes_hasznaltsag, kozonseg_szavazata_hasznaltsag);/*!Ha nincs akkor rekurzív*/
            }
            break;
        case 'N':
            break;
        default: {
            printf("Érvénytelen válasz.\n");
            /**
             * Ha nem jó formátumú a válasz akkor rekurzív
             */
            segitseg_keres(kerdes, felezes_hasznaltsag, kozonseg_szavazata_hasznaltsag);
        }
    }
}

//!A játékos válaszát kiértékeli és ha rossz a formátum rekurzívan fut
bool valasz_beker(ker_csop_tomben kerdes){
    char in = karakter_beker();/*!Eltárolja a beolvasott karaktert*/
    in = (char)toupper(in);/*!Nagybetűssé teszi*/
    if (in==kerdes.helyes) return true;/*!Ha a válasz helyes igazat ad vissza*/
    else if (in >= 'A' && in <= 'D')
        /**
         * Ha nem igaz akkor hamisat
         */
        return false;
    else {
        /**
         * Ha pedig nem jó az adott válasz formátuma akkor rekurzív
         */
        printf("Érvénytelen válasz!\n");
        return valasz_beker(kerdes);
    }
};