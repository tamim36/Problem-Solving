#include <bits/stdc++.h>
using namespace std;

#define MX 1000005

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> vc;
int parent[MX];

int find_parent(int n)
{
    if(parent[n] == n)
        return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}

int mst(const int cities, const int roads)
{
    sort(vc.begin(), vc.end());

    int total = 0, cnt = 0;
    int u, v;

    for(int i = 0; i < roads; i++)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            total += vc[i].w;
            cnt++;
            if(cnt == cities-1)
                break;
        }
    }
    return total;
}

int main()
{
    //freopen("vOutput.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int test, time;
    int cities, roads;
    int total, f=0;
    edge temp;

    //scanf("%d", &time);
    while (scanf("%d", &cities)==1)
    {
        int sum = 0, m, k;
        if (f==1)
        cout <<endl;
        f=1;
        vc.clear();
        for(int i = 1; i <= cities; i++)
            parent[i] = i;

        for (int i=0; i<cities-1; i++){
            int a, b, c;
            cin >>a>>b>>c;
            sum += c;
        }
        cin >> m;
        for (int i=0; i<m; i++){
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }
        roads = m+k;
        total = mst(cities, roads);
        cout << sum << endl << total << endl;
    }
    return 0;
}

