#include <stdio.h>
#include <stdlib.h>
int main ()
{
    float h, m,  minute, res;
    char c;
    float hour , angle;
    while (1){
            scanf("%f", &h);
            scanf("%c", &c);
    scanf("%f", &m);
            if (h==0 && m==0){
                break;
            }
    hour = h*30+(m/2);
    minute = m*6;
    angle = (hour - minute);
    if (angle<0){
        angle = angle*(-1);
    }
    if (angle>180){
        angle = 360-angle;
    }
    printf("%0.3f\n", angle);
    }
    return 0;
}
