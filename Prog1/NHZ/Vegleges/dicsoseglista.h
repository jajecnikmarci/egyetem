///
/// Created by Jajecnik Marcell on 2022. 12. 02..
///@author Jajecnik Marcell
///

#ifndef JATEK2_MENTES_H
#define JATEK2_MENTES_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "beolvas.h"
#include "debugmalloc.h"

//!Egy játék eredményeit tárolja
typedef struct Eredmeny {
    char* jatekosnev;/*!A játékot játszó játékos játékosneve */
    int megvalaszolt;/*!A játékos által helyesen megválaszolt kérdések száma */
    int ido;/*!A játékos által játékban töltött idő másodpercben kifejezve */
} Eredmeny;

//!A dicsőséglistát beolvassa az adott nehézségi szinthez, betölti, szerkeszti, rendezi, majd kiírja azt a consol-ra és a hozzá tartozó fájlba
void dicsoseglistat_kezel(Eredmeny eredmeny, int nehezsegiszint, int nyeremenyek[]);

#endif //JATEK2_MENTES_H
