#include <stdio.h>

void kocka(double el, double *ter, double *fel){
    *ter=el*el*el;
    *fel=el*el*6;
}

int main() {
    double ter, fel;
    kocka(2.7, &ter,&fel);
    printf("terfogat:   %g, felszín:   %g", ter,fel);
    return 0;
}
