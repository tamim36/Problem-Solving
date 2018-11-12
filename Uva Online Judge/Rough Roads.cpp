#include <bits/stdc++.h>
#define Inf 2000000
#define Max 1000
using namespace std;

struct data
{
    int node, weight;
    data () {}
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
vector <data> vec[Max];
vector <data> vec_rev[Max];
int dist[Max];
int  dist_src[Max];
int dist_des[Max];
int shortest_path;
int des;

void dijkstra(const int start)
{
    priority_queue <data> q;
    int u, v,w,co;
    dist[start] = 0;
    q.push(data(start, dist[start]));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            co = co + w;
            if (dist[v] <= co)
                continue;
            dist[v] = co;
            q.push(data(v, dist[v]));
        }
    }
    return ;
}

void dijkstra_rev(const int start)
{
    priority_queue <data> q;
    int u, v,w,co;
    dist[start] = 0;
    q.push(data(start, dist[start]));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
        for (int i=0; i<vec_rev[u].size(); i++){
            v = vec_rev[u][i].node;
            co = vec_rev[u][i].weight;
            co = co + w;
            if (dist[v] <= co)
                continue;
            dist[v] = co;
            q.push(data(v, dist[v]));
        }
    }
    return ;
}

void dijkstra_final(const int start)
{
    priority_queue <data> q;
    int u, v,w,co;
    dist[start] = 0;
    q.push(data(start, dist[start]));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
           if (v!=des)
                if (dist_src[v] + dist_des[v] == shortest_path)
                continue;

            co = vec[u][i].weight;
            co = co + w;
            if (v==des){
                    if(co > shortest_path && dist[des] > co){
            dist[v] = co;
            q.push(data(v, dist[v]));
                    }
            }
            else {
            if (dist[v] <= co)
                continue;

            dist[v] = co;
            q.push(data(v, dist[v]));
            }
        }
    }
    return ;
}


int main()
{
    freopen("Output.txt", "w", stdout);
    int node, edge, strt;

    while (scanf("%d%d", &node, &edge)){
       // cin >> node >> edge;
        if (node==0 && edge==0){
            break;
        }
        cin >> strt >> des;
        for (int i=0; i<node; i++){
            dist[i] = Inf;
            vec[i].clear();
            vec_rev[i].clear();
        }
        for (int i=0; i<edge; i++){
            int a, b, c;
            cin >> a >> b >> c;
            vec[a].push_back(data(b,c));
            vec_rev[b].push_back(data(a,c));
        }
        //Run Dijkstra From Source
        dijkstra(strt);
        shortest_path = dist[des];
        for (int i=0; i<node; i++){
            dist_src[i] = dist[i];
        }

        //Run DIjkstra From Destination
        for (int i=0; i<node; i++){
            dist[i] = Inf;
        }
        dijkstra_rev(des);
        for (int i=0; i<node; i++){
            dist_des[i] = dist[i];
        }

        //Final Calculation
        for (int i=0; i<node; i++){
            dist[i] = Inf;
        }
        dijkstra_final(strt);

        if (dist[des] == Inf){
          cout << "-1\n";
        }
        else {
          cout << dist[des] << "\n";
        }
    }
    return 0;
}
