#include <bits/stdc++.h>
using namespace std;
#define inf 2147483600
#define max 100

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

int level[max][max];
int dist[max][max];
int would_be[max][max];
vector <data> vec[max];

void dijkstra(const int start)
{
    priority_queue < data> q;
    int u, v, co, w;
    dist[0][0] = 0;
    q.push(data(0,dist[0][0]));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        q.pop();
       // if (dist[u] < w)
          //  continue;
        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            co = co + w;
           // if (dist[u][level[] <= co)
                //continue;
            if (would_be[u][v] == 1){
                level[v][co] = level[u][w] + 1;
                dist[v][level[v][co]] = co;
                q.push(data(v, dist[v][level[v][co]]));
            }
            else  {
                dist[v][level[v][co]] = co;
                q.push(data(v, dist[v][level[v][co]]));
            }
        }
    }
    return ;
}

int main()
{
   // freopen("vOutput.txt", "w", stdout);

   // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

    int tes_cas;
  cin >> tes_cas;

   for (int t=1; t <= tes_cas; t++){
        int node, edge, prop_rd, most, sum=inf;
        cin >> node >> edge >> prop_rd >> most ;

        for (int i=0; i<max; i++){
                for (int j=0; j<max; j++){
                    dist[i][j] = inf;
                   // would_be[i][j] = 0;
                   // level[i][j] = 0;
                }
            vec[i].clear();
        }
        memset(would_be, 0, sizeof(would_be[0][0]) * max * max);
        memset(level, 0, sizeof(level[0][0]) * max * max);

        for (int i=0; i<edge; i++){
            int a, b, c;
            cin >> a >> b >> c;
            would_be[a][b] = 0;
            vec[a].push_back(data(b,c));
        }
        for (int i=0; i<prop_rd; i++){
            int a, b, c;
            cin >> a >> b >> c;
            would_be[a][b] = 1;
            vec[a].push_back(data(b,c));
        }

        dijkstra(1);
        sum = dist[node-1][0];
        for (int i=1; i<=most; i++){
            if (dist[node-1][i] < sum){
                sum = dist[node-1][i];
            }
        }
        if (sum == inf){
            printf("Case %d: Impossible\n", t);
        }
        else {
            printf("Case %d: %d\n", t, sum);
        }
   }
    return 0;
}
