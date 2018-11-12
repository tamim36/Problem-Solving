#include <stdio.h>
int main ()
{
    int a, b, i=0,test, j;

    scanf("%d", &test);
    while (i<test){
        scanf("%d", &a);
        if (a==1 || a==2 || a==4 || a==5 || a==8 || a==11 || a==0 ){
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
        i++;
    }
    return 0;
}
