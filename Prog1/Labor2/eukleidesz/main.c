#include <stdio.h>

int main() {
    int a=11220;
    int b=2002;
    while (0<b){
        int temp=b;
        b=a%b;
        a=temp;
    }
    printf("A legnagyobb közös osztó: %d\n", a);
    return 0;
}
/b értéke 44
