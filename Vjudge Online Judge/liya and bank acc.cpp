#include <bits/stdc++.h>
using namespace std;

int main  ()
{
    long long n,i;
    cin >> n;
    if (n>=0){
        cout << n << endl;
        return 0;
    }
    if (n  >=  -10){
            cout << "aitai" <<endl;
        cout << 0 << endl;
        return 0;
    }
    if (n <  -10){
      int   j = -n;
      int   k = j/100;
        cout << max(-(k*10 + j%10), -(k*10 + (j/10)%10)) << endl;
    }
    return 0;
}
