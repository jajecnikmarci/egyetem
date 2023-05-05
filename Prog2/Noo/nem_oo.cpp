#include <cstring>
#include <cctype>
#include "string.h"
#include "nem_oo.h"

namespace sajat{
/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodop2,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

int atoi(const char *p, int base) {
    int result = 0;
    int i = 0;

    while (p[i] != '\0' && !isspace(p[i])) {
        result = result * base + p[i] - '0';
        if (p[i]-'0' >= base) throw "dmb3ad";
        i++;
    }
    return result;
}

char* strcat(const char *p1, const char *p2) {
    int hossz1= std::strlen(p1);
    int hossz2= std::strlen(p2);
    char* result=new char[hossz1+hossz2+1];
    std::strcpy(result,p1);
    std::strcat(result,p2);
    return result;
}

char* unique2(char *first, char *last) {
    char* elozo=first;
    first++;
    while (first!=last){
        if (*elozo==*first){
            char* iter=first;
            while (iter!=last){
                *iter=*(iter+1);
                iter++;
            }
            first--;
            last--;
        }
        elozo=first;
        first++;
    }
    *last='\0';
    return last;
}

int strlen(char* first, char* last){
    char* iter = first;
    int res=0;
    while (iter!=last){
        res++;
        iter++;
    }
    return res;
}

void strcpy(char* hova, char* honnan, int mennyit){
    int i=0;
    while (i<mennyit) hova[i]=honnan[i];
}

char* unique(char* first, char* last){
    char* og=first;
    int l= sajat::strlen(first,last);
    char* result= new char[l+1];
    char elozo=*og;
    result[0]=*og;
    first++;
    l=1;
    while (first!=last){
        if (*first!=elozo) {result[l]=*first; l++;}
        elozo=*first;
        first++;
    }
    sajat::strcpy(og,result,l);
    og[l]='\0';
    first=og;
    last=&og[l];
    delete[] result;
    return last;
}

}

