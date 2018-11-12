#include <stdio.h>
int main ()
{
    int caseno, range1, range2, sum=0, i, j ;
    scanf("%d", &caseno);
    for(i=0; i<caseno; i++){
        scanf("%d", &range1);
        scanf("%d", &range2);
        for (j=range1; j<=range2; j++){
            if (j%2==1){
                sum = sum + j;
            }

        }
        printf("case %d: %d\n", i+1,sum);
        sum = 0;
    }
    return 0;
}
