///
/// Created by Jajecnik Marcell on 2022. 12. 01..
///@author Jajecnik Marcell
///

#ifndef JATEK2_KIFORGATOM_ONT_IS_A_PENZEBOL_H
#define JATEK2_KIFORGATOM_ONT_IS_A_PENZEBOL_H

#endif //JATEK2_KIFORGATOM_ONT_IS_A_PENZEBOL_H

#include <stdio.h>
#include "beolvas.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "debugmalloc.h"



//!Beolvassa a kivant nehezsegi szintet es visszater a felhasznalo altal latott ertekkel;
int kivant_nehezsegi_szint (int kerdesek_csoportositva[], int nehezsegfajtak);

//!Feltesz egy random kerdest az adott nehezsegi szintbol, visszater a kerdessel
ker_csop_tomben kerdes_felteves (ker_csop_tomben *kerdesektarhaza[], int kerdesek_csoportositva[], int nehezsegi_szint);

//!Igazzal ter vissza, ha helyes a valasz, kezeli az ervenytelen valaszokat
bool valasz_beker(ker_csop_tomben kerdes);

//!A játékos segítségkéréseit teszteli és végrehajtja ha jogosult rá
void segitseg_keres(ker_csop_tomben kerdes, bool *felezes_hasznaltsag, bool *kozonseg_szavazata_hasznaltsag);