#include <bits/stdc++.h>
using namespace std;
#define infi 200000
#define max 1000

struct data
{
    int node, cost;
    data () {}
    data (int a, int b)
    {
        node = a;
        cost = b;
    }
    bool operator < (const data& p) const
    {
        return p.cost < cost ;
    }
};

vector <data> vec[max];
int dist[max];

void dijkstra(const int nodes)
{
    priority_queue <data>  q;
    int u,v,w,co;
    dist[1] = 0;
    q.push(data(1,dist[1]));
    while (!q.empty())
    {
        u = q.top().node;
        w = q.top().cost;
        q.pop();
        if (dist[u] < w)
            continue;
        for (int i=0; vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].cost;
            co = co + w;
            if (dist[v] <= co)
                continue;
            dist[v] = co;
            q.push(data(v, dist[v]));
        }
    }
    return;
}

int main()
{
    int nodes, edges, start, a, b, c;
    scanf("%d %d", &nodes, &edges);

    for(int i = 0; i <= nodes; i++)
    {
        dist[i] = infi;
        vec[i].clear();
    }

    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        vec[a].push_back(data(b,c));
        vec[b].push_back(data(a,c));
    }
    dijkstra(nodes);
    if(dist[nodes] == infi)
        printf("impossible\n");
    else
        printf("%d\n", dist[nodes]);
    return 0;
}
