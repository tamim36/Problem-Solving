#include <bits/stdc++.h>
using namespace std;
#define max 10000
#define inf 200000

struct data
{
    int node, weight, optional;
    data() {};
    data (int a, int b, int c)
    {
        node = a;
        weight = b;
        optional = c;
    }
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

int dist[max][11];
vector <data> vec[max];
int d;

void dijkstra(const int start)
{
    //cout << d << endl;
    int u,v,co, w, op_u, op_v;
    priority_queue <data> q;
    dist[0][0] = 0;
    q.push(data(0,0,0));
    while (!q.empty()){
        u = q.top().node;
        w = q.top().weight;
        op_u = q.top().optional;
       // cout << "Parent : " << "  u = " << u << " w = " << w << " op_u = " << op_u <<endl;
        q.pop();

        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            op_v = vec[u][i].optional;
                 //   cout << "Child : " << " v = " << v << " co = " << co << " op_v = " << op_v <<endl;

            co = co + w;
            op_v = op_u + op_v;

           if (op_v > d)
                continue;

           if (dist[v][op_v] <= co)
                continue;

             dist[v][op_v] = co;
         // cout << "Assign Value dist[v][op_v] = " << dist[v][op_v] << "  v  "  << v << "  op_v " << op_v << endl;
             q.push(data(v, dist[v][op_v], op_v));
        }
    }
    return;
}

int main()
{
   // freopen("vOutput.txt", "w" , stdout);
    int node, edge, pro_rd, test_cas;
    cin >> test_cas;
    for (int t=1; t<=test_cas; t++){
        cin >> node >> edge >> pro_rd >> d;
        //memset(dist, 0x3f, sizeof dist);

        for (int i=0; i<node; i++){
            for (int j=0; j<=d; j++){
                dist[i][j] = inf;
            }
        }

        for (int i=0; i<node; i++){
            vec[i].clear();
        }

        for (int i=1; i<=edge; i++){
            int a,b,c;
            cin >> a >> b >> c;
            vec[a].push_back(data(b, c, 0));
        }
        for (int i=0; i<pro_rd; i++){
            int a,b,c;
            cin >> a >> b >>c;
            vec[a].push_back(data(b,c,1));
        }
        dijkstra(1);
        /*for (int i=0; i<=d; i++) {
                cout << dist[node-1][i] << endl;
        }*/

        int ans = inf;
        for (int i=0; i<=d; i++) ans = min(ans, dist[node-1][i]);

        if (ans == inf){
            printf("Case %d: Impossible\n", t);
        }
        else {
            printf("Case %d: %d\n", t, ans);
        }
    }
    return 0;
}
