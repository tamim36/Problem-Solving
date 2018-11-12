//country roads
#include <bits/stdc++.h>
#define  max 25000
#define infi 2147483600
using namespace std;

//Like STL pair Function
struct data
{
    int node, weight;
    //constructor
    data() {}
    data (int a, int b)
    {
        node = a;
        weight = b;
    }
    //operator overloading
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

vector <data> vec[max];
int dist[max];

void dijkstra(const int start)
{
     priority_queue <data> q;
     int u, v, w, co;
    dist[start] = 0;
    q.push(data(start,dist[start]));
    while (!q.empty())
    {

        u = q.top().node;
        w = q.top().weight;
        q.pop();
        if (dist[u] < w)
            continue;

        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            if (w > co){
                co = w;
            }
            if (dist[v] <= co)
                continue;
            dist[v] = co;
            q.push(data(v, dist[v]));
        }
    }
    return ;
}

int main ()
{
    //Fast I/O technique
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int node, edge, a, b, c, start;
     int  test_num;
    cin >> test_num;
    for (int t=0; t<test_num; t++){

    cin >> node >> edge;
    for (int i=0; i<=node; i++){
        dist[i] = infi;
        vec[i].clear();
    }

    for (int i=0; i<edge; i++){
        cin >> a >> b >> c;
        vec[a].push_back(data(b,c));
        vec[b].push_back(data(a,c));
    }
    cin >> start;
    dijkstra(start);
    printf("Case %d:\n", t+1);
    for (int k=0; k<node; k++){
    if(dist[k] == infi)
        printf("Impossible\n");
    else
        printf("%d\n", dist[k]);
    }
    }
    return 0;
}

