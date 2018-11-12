#include <stdio.h>
#include <math.h>
int main ()
{
    int num,ans,temp;
    int i, test,digit;
    scanf("%d", &test);

    for (i=0; i<test; i++){
        scanf("%d", &num);
        num*=567;
        num/=9;
        num+=7492;
        num*=235;
        num/=47;
        num-=498;

        temp = num/10;
        temp = abs(temp%10);

        printf("%d\n", temp);
    }
    return 0;
}
