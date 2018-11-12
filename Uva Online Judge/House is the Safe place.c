#include <stdio.h>
int main ()
{
    int n, d, i=0, len;


    scanf("%d%d", &n, &d);
    char s[n];
    scanf("%s", &s);


    while (i<n){
        if (s[i] == '0'){
                printf("Break");
            break;
        }
        i=i+d;
    }
    if (i>=n){
        printf("Return   %d", i);
    }
    else {
        printf("No");
    }
    return 0;
}
