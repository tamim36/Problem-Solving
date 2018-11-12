#include <stdio.h>
int main ()
{
    int i, j, k;

    for (i=1; i<10; i++){
        for (j=7; j>4; j--){
            printf("I=%d J=%d\n", i,j);

        }
        i=i+1;
    }
    return 0;
}
