#include <stdio.h>
int main ()
{
    int num, work_hour;
    float amount_per_hour, total;
    scanf("%d%d%f", &num, &work_hour, &amount_per_hour);
    total = work_hour*amount_per_hour;
    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %0.2f\n", total);
    return 0;
}
