#include <bits/stdc++.h>
using namespace std;
int main ()
{
    vector <int> vec;
    int test, x, y, h=0;
    cin >> test;
    for (int i=0; i<test; i++){
            cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    for (int i=0; i<vec.size()-1; i++){
        if (vec[i] == vec[i+1]){
            h++;
            i++;
        }
    }
    h=h/2;
    cout << h << endl;

    return 0;
}

