#include <stdio.h>

void func1(int i2) {
    i2 *= 2;
    printf("func1()... i2 = %d\n", i2);     /* 4 */
    //i2-t szorozzuk kettővel majd kiírjuk
}

void func2(int *p3) {
    *p3 *= 2;
    printf("func2()... *p3 = %d\n", *p3);
    //p3 értékének kiírása
    p3 = NULL;                              /* 5, 6 */
    printf("func2()... p3 = %p\n", p3);
    //Mivel p3 helye a memóriában null így az íródik ki
}

int main(void) {
    int i1 = 2;
    int *p1 = NULL;
    int *p2 = NULL;
    printf("Hova mutat p1 es p2?\n");      /* 1 */
//A memóriában elfoglalt helyére mutat
    p1 = &i1;
    printf("&i1 = %p, p1 = %p\n", &i1, p1);

    printf("i1 = %d, *p1 = %d\n", i1, *p1); /* 2 */
//Mivel a p1 az i1re mutat így megörökli az értékét
    i1 = 3;  printf("*p1 = %d\n", *p1);
    //Mivel hely szerint lett átvéve így örökli az értékét
    *p1 = 4; printf("i1 = %d\n", i1);
//Megváltoztattuk a pointer értékét és így az i1 változóét is
    p2 = p1;
    *p2 = 5;
    printf("i1 = %d, p2 = %p\n", i1, p2);   /* 3 */
    //Az i1 értékét és a p2 memóriában elfoglalt helye
    printf("-----\n");

    func1(i1);
    printf("main()... i1 = %d - de miert?\n", i1);
    //Mivel az i1 értéke 5 volt és azon nem változtattunk csak paraméternek adtuk meg a függvényhez így az értéke nem változik
    printf("-----\n");

    func2(&i1);
    printf("main()... i1 = %d - miert?\n", i1);
    //i1-re mutató pointer értéke a duplájára nőtt így az i1 is
    printf("-----\n");

    func2(p2);
    printf("main()... i1 = %d - miert?\n", i1);
    //i1-re mutató pointer értéke a duplájára nőtt így az i1 is
    printf("main()... p2 = %p - miert?\n", p2);
    //p2 memóriában elfoglalt helyét írja ki
    return 0;
}