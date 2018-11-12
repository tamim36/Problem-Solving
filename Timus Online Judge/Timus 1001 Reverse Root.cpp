#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned long long k;
    double ara[128*1024];
     int i=0, j;
    while (scanf("%llu", &k)){
            ara[i] = k;
        i++;
    }
    for (j=i-1; j>=0; j--){
        printf("%0.4lf\n", sqrt(ara[j]));
    }
    return 0;
}
