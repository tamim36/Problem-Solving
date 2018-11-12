#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int vis[MAX];
int level[MAX];
vector <int> vec[MAX];
queue <int> q;
 main ()
{
    //freopen("Output.txt", "w", stdout);
    int edge, a, b, s_node, ttl, ans = 0, cas = 0, node_counter =0;


    while (cin >> edge  && edge!= 0){
        node_counter = 0;


        for (int i=0; i<edge; i++){
            cin >> a >> b;


            if (vec[a].size() == 0){
                node_counter ++;
            }
            vec[a].push_back(b);

            if (vec[b].size() == 0){
                node_counter ++;
            }
            vec[b].push_back(a);
        }

        while (cin >> s_node >> ttl){
                if (s_node ==0 && ttl ==0){
                    for (int i=0; i<MAX; i++){
                        vec[i].clear();
                    }
                    break;
                }



        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));



        cas ++;

        if (vec[s_node].size() == 0){
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas, node_counter, s_node, ttl);
            continue;
        }


        ans = 0;
        vis[s_node] = 1;
        q.push(s_node);

        while (!q.empty()){
            int top = q.front();
            //cout << top << "   " << level[top] << endl;
            q.pop();

            for (int i=0; i<vec[top].size(); i++){
                if (vis[vec[top][i]] == 0){
                    q.push(vec[top][i]);
                    vis[vec[top][i]]  = 1;
                    level[vec[top][i]] = level[top] + 1;
                    if (level[vec[top][i]] <= ttl){
                        ans++;
                    }
                }
            }
        }
        //cout << "node cnt = " << node_counter << "answer = " << ans << endl;
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas, node_counter-ans-1, s_node, ttl);
        }
    }
    return 0;
}
