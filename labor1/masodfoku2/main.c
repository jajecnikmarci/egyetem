#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
    printf("Mekkora a másodfokú tag együtthatója?");
    scanf("%lf", &a);
    printf("Mekkora az elaőfokú tag együtthatója?\n");
    scanf("%lf", &b);
    printf("Mekkora a konstans?\n");
    scanf("%lf", &c);
    double diszkriminans=(b*b)-(4*a*c);
    double y;
    double z;
    if (diszkriminans>0){
        diszkriminans= sqrt(diszkriminans);
        y=((b*(-1))+diszkriminans)/(2*a);
        z=((b*(-1))-diszkriminans)/(2*a);
        printf("Az elso megoldás: %f", y);
        printf("Az második megoldás: %f", z);
    }
    if (diszkriminans==0){
        z=((b*(-1))-diszkriminans)/(2*a);
        printf("Az elso megoldás: %f", z);
    }
    else
        printf("Nincs valós megoldás!\n");

    return 0;
}
