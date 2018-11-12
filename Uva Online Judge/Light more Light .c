#include <stdio.h>
#include <math.h>
int main ()
{
    long long n, i, j, count;


    while (scanf("%lld", &n)==1){
            i=sqrt(n);
            if (n==0){
                break;
            }
            j = i*i;

            if (j==n){
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
    }
    return 0;
}
