#include <bits/stdc++.h>
#define max 2010
using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> vec;
map <string,int> mp;
map <string,int> ::iterator it;
int par[max];

int find_par(int n)
{
    if (par[n] == n)
        return n;
    par[n] = find_par(par[n]);
    return par[n];
}

int mst (const int city, const int road)
{
    sort(vec.begin(), vec.end());
    int u,v;
    int total = 0, cnt = 0;
    for (int i=0; i<road; i++){
        u = find_par(vec[i].u);
        v = find_par(vec[i].v);

        if (u != v){
            par[u] = v;
            total = total + vec[i].w;
            cnt++;
            if (cnt == city-1)
                break;
        }
    }
    return total;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    //freopen("vOutput.txt", "w", stdout);

    int city, road, test;
    edge temp;
    cin >> test;

    for (int t=1; t<=test; t++){
           int total = 0, mp_cnt = 0;
            vec.clear();
            mp.clear();
        cin >> city >> road;

        for (int i=1; i<=city; i++){
            par[i] = i;
        }

        for (int i=0; i<road; i++){
          //  /*
            string au, av;
            cin >> au >> av >> temp.w;

            if (mp[au] == 0){
                mp[au] = ++mp_cnt;
            }
            if (mp[av] == 0){
                mp[av] = ++mp_cnt;
            }
            temp.u = mp[au];
            temp.v = mp[av];
           // */
            //cin >> temp.u >> temp.v >> temp.w;
            vec.push_back(temp);
        }

        total = mst(city, road);
        cout << total << "\n" ;
        if (t !=test){
            cout << "\n";
        }
    }
    return 0;
}
