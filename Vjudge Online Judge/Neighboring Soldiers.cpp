#include <bits/stdc++.h>
using namespace std;
int main ()
{
    map <int,int> mp;
    map<int,int> ::iterator it;
    vector <int> vec;
    int test, key, indx;
    cin >> test;
    for (int i=0; i<test; i++){
        int x;
        cin  >> x;
        vec.push_back(x);
    }
    for (int i= 0; i<vec.size()-1; i++){
        key =abs (vec[i] - vec[i+1]);
        indx = i+1;
        mp[key] = indx;
    }
    key = abs(vec[0] - vec[test-1]);
    indx = test;
    mp[key] = indx;

    it = mp.begin();

    if (it->second == test){
        cout << "1" << " " << test << endl;
    }
    else {
    cout << it->second  << " " << it->second+1 <<endl;
    }
    return 0;
}
