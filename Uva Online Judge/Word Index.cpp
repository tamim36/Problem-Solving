#include <bits/stdc++.h>
using namespace std;
int main ()
{
    map<string,int> m;
    map <string, int> ::iterator it;

string s[0] = "a";
    for (int i=1, j=97; i<=26; i++, j++){
        m[s] = i;
        s[0]++;
    }
   // cout << m[0];
    for (it = m.begin() ; it != m.end(); it++){
        cout << it->first <<"\t" << it->second << endl;
    }
    return 0;
}
