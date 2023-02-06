#include <stdio.h>

int* keres(int *t, int meret, int keresett){
    for (int i = 0; i < meret; ++i) {
        if (t[i]==keresett){
            return &t[i];
        }
    }
    return NULL;
}

int main() {
    int keresett=10;
    int t[10]={1,2,3,4,5,6,7,8,9,10};
    int keresett_index=keres(t,10, keresett);
    for (int i = 0; i < 10; ++i) {
        printf("[%d]=%d  ",i,t[i]);
    }
    if (keresett_index==-1)
        printf("\nNincs találat");
    else
        printf("\nindex=  %d", keres(t,10, keresett));

    return 0;
}
