#include<bits/stdc++.h>
using namespace std;
#define MAX 400
int vis[MAX];
int level[MAX];
queue <int> q;
vector <int> vec[MAX];

int main ()
{
    int node, edge, bicolor, x,y;
    while (scanf("%d", &node)){
            bicolor = 0;
            for (int i=0; i<MAX; i++){
            vec[i].clear();
            }
            if (node == 0){
                break;
            }
        cin >> edge;
    for (int i=0; i<edge; i++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    memset (vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
    q.push(x);
    vis[x] = 1;
    while (!q.empty()){
        int top = q.front();
        q.pop();
        for (int i=0; i<vec[top].size(); i++){
            if (vis[vec[top][i]]==0){
                    q.push(vec[top][i]);
                    vis[vec[top][i]] = 1;
                    if (level[top] == 0){
                        level[vec[top][i]] = 1;
                    }
                    else {
                        level[vec[top][i]] = 0;
                    }
            }
            else if (vis[vec[top][i]] == 1){
                if (level[top] == level[vec[top][i]]){
                    bicolor = 1;
                }
            }
        }
    }
    if (bicolor==0){
        cout << "BICOLORABLE." << endl;
    }
    else if (bicolor==1){
        cout << "NOT BICOLORABLE." << endl;
    }
    }
    return 0;
}

