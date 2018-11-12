#include <bits/stdc++.h>
using namespace std;
#define max 1000001

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

//vector <int> par;
int* par = new int[max];
vector <edge> vec;
vector <edge> vecK;

int find_par(int n)
{
    if (par[n] == n)
        return n;
    par[n] = find_par(par[n]);
    return par[n];
}

int mst(const int city, const int road)
{
    sort(vec.begin(), vec.end());
    int u, v;
    int total = 0, cnt = 0;

    for (int i=0; i<road; i++){
        u = find_par(vec[i].u);
        v = find_par(vec[i].v);

        if (u !=v ){
            par[u] = v;
            cnt++;
            total +=  vec[i].w;
            if  (cnt == city-1)
                break;
        }
    }
    return total;
}

int main ()
{
    //freopen("vOutput.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int city, K, M,  result, unnec, f=0;
    edge temp;
    while (scanf("%d", &city) != EOF){
            //par.clear();
            vec.clear();
            vecK.clear();
            if (f != 0){
                cout << "\n";
                f=1;
            }
            f=1;

        //int u , v, w;
        for (int i=1; i<=city; i++){
            par[i] = i;
        }

        for (int i=1; i<city; i++){
            cin >> unnec >> unnec >> unnec;
        }
        cin >> K;

        for (int i=0; i<K; i++){
            cin >> temp.u >> temp.v >> temp.w;
            vecK.push_back(temp);
        }
        cin >> M;
        for (int i=0; i<M; i++){
            cin >> temp.u >> temp.v >> temp.w;
            vec.push_back(temp);
        }

        result = mst(city, M);
        for (int i=1; i<=city; i++){
            par[i] = i;
        }


        cout << result << endl;
        for (int i=0; i<K; i++){
            vec.push_back(vecK[i]);
        }
        M = M+K;
        result = mst(city, M);
        cout << result << endl;
    }
    return 0;
}
