#include <bits/stdc++.h>
#define max 1000
#define inf 2147483600
using namespace std;

struct data
{
    int node, weight;
    data () {}
    data (int a, int b)
    {
        node  = a;
        weight = b;
    }
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

vector <data> vec[max];
int dist[max];

void dijkstra(const int nodes)
{
    priority_queue <data> q;
    int u, w, v, co, v2, co2;
    dist[0] = 0;
    q.push(data(0, dist[0]));

    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
        if (dist[u] < w)
            continue;

        for (int i=0; i < vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            co = co + w;

            for (int j=0; j < vec[v].size(); j++){
                v2 = vec[v][j].node;
                co2 = vec[v][j].weight;
                co2 = co2+co;
                if (dist[v2] <= co2)
                    continue;
                dist[v2] = co2;
                q.push(data(v2,dist[v2]));
            }
        }
    }
    return;
}


int main()
{
    cin.tie(NULL);

    int node, edge, cas = 0;
    while (scanf("%d%d", &node, &edge)==2){

            cas++;
        int a, b, c;
        for (int i=0; i<=node; i++){
            vec[i].clear();
            dist[i] = inf;
        }

        for (int i=0; i<edge; i++){
            cin >> a >> b >> c;
            vec[a].push_back(data(b,c));
            vec[b].push_back(data(a,c));
        }
        dijkstra(node);
        if (dist[node-1] == inf){
            cout << "Set #" << cas << "\n" << "?\n";
        }
        else {
            cout << "Set #" << cas << "\n" << dist[node-1] << "\n";
        }
    }
    return 0;
}



