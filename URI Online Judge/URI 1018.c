#include<stdio.h>
int main ()
{
    int long long taka;
    int temp, tk_100, tk_50, tk_20, tk_10, tk_5, tk_2, tk_1;
    scanf("%lld", &taka);
    printf("%lld\n", taka);
    tk_100 = taka/100;
    temp = taka%100;
    printf("%d nota(s) de R$ 100,00\n", tk_100);
    tk_50 = temp/50;
    temp = temp%50;
    printf("%d nota(s) de R$ 50,00\n", tk_50);
        tk_20 = temp/20;
    temp = temp%20;
    printf("%d nota(s) de R$ 20,00\n", tk_20);
        tk_10 = temp/10;
    temp = temp%10;
    printf("%d nota(s) de R$ 10,00\n", tk_10);
        tk_5 = temp/5;
    temp = temp%5;
    printf("%d nota(s) de R$ 5,00\n", tk_5);
        tk_2 = temp/2;
    temp = temp%2;
    printf("%d nota(s) de R$ 2,00\n", tk_2);
        tk_1 = temp/1;
    temp = temp%1;
    printf("%d nota(s) de R$ 1,00\n", tk_1);
    return 0;
}
