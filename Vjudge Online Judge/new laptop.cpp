#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ara[1000], num, i;
    int pres[1000];
    cin >> num;

    for (i=1 ; i<=num; i++){
        cin >> ara[i];
    }
    for (i=1; i<=num; i++){
        pres[ara[i]] = i;
    }
    for (i=1 ; i<=num; i++){
        cout << pres[i] << " ";
    }
    return 0;
}
