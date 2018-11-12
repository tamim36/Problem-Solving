#include <stdio.h>
int main ()
{
    int i,j, limit, cas, num, res=0;
    scanf("%d", &cas);
    for (i=0; i<cas; i++){
            res = 0;
            scanf("%d", &limit);
        for (j=0; j<limit; j++){
            scanf("%d", &num);
            if (num>res){
                res=num;
            }
        }
        printf("Case %d: %d\n", i+1, res);
    }
    return 0;
}
