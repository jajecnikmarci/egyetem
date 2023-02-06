//
// Created by Jajecnik Marcell on 2022. 11. 12..
//

#include "indit.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "debugmalloc.h"

int kerdeseketszamol (){
    FILE *fk;
    fk= fopen("kerdes.csv","r");
    int ossze_kerdes_szama=0;
    if (fk==NULL) {
        return 0;
    }
    char in= fgetc(fk);
    while (in!=EOF) {
        if (in=='\n'){
            ossze_kerdes_szama++;
        }
        in= fgetc(fk);
    }
    fclose(fk);
    return ossze_kerdes_szama;
}
int sorhosszokatszamol (int *sorhosszok){
    FILE *fk;
    fk= fopen("kerdes.csv","r");
    if (fk==NULL) {
        return 0;
    }
    int ossze_kerdes_szama=0;
    char in= fgetc(fk);
    while (in!=EOF) {
        int db=0;
        while (in!='\n') {
            in= fgetc(fk);
            db++;
        }
        if (in=='\n'){
            sorhosszok[ossze_kerdes_szama]=db;
            ossze_kerdes_szama++;
        }
        in= fgetc(fk);
    }
    fclose(fk);
    return sorhosszok;
}

void kerdestfelszabadit (kerdesek *kerdes){
    free(kerdes->kerdes);
    free(kerdes->A);
    free(kerdes->B);
    free(kerdes->C);
    free(kerdes->D);
    free(kerdes->kategoria);
    free(kerdes);
    return;
}
//ezt a függvényt alakítom át alább éppen
kerdesek* kerdest_berak(char *sor, kerdesek *kerdesek, int eddig_beolvasott_kerdes, int beolvasott_karakter){
    char sor_tomb[beolvasott_karakter];
    char *kerdes[beolvasott_karakter];
    char *a[beolvasott_karakter];
    char *b[beolvasott_karakter];
    char *c[beolvasott_karakter];
    char *d[beolvasott_karakter];
    char *kategoria[beolvasott_karakter];

    strcpy(sor_tomb,sor);
    printf("%s\n",sor_tomb);
    int nehezseg= strtok(sor_tomb,";");
    kerdesek[eddig_beolvasott_kerdes-1].nehezseg=nehezseg;
    printf("%d\n",nehezseg);
    printf("%s\n",sor_tomb);
    *kerdes= strtok(NULL,";");
    printf("%s\n",sor_tomb);
    *a=strtok(NULL,";");
    *b=strtok(NULL,";");
    *c=strtok(NULL,";");
    *d=strtok(NULL,";");
    *kategoria=strtok(NULL,";");

    //nehézségnek külön tömb, de a többinek egyesével létre kell hozni az strcopy miatt



    strcpy(kerdesek[eddig_beolvasott_kerdes-1].kerdes,kerdes);
    printf("%s\n",kerdesek[eddig_beolvasott_kerdes-1].kerdes);
    strcpy(kerdesek[eddig_beolvasott_kerdes-1].A,a);


    strcpy(kerdesek[eddig_beolvasott_kerdes-1].B,b);

    strcpy(kerdesek[eddig_beolvasott_kerdes-1].C,strtok(NULL,";"));
    strcpy(kerdesek[eddig_beolvasott_kerdes-1].D,strtok(NULL,";"));
    kerdesek[eddig_beolvasott_kerdes-1].helyes=strtok(NULL,";");
    kerdesek[eddig_beolvasott_kerdes-1].kategoria=strtok(NULL,";");
    return kerdesek;
}

 void lefoglal(kerdesek *kerdesbe, int *sorhosszok, int osszes_kerdes_szama){
     for (int i = 0; i <osszes_kerdes_szama ; ++i) {
         kerdesbe[i].kerdes= (char*) malloc(sizeof (char)*sorhosszok[i]);
         kerdesbe[i].A= (char*) malloc(sizeof (char)*sorhosszok[i]);
         kerdesbe[i].B= (char*) malloc(sizeof (char)*sorhosszok[i]);
         kerdesbe[i].C= (char*) malloc(sizeof (char)*sorhosszok[i]);
         kerdesbe[i].D= (char*) malloc(sizeof (char)*sorhosszok[i]);
         kerdesbe[i].kategoria= (char*) malloc(sizeof (char)*sorhosszok[i]);
     }
}

kerdesek* kerdesbetolt (kerdesek* kerdes){
    int beolvasott_kerdesek_szama = 0;
    int ossze_kerdes_szama= kerdeseketszamol();
    int *sorok_hossza[ossze_kerdes_szama];
    sorhosszokatszamol(sorok_hossza);
    FILE *fp;
    fp= fopen("kerdes.csv","r");
    if (fp==NULL) return false;
    char c_in = fgetc(fp);
    kerdesek kerdesbe[ossze_kerdes_szama];
    lefoglal(kerdesbe, sorok_hossza, ossze_kerdes_szama);
    //mivel a sorhosszámolás miatt tudom hogy mennyi a hossza for ciklussal be tudom sokkal egyszerűbben olvasni a sorokat.
    for (int i = 0; i < ossze_kerdes_szama; ++i) {

        int sorhossz = sorok_hossza[beolvasott_kerdesek_szama];
        char *sor = (char*) malloc(sizeof(char) * sorhossz);
        sor[sorhossz-1] = '\0';

        /*while (c_in != '\n') {

            char *ujtomb = (char *) malloc(sizeof(char) * (db + 1 + 1));
            for (int i = 0; i < db; ++i)
                ujtomb[i] = sor[i];
            free(sor);
            sor = ujtomb;
            ujtomb[db] = c_in;
            ujtomb[db + 1] = '\0';
            ++db;
            printf("%c",c_in);
            c_in = fgetc(fp);
        }*/
        for (int i = 0; i < sorhossz-1; ++i) {
            sor[i]=c_in;
            c_in= fgetc(fp);
        }
        kerdest_berak(sor, kerdesbe, beolvasott_kerdesek_szama, sorhossz);
        beolvasott_kerdesek_szama++;
        c_in = fgetc(fp);
        printf("%d",beolvasott_kerdesek_szama);
        free(sor);
    }
    kerdes=kerdesbe;
    printf("%d",beolvasott_kerdesek_szama);
    kerdestfelszabadit(kerdesbe);
    fclose(fp);
    return true;
}