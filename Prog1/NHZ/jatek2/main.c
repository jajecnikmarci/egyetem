#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "beolvas.h"
#include "jatek.h"
#include "dicsoseglista.h"
#include <time.h>
#include "debugmalloc.h"

int main() {
    srand(time(0)); /*!< Időkövetés implementálása */

    ///A beolvasás kezdete
    Kerdes *kerdesekLacoltban;/*!<Kérdéseket tároló lácolt lista */
    if ((lancoltbaolvas(&kerdesekLacoltban)) == -1) {/*!Tesztelés a beolvasás sikerességére */
        printf("Beolvasási hiba");
        return 0;
    };
    int *kerdesek_csoportositva;/*!Nehézségi szintek alapján megszámolja, hogy mennyi kérdés található az adott nehézségi szintből*/
    int nehezsegfajtak=0;/*!A nehézségi szinteket száma */
    if ((nehezsegfajtak=kerdest_csoportosit(kerdesekLacoltban, &kerdesek_csoportositva)) == -1) {/*!Tesztelés a  sikerességére */
        printf("Beolvasási hiba");
        return 0;
    };
    ker_csop_tomben** neh_csop_tomb_tomb; /*!nehezsegek_alapjan_csoportositott_tombok_tombje ami egy 2 dimenziós tömb mely nehézségek alapján csoportosítva tárolja a kérdéseket*/
    if ((neh_csop_tomb_tomb = csop_tomb_belerak(kerdesekLacoltban, nehezsegfajtak, kerdesek_csoportositva)) == NULL) {/*!Tesztelés a foglalás sikerességére */
        printf("Beolvasási hiba");
        return 0;
    };
    ///A beolvasás vége

    ///A játék kezdete
    int nehezsegiszint = kivant_nehezsegi_szint(kerdesek_csoportositva, nehezsegfajtak);/*!A játékos által választott nehézségi szint eltárolása */
    int nyeremenyek[15] = {5000, 10000, 25000, 50000, 100000, 200000, 300000, 500000, 800000, 1500000, 3000000, 5000000, 10000000, 20000000, 40000000};/*!A nyereményeket egy tömbben tárolja el */

    int jatekeleje = (int)time(NULL); /*! A játék kezdetének időpontját eltárolja egy változóban*/

    bool felezes_hasznaltsag=false; /*!Felezés segítség használtságának számontartásához */
    bool kozonseg_szavazata_hasznaltsag=false;/*!Közönség segítségének segítség nyilvántartásához */

    printf("\n\nÜdvözlöm önt a legyen ön is milliomos játékban!\n"
           " A játék célja hogy megválaszoljon minnél több kérdést helyesen\n"
           "Amennyiben 15 kérdést hibátlanul megválaszol sorozatban ön megnyeri a főnyereményt\n"
           "A játékban 2 fajta segítség áll a rendelkezésére, a felezést és a közönség segítségét\n"
           "A felezéskor a gép elvesz 2 rossz válaszlehetőséget, így önnek 50-50% esélye lesz a helyes válaszra\n"
           "A közönség segítségének kérésekor %%-os formában kap meg értékeket ami alapján elndönthati, hogy melyik válaszlehetőséget választja\n"
           "Minden segítséget csak egyszer tud felhasználni a játék alatt\n\n"
           "Jó játékot!");

    int szint=0;/*!A játékos haladásának nyomonkövetésére szolgál */
    for (; szint < 15; ++szint) {/*!15 kérdésből áll a játék */
        printf("\n%d Forintért íme a %d. kérdés.\n",nyeremenyek[szint],szint+1);/*!Jelenlegi szont kiírási a következő nyereményért */
        ker_csop_tomben kerdes = kerdes_felteves(neh_csop_tomb_tomb,kerdesek_csoportositva,nehezsegiszint);/*!Kiír egy kérdést és eltárolja  */
        segitseg_keres(kerdes, &felezes_hasznaltsag, &kozonseg_szavazata_hasznaltsag);/*!Amennyiben még maradt segítsége felméri hogy szeretné-e használni azt */
        printf("Adja meg a válaszát!\n");
        bool helyes = valasz_beker(kerdes);/*!Ellenőrzi a helyességét a válasznak */
        if (!helyes) {
            printf("Sajnos rossz a válasz.\n");
            if (szint > 0) {
                printf("Az ön nyereménye:%d Forint. Sok szerencsét legközelebb!\n", nyeremenyek[szint - 1]);
            }
            /**Ha nem helyes a válasz kiírja a nyereményt és kilép a ciklusból*/
            break;
        } else printf("Helyes válasz\n");
    }
    if (szint==15) printf("Gratulálunk ön megnyerte a főnyereményt (%d Forint)!\n", nyeremenyek[14]);/*!Ha az összes kérdést helyesen megválaszolta akkor fut le */
    int jatekido = (int)time(NULL) - jatekeleje;/*!A játék kezdetekor elmentett időből kiszámítja a játékban töltött időt */
    ///A játék vége

    ///Kiértékelés kezdete
    Eredmeny eredmeny;/*!A játék kimenetelét tárolja el */
    eredmeny.ido = jatekido;/*!A játékban töltött idő */
    eredmeny.megvalaszolt = szint;/*!A helyesen megválaszolt kérdések száma */

    printf("\nAdja meg a játékosnevét:\n");
    eredmeny.jatekosnev = sor_be(stdin);/*!Bekéri a játékos nevét a dicsőséglistába íráshoz */
    dicsoseglistat_kezel(eredmeny, nehezsegiszint, nyeremenyek);/*!Betölti a dicsőséglistát, kezeli, kiírja a consolra és a hozzá tartozó fájlba */
    ///Kiértékelés vége

    //!Felszabadítja az eltárolt kérdéseket
    kerdeseket_felszabadit(neh_csop_tomb_tomb, kerdesek_csoportositva, nehezsegfajtak);

    ///Minden fel lett szabadítva és bezárva, így a program lezárul
    return 0;
}


