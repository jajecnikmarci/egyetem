#include <stdio.h>

int main(void) {
    signed char i = 1;
    while (i > 0) {
        ++i;
    }
    printf("%d\n", i);

    return 0;
}