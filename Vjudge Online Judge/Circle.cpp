#include <bits/stdc++.h>
#define pi 2*acos (0.0)
using namespace std;
int main()
{
    //freopen("vOutput.txt", "w", stdout);
    double sum, sq, circ;
    int tes;
    cin >> tes;
    for (int t=1; t<=tes; t++){
            sum = 0;
        double r;
        cin >> r;
        sq = (r+r)*(r+r);
        circ = pi*r*r;
        sum = (sq - circ);
        printf("Case %d: %0.2lf\n", t, sum);
        }


    return 0;
}

