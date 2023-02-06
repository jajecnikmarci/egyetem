#include <stdio.h>

int main(void) {
    double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };

    /* Az eredeti tömb kiírása */
    printf("Összesen %d szám van.\n", 10);
    for (int i = 0; i < 10; ++i)
        printf("[%d]=%g ", i, szamok[i]);
    printf("\n\n");

    /* Negatívak indexeinek kigyűjtése */
    int nindex[10];
    int szamlalo=0;
    for (int i = 0; i < 10; ++i) {
        if (szamok[i]<0){
            nindex[szamlalo]=i;
            szamlalo++;
        }
    }
    printf("Ebből %d szám negatív.\n",szamlalo);
/*    printf("Indexeik: ");
    for (int i = 0; i < szamlalo; ++i) {
        printf("%d ",nindex[i]);
    }*/
    /* Negatívak kiírása */
    for (int i = 0; i < szamlalo; ++i) {
        printf("[%d]=%g ",nindex[i], szamok[nindex[i]]);
    }
    return 0;
}