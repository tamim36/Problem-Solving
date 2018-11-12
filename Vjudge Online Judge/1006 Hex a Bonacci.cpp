#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, res;
int fn( int n )
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    else
    {
        for (int i=6; i<=n; i++)
        {
            res = a + b+c+d+e+f;
            res = res% 10000007;
            a = b;
            b=c;
            c=d;
            d=e;
            e=f;
            f=res;
        }
    }
    return res ;
}
int main()
{
    //freopen("vOutput.txt", "w", stdout);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        res = 0;
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n)% 10000007);
    }
    return 0;
}
