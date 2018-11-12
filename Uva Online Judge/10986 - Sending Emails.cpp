#include <bits/stdc++.h>
#define max  20001
#define infin 200000
using namespace std;

struct data
{
    int node, weight;
    data() {}
    data (int a, int b)
    {
        node = a;
        weight = b;
    }
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

vector <data> adj[max];
int dist[max];

void dijkstra(const int src)
{
    priority_queue <data> q;
    int u,v, w, co;
    dist[src] = 0;
    q.push(data(src,dist[src]));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
        if (dist[u] < w)
            continue;
        for (int i=0; i<adj[u].size(); i++){
            v = adj[u][i].node;
            co = adj[u][i].weight;
            co = co + w;
            if (dist[v] <= co)
                continue;
            dist[v] = co;
            q.push(data(v, dist[v]));
        }
    }
    return ;
}

int main()
{
   // freopen("Output.txt", "w", stdout);
    int node,edge, src, term, a,b,c, num_test;
    scanf("%d", &num_test);
    for (int f=0; f<num_test; f++){
        scanf("%d%d%d%d", &node, &edge, &src, &term);
        for (int i=0; i<=node; i++){
            dist[i] = infin;
            adj[i].clear();
        }
        for (int i=0; i<edge; i++){
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back(data(b,c));
            adj[b].push_back(data(a,c));
        }
        dijkstra(src);
        printf("Case #%d: ", f+1);
        if (dist[term] == infin){
            printf("unreachable\n");
        }
        else {
            printf("%d\n", dist[term]);
        }
    }
    return 0;
}
