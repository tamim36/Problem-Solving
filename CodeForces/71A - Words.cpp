#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if (s.length() >= 11)
        cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        else
            cout << s << endl;
    }

    return 0;
}

