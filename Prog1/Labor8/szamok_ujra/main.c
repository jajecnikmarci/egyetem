#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"


int main() {
    int meret =0;
    double *t= (double*) malloc(0*sizeof (double));
    double beker;
    scanf("%lf",&beker);
    while ( beker!=-1.0){

        double *t_uj= (double*) malloc((meret+1)*sizeof (double));
        for (int i = 0; i < meret; ++i) {
            t_uj[i]=t[i];
        }
        free(t);
        t_uj[meret]=beker;
        t=t_uj;
        meret++;
        scanf("%lf",&beker);
    }
    for (int i = meret; 0 < i; i--) {
        printf("%g\n",t[i-1]);
    }
    free(t);
    return 0;
}
