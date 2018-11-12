#include <stdio.h>
int main ()
{
    int a, b, i, j, sum, atemp, btemp, count;
    while (scanf("%d%d", &a, &b)==2){
            if (a==0 && b==0){
                break;
            }
            count = 0;
            int carry=0;
        while (a!=0 && b!=0){
            sum = a%10+b%10+carry;
            b = b/10;
            a = a/10;

            if (sum>=10){
                count++;
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        printf("%d carry operation\n", count);
    }
    return 0;
}
