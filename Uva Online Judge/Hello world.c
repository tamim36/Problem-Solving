#include <stdio.h>
#include <math.h>
int main()
{
    int res, i, x,num, ans;

    for (x=1;x<2001; x++){
        scanf("%d", &num);
        if (num < 0){
            break;
        }

        else {
            for (i=1; i<100; i++){
            res = pow(2,i);
            if (num==0 || num == 1){
                ans = 0;
                break;
            }
            if (res>=num){
                ans = i;
                break;
            }
        }
        printf("Case %d: %d\n",x, ans);
        }
    }

    return 0;
}
