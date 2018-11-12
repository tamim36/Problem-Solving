#include <stdio.h>
int main ()
{
    int long time ;
    int hour, minute, seconds,temp;
    scanf("%ld", &time);
    hour = time / 3600;
    temp = time%3600;
    minute = temp/60;
    temp = temp%60;
    seconds = temp;
    printf("%d:%d:%d\n", hour, minute, seconds);
    return 0;
}
