#include <stdio.h>
int main ()
{
    long long int a, b, i, j, num, sum, carry=0, count=0, temp;
    while(scanf("%lld %lld", &a, &b)==2){
            carry=0;
            count=0;
            if (a==0 && b==0){
                break;
            }
        if (b>a){
            temp = b;
            b = a;
            a = temp;
        }
        while (a!=0){
            sum = (a%10 + b%10 + carry);
            if (sum>=10){
                carry=1;
                count++;
            }
            else {
                carry=0;
            }
            a=a/10;
            b=b/10;
        }
        if (count==0){
            printf("No carry operation.\n");
        }
        else if (count==1){
            printf("%lld carry operation.\n", count);
        }
        else {
        printf("%lld carry operations.\n", count);
        }
    }
    return 0;
}
