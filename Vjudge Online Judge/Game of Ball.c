#include <stdio.h>
int main ()
{
    int a=0, i, j=1, n, k;
    scanf("%d", &n);
    if (n==2){
        printf("2");
    }
    else {
    for (i=1; i<n; i++){
        j=j+i;
        j=j%n;
        if (j==0){
            j=n;
        }
        printf("%d ", j);
    }
    }
    return 0;
}
