#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int par_vis [MAX];
int vis[MAX];
int color[MAX];
int assign_col[MAX];
vector <int> vec[MAX];
queue <int> q;
queue <int> q_path;

int main()
{
    int node, step=0;
    cin >> node;
    for (int i=0; i<node-1; i++){
        int x, y;
        cin >> x>> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i=1; i<=node; i++){
        scanf("%d", &color[i]);
    }
    memset(par_vis, 0, sizeof(par_vis));
    memset(vis, 0, sizeof(vis));
    memset(assign_col, 0, sizeof(assign_col));
    q.push(1);
    vis[1] = 1;
    while (!q.empty()){
        int top = q.front();
        q_path.push(top);
        q.pop();
        for (int i=0; i < vec[top].size(); i++){
            if (vis[vec[top][i]] == 0 ){
                q.push(vec[top][i]);
                vis[vec[top][i]] = 1;
            }
        }
    }
    memset(par_vis, 0, sizeof(par_vis));
    memset(vis, 0, sizeof(vis));
    memset(assign_col, 0, sizeof(assign_col));
    while (!q_path.empty()){
        int top = q_path.front();
        q_path.pop();
            q.push(top);
    vis[top] = 1;
    if (color[top] == assign_col[top]){
            q.pop();
    }
    else {
    while (!q.empty()){
        int top = q.front();
        q.pop();
        assign_col[top] = color[top];
        step++;
        for (int i=0; i < vec[top].size(); i++){
            if (vis[vec[top][i]] == 0 ){
                q.push(vec[top][i]);
                assign_col[top] = color[top];
            }
        }
    }
    }
    }
    printf("%d", step);
    return 0;
}

