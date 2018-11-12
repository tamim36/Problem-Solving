#include <stdio.h>
int main ()
{
    long long i, num, res;
    while (scanf("%lld", &num)==1){
            res =1;
            if (num <0){
                break;
            }
        for (i=0; i<=num; i++){
            res = res+i;
        }
        printf("%lld\n", res);
    }
    return 0;
}
