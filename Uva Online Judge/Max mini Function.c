#include <stdio.h>
double max(double a, double b)
{
    double big;
    if (a>b){
        big = a;
    }
    else if (a<b){
        big = b;
    }
    return big;
}
double min (double a, double b)
{
    double small;
    if (a>b){
        small = b;
    }
    else if (b>a){
        small = a;
    }
    return small;
}
int main ()
{
    double x, y, i, j;
    scanf("%lf%lf", &x, &y);
    printf("Maximum = %lf\n", max(x,y));
    printf("Minimum = %lf\n", min(x,y));
    return 0;
}
