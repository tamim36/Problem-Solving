#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("vOutput.txt", "w", stdout);
    int tes, sum;
    cin >> tes;
    for (int t=1; t<=tes; t++){
        sum =0;
        int num;
        cin >> num;
        for (int i=0; i<num; i++){
            int a;
            cin >> a;
            if (a<0){
                a=0;
            }
            sum = sum +a;
        }
        printf("Case %d: %d\n", t, sum);
    }
    return 0;
}
