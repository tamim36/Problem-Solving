#include<bits/stdc++.h>
using namespace std;
int main  ()
{
    freopen ("Output.txt", "w", stdout);
    long long test=1, num, a, pro=1;
    while (scanf("%lld", &num)==1){
            pro = 1;
        for (int i=0; i<num; i++){
            cin >> a;
            if (a>0){
                pro = pro * a;
            }
        }
        if (pro == 1){
            pro = 0;
        }
        printf("Case #%lld: The maximum product is %lld.\n\n", test++, pro);
    }
    return 0;
}
