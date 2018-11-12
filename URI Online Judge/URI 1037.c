#include<stdio.h>
int main ()
{
    float value,temp;
    scanf("%f", &value);
    if(value>=0 && value <=25){
        printf("Intervalo [0,25]\n");
    }
    if(value>25 && value <=50){
        printf("Intervalo (25,50]\n");
    }
    if(value>50 && value <=75){
        printf("Intervalo (50,75]\n");
    }
    if(value>75 && value <=100){
        printf("Intervalo (75,100]\n");
    }
    if(value<0 || value>100) {
        printf("Fora de intervalo\n");
    }
    return 0;
}

