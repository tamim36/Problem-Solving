#include <stdio.h>
int main ()
{
    int r;
    double pi=3.14159, sphere;
    scanf("%d", &r);
    sphere = (4.0/3.0)*pi*r*r*r;
    printf("VOLUME = %0.3lf", sphere);
    return 0;
}
