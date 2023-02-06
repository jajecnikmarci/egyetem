#include <stdio.h>
/*
 * - szöveg vátozóba
 * szám bekérése egész változóba
 * + írása új sorba
 * for ciklussal bekért mennyiségű - kiírás
 * + kiírása
 * */

int main() {
    char a='-';
    printf("Mekkora legyen a szakasz?: ");
    int db;
    scanf("%d",&db);
    printf("+");
    for (int i = 0; i < db; ++i) {
        printf("%c", a);
    }
    printf("+");
    return 0;
}
