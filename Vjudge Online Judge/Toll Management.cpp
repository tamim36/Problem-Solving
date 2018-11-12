//toll management
#include <bits/stdc++.h>
#define  max 25000
#define infi 2147483600
using namespace std;
int ans ;
int toll[max];
int p;

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
       // if (dist[u] < w)
           // continue;

        for (int i=0; i<vec[u].size(); i++){
            v = vec[u][i].node;
            co = vec[u][i].weight;
            if (w > co){
                ans = w;
            }
            else if (w <= co){
                ans = co;
            }
            co = co+w;
            if (co > p)
                continue;

            dist[v] = co;
            if  (ans > toll[v]){
            toll[v] = ans;
            }
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

    int node, edge, a, b, c, start,finish;
     int  test_num;
    cin >> test_num;
    for (int t=0; t<test_num; t++){
            memset(toll, 0, sizeof(toll));
            ans = 0;
            p = 0;

    cin >> node >> edge >> start >> finish >> p;
    for (int i=0; i<=node; i++){
        dist[i] = infi;
        vec[i].clear();
    }

    for (int i=0; i<edge; i++){
        cin >> a >> b >> c;
        vec[a].push_back(data(b,c));
    }
   // cin >> start >> p;
    dijkstra(start);
    /*printf("Case %d:\n", t+1);
    for (int k=0; k<node; k++){
    if(dist[k] == infi)
        printf("Impossible\n");
    else
        printf("%d\n", dist[k]);
        }*/
        if (toll[finish] == 0){
            printf("Case %d: -1\n", t+1);
        }
        else {
        printf("Case %d: %d     %d\n", t+1, toll[finish], dist[finish]);
        }
    }
    return 0;
}


