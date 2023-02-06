//
// Created by Jajecnik Marcell on 2022. 09. 08..
// kerulet es terulet
#include <stdio.h>

int main() {
    double sugar;
    printf("Mennyi a kor sugara?");
    scanf("%lf", &sugar);
    double pi=3.1416;
    double terulet= sugar*sugar*pi;
    double kerulet=2*sugar*pi;
    printf("A kor kerulete: %f, a kor terulete: %f \n",kerulet,terulet);

    return 0;
}