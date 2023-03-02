#include <iostream>

int main() {
    char neptun[] = "dmb3ad";
    for (int x=0; x<strlen(neptun); x++)
        putchar(toupper(neptun[x]));
    std::cout << std::endl;
    return 0;
}
