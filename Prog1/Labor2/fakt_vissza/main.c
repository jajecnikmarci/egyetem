#include <stdio.h>

int main() {
    int szorzat=1;
    int n=8;
    while (n>1){
        szorzat*=n;
        n--;
    }
    printf("%d\n", szorzat);
    return 0;
}
//amikor 3ra vált 6720 az értéke