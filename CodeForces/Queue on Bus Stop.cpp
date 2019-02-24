#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m, a, bus=0, top, capacity;
    queue<int> q;
    cin >> n >> m;

    while (n--){
        cin >> a;
        q.push(a);
    }

    while(!q.empty()){
            capacity = m;
        while ((capacity > 0) && (!q.empty())){
            top = q.front();
            if (capacity >= top){
                //cout << capacity << "     " << top << "    " << bus << endl;
                q.pop();
                capacity -= top;
            }
            else {
                capacity = 0;
            }
        }
        bus++;
    }
    cout << bus << endl;

    return 0;
}
