#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long x, y, type, amount, hams, now=1000000000000000000,ans;
    cin >> hams >> type;
    for (int i=1 ; i<=type; i++){
        cin >> x;
        y = hams%x;
        if (y<now){
        now = y;
        ans = i;
        amount = hams/x;
        }
    }
    cout << ans << " "<< amount<<endl;
    return 0;
}

