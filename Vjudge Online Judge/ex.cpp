#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("vOutput.txt", "w", stdout);
    //freopen("Output.txt", "w", stdout);
    int tes_cas;
    //cin >> tes_cas;
    //for  (int t=1; t<=tes_cas; t++){

    for (int i=1; i<=6; i++){
        for (int j=1; j<=6; j++){
            if (i<j)
                cout << i << j << "   " ;
        }
        cout << endl;
    }
    //printf("Case %d: %d\n", t, sum);
    //}

    return 0;
}

