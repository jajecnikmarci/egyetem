#include <stdio.h>
#include <math.h>
double kob(double x){
    return x*x*x;
}
double abszolut(double y){
    if (y<0)
        y=y*-1;
    return y;
}

int main() {
    double a=-1;
    while (a<=1){
        printf("%0.4f\n",a);
        printf("%0.4f\n",kob(a));
        printf("%0.4f\n",abszolut(a));
        printf("%0.4f\n\n", sin(a));
        a=a+0.1;
    }
    return 0;
}
