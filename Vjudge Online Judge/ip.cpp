#include <bits/stdc++.h>
using namespace std;

#define MX 10005

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> vc;
map <string,int> mp;
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
    int test, time;
    int cities, roads;
    int total;
    edge temp;
    int mp_cnt;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        mp_cnt = 0;
        scanf("%d %d", &cities, &roads);
        vc.clear();
        mp.clear();
        for(int i = 1; i <= cities; i++)
            parent[i] = i;

        for(int i = 0; i < roads; i++)
        {
             string au, av;
            cin >> au >> av >> temp.w;

            if (mp[au] == 0)
                mp[au] = mp_cnt++;
            if (mp[av] == 0)
                mp[av] = mp_cnt++;
            temp.u = mp[au];
            temp.v = mp[av];

            vc.push_back(temp);
        }
        total = mst(cities, roads);
        cout << total << "\n\n";
    }
    return 0;
}
