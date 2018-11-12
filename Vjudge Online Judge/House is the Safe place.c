#include <stdio.h>
int main ()
{
    int n, d,  i=0, jump=0, k, log=0;
    scanf("%d%d", &n,&d);
    char str[n+1];
    scanf("%s", str);

    while (i<n){
        if (str[i] == '1'){
            i=i+d;
            k=0;
            if (i==n-1){
                jump--;
            }
            jump++;
        }
        else if ((str[i] == '0')&&(k<d-1)){
            i--;
            k++;
        }
        else {
                log =  1;
            break;
        }
    }
    if (log==0){
        printf("Return home with jump %d\n", jump);
    }
    else if (log == 1){
        printf("-1");
    }
    return 0;
}
