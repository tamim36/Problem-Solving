#include <bits/stdc++.h>
using namespace std;

#define MX 300005

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
    int test, time;
    int cities, roads;
    int total;
    edge temp;

    /*scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {*/

        while (scanf("%d %d", &cities, &roads)==2){
                if (cities == 0 && roads == 0)
                    break;
            vc.clear();
            int sum = 0;
            for(int i = 0; i < cities; i++)
                parent[i] = i;

            for(int i = 0; i < roads; i++)
            {
                scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
                sum +=temp.w;
                vc.push_back(temp);
            }
            total = mst(cities, roads);
            cout << sum-total << endl;
        }
    return 0;
}

