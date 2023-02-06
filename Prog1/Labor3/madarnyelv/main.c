#include <stdio.h>

int main(void) {
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            printf("%cv%c", c, c);
        else
            printf("%c", c);
    }

    return 0;
}