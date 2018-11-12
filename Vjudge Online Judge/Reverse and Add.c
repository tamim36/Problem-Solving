#include <stdio.h>
int reverse(int num)
{
    int rev=0, rem, temp;
    while (num!=0){
        rem = num%10;
        rev = (rev*10) + rem;
        num = num/10;
    }
    return rev;
}
int ispalindrome (int num)
{
    int temp;
    temp = reverse(num);
    if (num==temp){
        return 1;
    }
    return 0;
}
int add(int a, int b)
{
    return (a+b) ;
}
int main ()
{
    int num, i, j=0, re, temp, sum, test;
    scanf("%d", &test);
    while (j<test){
        if (test>100){
            break;
        }
        scanf("%d", &num);
        for (i=1; i<100; i++){
            temp = num;
            re = reverse(temp);
            sum = add(temp, re);
            if (ispalindrome(sum)){
                printf("%d %d\n",i, sum);
                break;
            }
            num = sum;
        }
        j++;
    }
    return 0;
}
