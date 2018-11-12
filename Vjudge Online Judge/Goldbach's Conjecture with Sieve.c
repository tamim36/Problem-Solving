#include <stdio.h>
int main ()
{
    int ara[1000];
    int prime[1000];
    int i, j, num;
    for (i=0; i<1000; i++){
        ara[i] = 0;
    }
    for (i=2; i<sqrt(1000); i++){
        if (ara[i] == 0){
            for (j=2; j*i<1000; j++){
                ara[i*j] = 1;
            }
        }
    }
    for (i=2; i<1000; i++){
        if (ara[i]==0){
            prime[i] = i;
        }
    }
    for (i=2; i<1000; i++){
        printf("%d\n", prime[i]);
    }
    return 0;
}
