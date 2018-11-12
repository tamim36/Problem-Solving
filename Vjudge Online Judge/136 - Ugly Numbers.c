#include <stdio.h>
int main ()
{
    int num, i;
    scanf("%d", &num);
    for (i=2; i<=num/2; i++){
        if (num%i==0){
            printf("%d ", i);
            num=num/i;
            i=2;

        }
    }
    return 0;
}
