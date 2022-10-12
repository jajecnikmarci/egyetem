#include <stdio.h>

int main() {
    double pi=3.1416;
    double  magassag;
    printf("Mekkora a magassag?");
    scanf("%lf", &magassag);
    double atmero;
    printf("Mekkora az atmeroje?");
    scanf("%lf", &atmero);
    double felulet=((2*(atmero/2)*(atmero/2)*pi)+(magassag*atmero*pi))/2;
    printf("%f doboz festek kell\n", felulet);
    return 0;
}
