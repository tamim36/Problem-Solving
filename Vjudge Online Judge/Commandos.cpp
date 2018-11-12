#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1001];
int dis[1001];
int vis[1001];
int res[1001];

void bfs(int s)
{
    int cnt = 0;
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()){
        int fnt = q.front();
        q.pop();
        for (int i=0; i<adj[fnt].size(); i++){
            int e = adj[fnt][i];
            if (!vis[e]){
                vis[e] = 1;
                q.push(e);
                dis[e] = dis[fnt] + 1;
            }
        }
    }
}

int main ()
{
    //freopen("Output.txt", "w", stdout);

    int t, n ,r, s,d,cs=0;
    cin>> t;
    while (t--){
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        memset(adj, 0, sizeof adj);

        cin >> n >> r;

        for (int i=0; i<r; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s >> d;
        bfs(s);
        for (int i=0; i<n; i++){
            res[i] = dis[i];
        }
        memset(dis, 0, sizeof dis);
        memset(vis, 0, sizeof vis);

        bfs(d);
        int cnt =0;

        for (int i=0; i<n; i++){
            res[i] += dis[i];
            cnt = max(cnt,res[i]);
        }
        printf("Case %d: %d\n", ++cs, cnt);
    }
    return 0;
}
