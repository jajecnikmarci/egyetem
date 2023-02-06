#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Hány számot olvasson be? ");
    scanf("%d", &n);
    double *t= (double*) malloc(n*sizeof (double));
    for (int i = 0; i < n; ++i) {
        printf("%d. elem: ",i);
        scanf("%lf",(t+i));
    }
    for (int i = n; 0 < i; i--) {
        printf("Az %d. elem: %f\n", i, *(t+i-1));
    }
    free(t);
    return 0;
}
