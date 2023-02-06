///
/// Created by Jajecnik Marcell on 2022. 11. 22..
///@author Jajecnik Marcell
///

#ifndef JATEK2_BEOLVAS_H
#define JATEK2_BEOLVAS_H
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"

//!A kerdes struct egy beolvasott sor feldarabolt elemeit tárolja, ebből később egy láncolt listát építek, beolvasási sorrendben
typedef struct Kerdes{
    int nehezseg;/*!A kérdés nehézségi szintjét tárolja */
    char *kerdes;/*!A kérdést tárolja */
    char *a;/*!Az A válaszlehetőséget tárolja */
    char *b;/*!Az B válaszlehetőséget tárolja */
    char *c;/*!Az C válaszlehetőséget tárolja */
    char *d;/*!Az C válaszlehetőséget tárolja */
    char helyes;/*!A helyes válasz betűjelét tárolja tárolja */
    char *kategoria;/*!A kérdés kategóriáját tárolja */
    struct Kerdes* kov;/*!A következő elemre mutató pointer a láncolt listához */
}Kerdes;

//!A láncoltlistába olvasott kérdéseimet tárolja majd egy 2 dimenziós tömbben
typedef struct ker_csop_tomben{
    char *kerdes;/*!A kérdést tárolja */
    char *a;/*!Az A válaszlehetőséget tárolja */
    char *b;/*!Az B válaszlehetőséget tárolja */
    char *c;/*!Az C válaszlehetőséget tárolja */
    char *d;/*!Az C válaszlehetőséget tárolja */
    char helyes;/*!A helyes válasz betűjelét tárolja tárolja */
    char *kategoria;/*!A kérdés kategóriáját tárolja */
    bool hasznalt;/*!A kérdés használtságát jelzi*/
}ker_csop_tomben;

//!Beolvassa egy sor elemeit egy láncolt listába
int beolvas(Kerdes* kerdes, FILE *f);

//!A fájlból beolvas egy sort és azt egy karaktertömben visszaadja
char* sor_be (FILE *f);

//!A lácolt listában létrehoz egy új elemet a következő beolvasáshoz
void kerdest_beszur(Kerdes **peleje);

//!A beolvasott sort elemekre bontja és visszaadja a rájuk mutató pointereket tartalmazó tömböt
int token(char *sor,char *token_ptrek[]);

//!A forrásfájl összes sorát beolvassa és eltárolja egy láncolt listában és visszaadja a beolvasott kérdések darabszámát
int lancoltbaolvas(Kerdes **kerdesek_eredeti);

//!Megszámolja hogy hány nehézségfajta van és hogy a bizonyos nehézségfajtákból hány darab kérdés van
int* nehezsegeket_szamol(Kerdes* eleje, int *nehezsegfajtakszama);

//!A nehézségalapú csoportosítást letárolja és visszaadja a nehézségfajták számát
int kerdest_csoportosit (Kerdes *kerdesek, int **kerdesek_csoportositva);

//!A láncolt listában tárolt kérdéseket nehézség alapján csoportosítva belerakja egy 2 dimenziós tömbbe
ker_csop_tomben **csop_tomb_belerak(Kerdes *kerdesek_lacoltban, int nehezsegfajtak,int *kerdesek_csoportositva);

//!A láncolt listában tárolt kérdéseknek nincs szükség minden elemére de szükség van a használtságára a kérdésgenerálásnál később ezért konvertál
ker_csop_tomben konvertal(Kerdes* kerdes);

//!Felszabadítja a 2 dimenziós mátrixát a kérdéseknek a malloc-olás miatt a program lefutásának végén
void kerdeseket_felszabadit(ker_csop_tomben **kerdesek, int *kerdesek_csoportositva, int nehezsegfajtak);

#endif //JATEK2_BEOLVAS_H
