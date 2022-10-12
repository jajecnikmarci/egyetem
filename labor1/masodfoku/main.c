#include <stdio.h>
#include <math.h>

int main() {
    printf("Mekkora a x negyzet egyutthatoja?: ");
    double elso;
    scanf("%lf", &elso);
    printf("Mekkora az x egyutthatoja?: ");
    double masodik;
    scanf("%lf", &masodik);
    printf("Mekkora a konstans?: ");
    double konstans;
    scanf("%lf", &konstans);
    double diszkriminans= (masodik*masodik)-(4*elso*konstans);
    if (diszkriminans>=0)
        diszkriminans= sqrt(diszkriminans);
    if(diszkriminans==0)
        printf("Egy valos megoldas van");
    else if(diszkriminans<0)
        printf("0 valos megoldas van");
    else printf("2 valos megoldas van");
    return 0;
}
