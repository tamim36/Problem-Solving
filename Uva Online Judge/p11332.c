#include <stdio.h>
int main ()
{
    int num, sum=0, temp;


    while (1){
        scanf("%d", &num);
    if (num==0){
        break;
    }
    else if (num>0 && num <10){
        printf("%d\n", num);
    }
    else {
        while (num>=10){
            sum = 0;
            while (num!=0){
                temp = num%10;
                sum = sum + temp;
                num = num/10;
            }
        num = sum;
        }
        printf("%d\n", sum);
    }
    }

    return 0;
}
