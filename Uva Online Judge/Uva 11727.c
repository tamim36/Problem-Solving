#include <stdio.h>
int main ()
{
    int a, b, c,d, ans, i=0;
    scanf("%d", &d);
    for (;i<d;){
        scanf("%d%d%d", &a, &b, &c);
        if (a>b && a<c || a<b&&a>c){
            ans = a;
        }
        else if (b>a && b<c || b>c&&b<a){
            ans = b;
        }
        else {
            ans = c;
        }
        printf("case %d: %d", i+1, ans);
        i++;
    }
    return 0;
}
