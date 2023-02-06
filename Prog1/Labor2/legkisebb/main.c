#include <stdio.h>

int main() {
    int t[10]= {25,69,54,8,77,6,29,10,3,98};
//    printf("A tömb: ");
//    for (int i = 0; i < 10; ++i) {
//        printf("[%d]=%d ",i,t[i]);
//    }
    int legkisebb=t[0];
    int legkisebb_hely;
    for (int i = 0; i < 10; ++i) {
        if (t[i]<legkisebb){
            legkisebb=t[i];
            legkisebb_hely=i;
        }
    }
//    printf("\nA legkisebb szám: %d",legkisebb);
//    printf("\nA legkisebb szám indexe: %d",legkisebb_hely);
    printf("Jelölve:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d",t[i]);
        if (i==legkisebb_hely)
            printf("[MIN]");
    }
    return 0;
}
