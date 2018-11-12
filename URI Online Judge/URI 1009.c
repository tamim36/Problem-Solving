#include <stdio.h>
#include <string.h>
int main ()
{
    char name[100];
    double a, b, hudai;
    gets(name);
    scanf("%lf%lf", &a, &b);
    hudai = ((b*15)/100 + a);
    printf("TOTAL = R$ %0.2lf\n", hudai);
    return 0;
}
