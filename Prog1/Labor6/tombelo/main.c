#include <stdio.h>

void ite_elo (int *a, int meret){
    for (int i = 0; i < meret; ++i) {
        printf("%d ", a[i]);
    }
}

void ite_hat (int *a, int meret){
    for (int i = meret-1; 0 <= i; --i) {
        printf("%d ",a[i]);
    }
}

void rek_elo(int *b, int meret){
    if (meret==0) return;
    printf("%d ", b[0]);
    rek_elo(b+1,meret-1);
}
void rek_hatra(int *b, int meret){
    if (meret==0) return;
    printf("%d ", b[meret-1]);
    rek_hatra(b,meret-1);
}

int main() {
    int a[10]={1,2,4,6,9,103,26,9,66,72};
    int b[5]={92,01,23,10,45};
    ite_elo(a,10);
    printf("\n");
    ite_hat(a,10);
    printf("\n");
    rek_elo(b,5);
    printf("\n");
    rek_hatra(b,5);
    return 0;
}
