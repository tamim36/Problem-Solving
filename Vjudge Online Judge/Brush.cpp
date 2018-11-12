#include <bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define MX 1002
#define INFI 200000

struct data
{
    int node, weight;
    // constructor
    data() {}
    data(int a, int b)
    {
        node = a;
        weight = b;
    }
    // operator overload
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

vector<data> adj[MX];
int dist[MX];

void dijkstra(const int nodes)
{
    priority_queue<data> que;
    int u, v, w, co;
    // 1 is source
    dist[1] = 0;
    que.push(data(1,dist[1]));

    while(!que.empty())
    {
        u = que.top().node;

        w = que.top().weight;

        que.pop();

        if(dist[u] < w)
            continue;

        int sz = adj[u].size();

        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].node;
            co = adj[u][i].weight;
            co = co+w;
            if(dist[v] <= co)
                continue;

            dist[v] = co;
            que.push(data(v,dist[v]));
        }
    }
    return;
}


int main()
{
    int nodes, edges, start, a, b, c;
    int num_test;
    cin >> num_test;
    for(int k=0; k<num_test; k++){
    scanf("%d %d", &nodes, &edges);

    for(int i = 0; i <= nodes; i++)
    {
        dist[i] = INFI;
        adj[i].clear();
    }

    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        adj[a].push_back(data(b,c));
        adj[b].push_back(data(a,c));
    }
    dijkstra(nodes);
    if(dist[nodes] == INFI)
        printf("Impossible\n");
    else
        printf("%d\n", dist[nodes]);
    }
    return 0;
}

