#include <stdio.h>
long long reverse(long long num)
{
    long long rev=0, rem, temp;
    while (num!=0){
        rem = num%10;
        rev = (rev*10) + rem;
        num = num/10;
    }
    return rev;
}
long long ispalindrome (long long num)
{
    long long temp;
    temp = reverse(num);
    if (num==temp){
        return 1;
    }
    return 0;
}
long long add(long long a, long long b)
{
    return (a+b) ;
}
int main ()
{
    long long num, i, j=0, re, temp, sum, test;
    scanf("%lld", &test);
    while (j<test){
        scanf("%lld", &num);
        for (i=1; i<100; i++){
            temp = num;
            re = reverse(temp);
            sum = add(temp, re);
            if (ispalindrome(sum)){
                printf("%lld %lld\n",i, sum);
                break;
            }
            num = sum;
        }
        j++;
    }
    return 0;
}
