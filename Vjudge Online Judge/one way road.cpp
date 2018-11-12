#include <bits/stdc++.h>
#define inf 1000000009
#define ms(a,b) memset (a,b, sizeof a)

using namespace std;
typedef pair <int,int> pr;

bool visit[105];
int arr[105][105], sum;
vector <pr> vec[105];

void dfs(int node, int parent)
{
    int sz = vec[node].size();
    for (int k=0; k<sz; k++){
        pr w = vec[node][k];
        int x = w.second;
        int cost = w.first;
        if(!visit[x] and x!=parent){
            visit[x] = true;
            if(arr[node][x] == 0){
                sum+=cost;
            }
            dfs(x,node);
        }
    }
}

int main ()
{
    //freopen("output.txt", "w", stdout);
    int test, cas, n, u, v, w;
    while(cin>>test){
        cas=1;
        while(test--){
            cin>>n;
            for (int i=0; i<105; i++){
                for (int j=0; j<105; j++){
                    arr[i][j] = 0;
                }
            }
            for (int i=0; i<n; i++){
                cin >> u>>v>>w;
                vec[u].push_back(pr(w,v));
                vec[v].push_back(pr(w,u));
                arr[u][v] = 1;
            }
            pr x = vec[1][0];
            pr y = vec[1][1];
            int mn = inf;
            sum = 0;
            ms(visit,false);
            dfs(1, -1);
            mn = min(mn, sum);
            sum  =0;
            ms(visit, false);
            vec[1].clear();
            vec[1].push_back(y);
            vec[1].push_back(x);
            dfs(1,-1);
            mn = min(mn, sum);
            printf("Case %d: %d\n", cas++, mn);
            for (int i=0; i<105; i++) vec[i].clear();
        }
    }
    return 0;
}
