#include <stdio.h>
int main ()
{
    int prod1, prod2, a, b;
    double c,d, hudai;
    scanf("%d%d%lf%d%d%lf", &prod1, &a, &c, &prod2, &b, &d);
    hudai = ((a*c)+(b*d));
    printf("VALOR A PAGAR: R$ %0.2lf\n", hudai);
    return 0;
}
