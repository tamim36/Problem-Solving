#include <bits/stdc++.h>
bool myfunc(int a, int b)
{
    return (a>b);
}
using namespace std;
int main()
{
    vector <int> vec1;
    vector <int> vec2;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
       unsigned long long x;
        cin >> x;
        vec1.push_back(x);
    }
        for (int i=0; i<m; i++){
        long long x;
        cin >> x;
        vec2.push_back(x);
    }
    sort(vec1.begin(), vec1.end(), myfunc);
    sort(vec2.begin(), vec2.end(), myfunc);
    unsigned long long ans;
    ans = vec1[1] * vec2[0];
    cout << ans << endl;
    return 0;
}
