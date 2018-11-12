#include <stdio.h>
#include <math.h>
#define N 1000
int main ()
{
    int i, j, num;
    int ara[N];
    for (i=0;i<N; i++){
        ara[i] = 0;
    }
    ara[0] = ara[1] = 1;
    for (i=2; i<N; i++){
        if (ara[i] == 0){
            for (j=2; j<N; j++){
                ara[i*j] = 1;
            }
        }
    }
    for (i=2; i<N; i++){
        if (ara[i] == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}
