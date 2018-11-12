#include <stdio.h>

int main()
{
    long long cas, farmer, a,b,c,sum,i,j,k;
    scanf("%lld", &cas);

    for (k=0; k<cas; k++){
        sum=0;
        scanf("%lld", &farmer);
        for (i=0; i<farmer; i++){
            scanf("%lld%lld%lld", &a, &b, &c);
                j = a*c;
                sum=sum+j;
        }
    printf("%lld\n", sum);
    }
    return 0;
}
