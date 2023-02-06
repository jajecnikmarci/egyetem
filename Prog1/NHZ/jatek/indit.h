//
// Created by Jajecnik Marcell on 2022. 11. 12..
//

#ifndef JATEK_INDIT_H
#define JATEK_INDIT_H
#include <stdbool.h>

typedef struct kerdesek {
    int nehezseg;
    char* kerdes;
    char* A;
    char* B;
    char* C;
    char* D;
    char helyes;
    char* kategoria;
}kerdesek;

int kerdeseketszamol();
kerdesek *kerdest_berak(char *sor, kerdesek *kerdesregi, int kerdesekszama, int beolvasott_karakter);
kerdesek* kerdesbetolt(kerdesek* kerdes);
int sorhosszokatszamol (int *sorhosszok);
void lefoglal(kerdesek *kerdesbe, int *sorhosszok, int osszes_kerdes_szama);
void kerdestfelszabadit (kerdesek *kerdes);
#endif //JATEK_INDIT_H
