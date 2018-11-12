#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
queue <int> q;

int main ()
{
    long long edge, x, y, s_node;
    cin >> edge;
    int vis[MAX];
    vector <int> vec[MAX];
    for (int i=0; i<edge; i++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    memset (vis, 0, sizeof(vis));
    for (int i=0; i<edge+1; i++){
        if (vec[i].size() == 1){
            s_node = i;
            break;
        }
    }
    q.push(s_node);
    vis[s_node] = 1;
    while (!q.empty()){
        int top = q.front();
        cout << top << " ";
        q.pop();
        for (int i=0; i<vec[top].size(); i++){
            if (vis[vec[top][i]]==0){
                q.push(vec[top][i]);
                vis[vec[top][i]] = 1;
            }
        }
    }
    return 0;
}
