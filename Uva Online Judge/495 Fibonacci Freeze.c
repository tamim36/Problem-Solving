#include <stdio.h>
int main ()
{
    long long fib, num,cs, i=0, j, prev=0,temp, pres=1;

    while (scanf("%lld", &cs)){
        if (cs==0){
            printf("The Fibonacci number for %lld is %lld\n", cs, prev);
        }
        else if (cs == 1){
            printf("The Fibonacci number for %lld is %lld\n", cs, pres);
        }
        else {
            cs = cs-1;

        while (i<cs){
            fib = prev+pres;
            temp = prev;
            prev=pres;
            pres=fib;
            i++;
        }
        printf("The Fibonacci number for %lld is %lld\n", cs+1, fib);
        }
    }
    return 0;
}
