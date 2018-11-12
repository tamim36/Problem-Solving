#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    double x=0, a, b, d;
    cin >> a >> b;
    d = b;
    for (int i=0; i<32; i++){
        b=b/a;
        if (b==1){
            cout <<"YES" << endl << i;
            break;
        }
        else if (b<1) {
        cout << "NO";
        break;
    }
    }
    return 0;
}
