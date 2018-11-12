#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0, n, m, cost, prev=0;
    multiset <int> st;
    multiset <int> ::iterator it;
    cin >> n >> m;
    for (int i=0; i<n; i++){
            cin >> cost;
        st.insert(cost);
    }

    it = st.begin();
    for (int i=0; i<m; i++){
        sum = sum + *it;
        if (sum>prev){
            break;
        }
        else {
            prev = sum;
        }
        it++;
    }

    cout << abs(prev) << "\n";

    return 0;
}
