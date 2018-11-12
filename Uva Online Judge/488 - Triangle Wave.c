#include <stdio.h>
int main ()
{
    int i,j,k, amp, freq, cas, a;
    while (scanf("%d", &cas)==1){
        for(a=1; a<=cas; a++){
            scanf("%d", &amp);
            scanf("%d", &freq);


        for(k=1; k<=freq; k++){
            for (i=1; i<=amp; i++){
                for (j=1; j<=i; j++){
                    printf("%d", i);
                }
                printf("\n");
            }
            for (i=amp-1; i>=1; i--){
                for (j=i; j>=1; j--){
                    printf("%d", i);
                }
                printf("\n");
            }
            if (a!=cas){
            printf("\n");
            }
        }
    }
    }
    return 0;
}
