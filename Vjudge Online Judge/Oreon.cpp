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
    char cu, cv;

    for(int i = 0; i < roads; i++)
    {
        u = find_parent(vc[i].u);
        v = find_parent(vc[i].v);

        if(u != v)
        {
            parent[u] = v;
            total += vc[i].w;
            cnt++;
            cv = 'A' + vc[i].v - 1;
            cu = 'A' + vc[i].u - 1;
            if (cv < cu){
            printf("%c-%c %d\n", cv, cu, vc[i].w);
            }
            else {
                printf("%c-%c %d\n", cu, cv, vc[i].w);
            }
            //cout << vc[i].u << "-" << vc[i].v << " " << vc[i].w <<endl;
            if(cnt == cities-1)
                break;
        }
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
   // freopen("vOutput.txt", "w", stdout);
    int test, time;
    int cities, roads=0;
    int total=0;
    edge temp;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        scanf("%d", &cities);
        vc.clear();
        for(int i = 1; i <= cities; i++)
            parent[i] = i;



        /*for(int i = 0; i < roads; i++)
        {
            scanf("%d %d %d", &temp.u, &temp.v, &temp.w);
            vc.push_back(temp);
        }*/
        int x;
        char c;
        for (int j=1; j<=cities; j++){
            for (int i=1; i<=cities; i++){

                cin >> x;
                if (j < i){
                    if (x != 0){

                    temp.u = i;
                    temp.v = j;
                    temp.w = x;
                    vc.push_back(temp);
                    roads++;
                    }
               }
                if (i==cities)
                    continue;
                cin >> c;
            }
        }



        //
        //cout << "road " << roads <<endl;
        printf("Case %d:\n", test);

        total = mst(cities, roads);
        //cout << total << endl;

    }
    return 0;
}

