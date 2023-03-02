#include <stdio.h>
#include "string.h"
#include "ctype.h"

int main() {
    char neptun[] = "dmb3ad";
    for (int x=0; x<strlen(neptun); x++)
        putchar(toupper(neptun[x]));
    printf("\n");
    return 0;
}