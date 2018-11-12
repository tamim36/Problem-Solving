#include <stdio.h>
int max(int num1, int num2);
int min (int num1, int num2);
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Maximum : %d\n", max(a,b));
    printf("Minimum : %d\n", min(a,b));
    return 0;
}

int max (int num1, int num2)
{
    return ((num1 > num2) ? num1 : num2);
}
int min (int num1, int num2)
{
    return ((num1>num2) ? num2 : num1);
}
