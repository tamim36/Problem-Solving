#include <bits/stdc++.h>
using namespace std;
int main ()
{
    string a, ns;
        getline(cin, a);
        getline(cin, ns);

    string b = a;
    reverse(b.begin(), b.end());
    if (ns == b){
        cout << "Yes" <<endl;
    }
    else {
        cout << "No";
    }

    cout << b << endl;
    return 0;
}
