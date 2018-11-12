#include <bits/stdc++.h>
using namespace std;
int main ()
{
    vector <int> vec;
    vector <int> ::iterator it;
    int test, x;
    cin >> test;
    for (int i=0; i<test; i++){
        cin >> x;
        vec.push_back(x);
    }
    for (int i =1; i<3010; i++){
    it = find (vec.begin(), vec.end(), i);
    if (it == vec.end()){
        cout << i << endl;
        break;
    }
    }
    return 0;
}
