#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int vis [MAX];
int level[MAX];
vector <int> vec[MAX];
queue <int> q;


int main()
{
    int node, edge;
    cin  >> edge;
    for (int i=0; i<edge; i++){
        int x, y;
        cin >> x>> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
    int snode, des;
    cin >> snode>> des;
    q.push(snode);
    vis[snode] = 1;
    while (!q.empty()){
        int top = q.front();
        cout << top<< "    ";
        cout << level[top] << endl;
        if(top == des){
            break;
        }
        q.pop();
        for (int i=0; i < vec[top].size(); i++){
            if (vis[vec[top][i]] == 0 ){
                q.push(vec[top][i]);
                vis[vec[top][i]] = 1;
                level[vec[top][i]] = level[top] + 1;
            }
        }
    }
    return 0;
}
