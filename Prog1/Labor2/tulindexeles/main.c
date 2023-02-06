#include <stdio.h>
#include <stdbool.h>
int main() {
    int tomb[10];

    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10;

    int i = 0;
    while (true) {
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }
    return 0;
}
//1. A tömb méretét meghaladó elemek random értéket kapnak
//2. A tru feltétel állandóan igazzá teszi a while feltételét ezért infinite loopba kerül