#include <stdio.h>
#include <math.h>

int main ()
{
    int t, n, k, i, j,m,f,a, count;
    scanf("%d", &t);

    for (i=0; i<t; i++){
            count=0;
        scanf("%d", &n);
        scanf("%d", &k);
        for (a=1; a<=n; a++){
            j = (a*a) + (a*a*a);
            f=sqrt(j);
            m=pow(f,2);
            if (j==m){
                count++;
            }
        }
        if(count==k){
    printf("I am married now\n");
        }
        else {
    printf("Baba amar ki biye hobe na\n");
        }
    }
    return 0;
}
