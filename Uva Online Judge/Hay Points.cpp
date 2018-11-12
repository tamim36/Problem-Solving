#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("Output.txt", "w", stdout);
    int m, n, i = 0, j, tes, value, sum=0;
    string key, word;
    map <string,int> mp;
    map <string,int>::iterator it;
    cin >> m >> n;

    while (i<m){
            i++;
        cin >> key >> value;
        mp[key] = value;
    }
    i=0;
    while (i<n){
        i++;
        while (cin >> key){
            if(key == "."){
                break;
            }
            sum = sum + mp[key];
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}
