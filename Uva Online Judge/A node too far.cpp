#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int vis[MAX];
int a[MAX];
int level[MAX];
queue <int> q;
vector <int> vec[MAX];

int main ()
{
    int  edge, x, y, s_node, not_reach=0, ttl, cas=0,node=0;
    //freopen("output.txt", "w", stdout);
    while (scanf("%d", &edge)){
            if (edge==0){
                break;
            }
            node=0;
            memset(a, 0, sizeof(a));

            for (int i=0; i<edge; i++){
                cin >> x >> y;
                if(a[x]==0)
                {
                    node++;
                    a[x]=1;
                }
                 if(a[y]==0)
                {
                    node++;
                    a[y]=1;
                }



                vec[x].push_back(y);
                vec[y].push_back(x);
            }

            while (scanf("%d", &s_node)){
            memset(vis, 0, sizeof(vis));
            memset(level, 0, sizeof(level));
            cin >>  ttl;
            if (s_node == 0 && ttl == 0){
                for (int i=0; i<MAX; i++){
                    vec[i].clear();
                }
                break;
            }
            int x=0;
            if(a[s_node])
            {
                x=1;
            }
            q.push(s_node);
            vis[s_node] = 1;
            level[s_node]=1;
            not_reach = 0;
            while (!q.empty()){
                int top = q.front();

                q.pop();
                for (int  i=0; i<vec[top].size(); i++){
                        if (vis[vec[top][i]] == 0){
                            q.push(vec[top][i]);

                            vis[vec[top][i]] = 1;
                            level[vec[top][i]] = level[top] + 1;
                            if (level[vec[top][i]] <=ttl+1){
                    not_reach ++;
                }
                        }
                }
            }
            cas++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas, (node-not_reach)-x, s_node, ttl);
        }
    }
    return 0;
}
