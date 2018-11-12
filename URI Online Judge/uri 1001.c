#include <stdio.h>
int main(){
    int a,b;
    long int sum;
    for(;;){
    scanf("%d%d", &a, &b);
    sum = a+b;
    printf("X = %d\n", sum);
    sum = 0;
    }
    return 0;
}
