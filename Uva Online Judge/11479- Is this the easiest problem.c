#include <stdio.h>
int main ()
{
    long long  a,b,c;
    int i , test;
    scanf("%d", &test);

    for (i=1; i<=test; i++){
        scanf("%lld%lld%lld", &a,&b,&c);
        if (a+b<c || b+c<a || c+a<b || a==0 || b==0 || c==0){
            printf("Case %d: Invalid\n", i);
        }
        else if (a==b && b==c && a==c){
            printf("Case %d: Equilateral\n", i);
        }

        else if ((a==b && b!=c) || (b==c && c!=a) || (c==a && a!=b)){
            printf("Case %d: Isosceles\n", i);
        }
        else if(a!=b!=c){
            printf("Case %d: Scalene\n", i);
        }
    }
    return 0;
}
