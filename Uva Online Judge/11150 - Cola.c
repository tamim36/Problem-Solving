#include <stdio.h>
int main ()
{
    int quo, rem, fin , req=3, temp, total, i, j, tcase, k=0;

    while (scanf("%d", &i)==1){
        total =  i;
        fin = i;

        while (total>=req){
            quo = total/req;
            rem = total%req;
            total = quo+rem;
            fin = fin + quo;
        }
    if (total==2){
            fin = fin+1;
        }
    printf("%d\n", fin);
    }
    return 0;
}

