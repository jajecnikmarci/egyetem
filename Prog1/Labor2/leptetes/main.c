#include <stdio.h>

int main() {
    char t[10]={'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z', };
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%c ",t[j]);
        }
        printf("\n");
        char temp= t[0];
        for (int j = 0; j < 9; ++j) {
            t[j]=t[j+1];
        }
        t[9]=temp;
    }
    return 0;
}
