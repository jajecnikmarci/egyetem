#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void sorban_kiir(BiFa *gyoker) {
    if (gyoker == NULL)   /* leállási feltétel */
        return;

    sorban_kiir(gyoker->bal);     /* 1 */
    printf("%d ", gyoker->ertek);     /* 2 */
    sorban_kiir(gyoker->jobb);    /* 3 */
}

void felszabadit(BiFa *gyoker) {
    if (gyoker == NULL)   /* leállási feltétel */
        return;

    felszabadit(gyoker->bal);     /* 1 */
    felszabadit(gyoker->jobb);       /* 2 */
    free(gyoker);                 /* 3 */
}

int elemszam(BiFa *gyoker, int db) {

    if (gyoker == NULL)   /* leállási feltétel */
        return db;

    db=elemszam(gyoker->bal,db);     /* 1 */
    db++;     /* 2 */
    db=elemszam(gyoker->jobb,db);
    return db;/* 3 */
}

int elemosszeg(BiFa *gyoker) {

    if (gyoker == NULL)   /* leállási feltétel */
        return 0;
    return (elemosszeg(gyoker->bal)+elemosszeg(gyoker->jobb)+gyoker->ertek);
}

int keres(BiFa *gyoker, int keresett, int *p) {

    if (keresett==gyoker->ertek) {
        p=gyoker->ertek;
        return p;
    }
    if (gyoker == NULL)   /* leállási feltétel */
        return NULL;

    if (keresett<gyoker->ertek) p=keres(gyoker->bal,keresett,p);     /* 1 */
     /* 2 */
    else p=keres(gyoker->jobb,keresett,p);
    return p;/* 3 */
}

void negal(BiFa *gyoker) {

    if (gyoker == NULL)   /* leállási feltétel */
        return;

    negal(gyoker->bal);     /* 1 */
    gyoker->ertek=(-1)*(gyoker->ertek);     /* 2 */
    negal(gyoker->jobb);
    return;/* 3 */
}

int keresnegaltban(BiFa *gyoker, int keresett, int *p) {

    if (keresett==gyoker->ertek) {
        p=gyoker->ertek;
        return p;
    }
    if (gyoker == NULL)   /* leállási feltétel */
        return p;

    if (gyoker->ertek<keresett) p=keresnegaltban(gyoker->bal,keresett,p);     /* 1 */
    /* 2 */
    if (keresett<gyoker->ertek) p=keresnegaltban(gyoker->jobb,keresett,p);
    return p;/* 3 */
}

BiFa* tukroz(BiFa *gyoker){
    if (gyoker == NULL)   /* leállási feltétel */ return gyoker;
    struct BiFa *temp;
    tukroz(gyoker->bal);
    tukroz(gyoker->jobb);
    temp=gyoker->bal;
    gyoker->bal=gyoker->jobb;
    gyoker->jobb=temp;
    return gyoker;
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */
    sorban_kiir(gyoker);
    int db=0;
    int osszeg=0;

    printf("\n%d\n", elemszam(gyoker,db));
    printf("%d\n", elemosszeg(gyoker));
    int keresett=14;
    int *p;
    p=keres(gyoker,keresett, p);
    printf("%d\n",p);
    gyoker= tukroz(gyoker);
    sorban_kiir(gyoker);
    /*negal(gyoker);
    keresett=(-1)*keresett;
    p=keresnegaltban(gyoker,keresett,p);
    printf("%d\n",p);*/

    felszabadit(gyoker);

    return 0;
}