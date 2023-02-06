#include <stdio.h>
#include "debugmalloc.h"

int main() {
    char *t=(char*) malloc(sizeof (char )*0);
    char beker;
    int meret= 0;
    scanf("%c",beker);
    while (beker!="\n"){
        char *t_uj= (char *) malloc((meret+1)*sizeof (char ));
        for (int i = 0; i < meret; ++i) {
            t_uj[i]=
        }
        scanf("%c",beker);
    }
    free(t);
    return 0;
}
