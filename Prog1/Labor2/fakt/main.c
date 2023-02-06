#include <stdio.h>

int main() {
    int n=1;
    int szorzat=1;
    while (n<=8){
        szorzat=szorzat*n;
        n++;
    }
    printf("A szorzat: %d\n", szorzat);
    return 0;
}
