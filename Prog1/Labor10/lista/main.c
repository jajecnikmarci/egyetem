#include <stdlib.h>
#include <stdio.h>
typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}

int hossz(ListaElem* eleje){


    ListaElem *mozgo;
    int i=0;

    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        i++;
    }
    return i;
}

ListaElem* Elso_elem (ListaElem* eleje, int adat){
    ListaElem *uj;
    uj= (ListaElem*) malloc(sizeof(ListaElem));
    uj->kov= eleje;
    uj->adat=adat;
    eleje=uj;
    return uj;
}

ListaElem* Utolso(ListaElem* eleje, int adat){
    ListaElem *uj;
    uj= (ListaElem*) malloc(sizeof(ListaElem));
    ListaElem* mozgo=eleje;
    while (mozgo->kov!=NULL) mozgo=mozgo->kov;
    (*mozgo).kov=uj;
    (*uj).kov=NULL;
}

ListaElem* keres(ListaElem* eleje, int adat){
    ListaElem* mozgo=eleje;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        if (mozgo->adat==adat) return mozgo;
    }
    return NULL;
}

int main(void) {
    ListaElem *eleje;

    eleje = lista_letrehoz();

    ListaElem *mozgo;
    int i=0;

    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
        printf("%d ", mozgo->adat);
        i++;
    }
    printf("\n%d",hossz(&eleje));

    Elso_elem(&eleje,20);

    Utolso(&eleje, 333);

    keres(&eleje, 55);
    ListaElem *iter;
    while (iter != NULL) {
        ListaElem *kov = iter->kov; /* következő elem */
        free(iter);
        iter = kov;
    }
    printf("\nFelszabadítva");
    return 0;
}