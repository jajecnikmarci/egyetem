#include <stdio.h>

int main() {
    unsigned long long int ideig=0;
    int hossz=0;
    int i=0;
    while (0<=hossz) {
        unsigned long long int a= 1;
        a= a<<i;


        if(a<ideig){ printf(" elozo:%llu   Most: %llu, hossz:%d\n",ideig,a,hossz);
            break;}
        printf("%d.  %llu\n", i, a);
        ideig=a;
        hossz++;
        i++;
    }
    return 0;
}
