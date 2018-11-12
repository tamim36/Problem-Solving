#include <bits/stdc++.h>
using namespace std;
#define MAX 30012

bool v[MAX];
int dis[MAX], test = -1, src_2;
vector <int>adj[MAX];
map<pair<int,int>,int>mp;

void bfs(int src)
{
    memset (v, 0 , sizeof v);
    memset(dis, 0, sizeof dis);
    v[src] = 1;
    dis[src] = 0;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=0; i<adj[u].size(); ++i)
        {
            if (!v[adj[u][i]])
            {
                v[adj[u][i] ]= 1;
                dis[adj[u][i]] = dis[u] + mp[  {u,adj[u][i]}  ];
                q.push(adj[u][i]);
                if (test<dis[adj[u][i]])
                {
                    test = dis[adj[u][i]];
                    src_2 = adj[u][i];
                }
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int t=1; t<=tc; ++t){
        int n;
        scanf("%d", &n);
        for (int i=1; i<n; ++i){
            int u,v, w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[ {u,v} ] = w;
            mp[ {v,u} ] = w;
        }
        bfs(0);
        bfs(src_2);
        printf("Case %d: %d\n", t, test);
        for (int i=0; i<n; i++)
            adj[i].clear();
        mp.clear();
        test=-1;
    }
}
