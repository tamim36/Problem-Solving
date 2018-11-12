#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int i,T,a,b,j,k;
    cin >>T;
    for (i=0; i<T; i++){
        cin >> a>> b;
        if (b%a != 0)
            j=0;
        else
        for (j=1; b%a == 0  &&  b!=a; j++){
            b=b/a;
            for (a=2;a<=sqrt(double(b)) && a>=2; a++)
                if (b%a == 0)
                break;
            else
                continue;
        }
        cout << j << endl;
    }
    return 0;
}
