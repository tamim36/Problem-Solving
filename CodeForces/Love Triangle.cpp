#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <int,int> m;
    map<int,int>::iterator it;
    int num, x, flag = 0;
    cin >> num;
    for (int i=1; i<=num; i++){
        cin >> x;
        m.insert(make_pair(i, x));
    }

    for (it = m.begin(); it!=m.end(); it++){
        int y = m[it->second];
        if (m[y] == it->first){
            cout << "YES\n" ;
             flag = 1;
            break;
        }
    }
    if (flag != 1){
        cout << "NO\n";
    }
    return 0;
}
