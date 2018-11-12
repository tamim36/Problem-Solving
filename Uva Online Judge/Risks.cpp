#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int vis[MAX];
int level[MAX];
vector <int> vec[30];
queue <int> q;
int main ()
{
freopen("Output.txt", "w", stdout);
    int k,j, test = 0;


   while (scanf("%d", &k) == 1){
       test ++;
       for (int i=0; i<=30; i++){
        vec[i].clear();
      }
      while (!q.empty()){
        q.pop();
      }
        for (int i=1; i<=19; i++){
               if (i==1){
              j = k;
               }
            else {
            cin >> j;
             }

            for (int k=0; k<j; k++){
                int x;
                cin >> x;
                vec[i].push_back(x);
                vec[x].push_back(i);
           }
        }

        int n;
        cin >> n;
        //cout.width(11);
        if (test != 1){
            cout <<  endl;
        }
        printf("Test Set #%d\n",test);
        for (int i=0; i<n; i++){
        while (!q.empty()){
            q.pop();
        }
        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));

        int s_node, end_node;
        cin >> s_node >> end_node;
        q.push(s_node);
        vis[s_node] = 1;
        while(!q.empty()){

            int top = q.front();
            q.pop();
            if (top == end_node){
               // cout.width(1);
                 printf("%2d to %2d: %d\n",s_node, end_node, level[top]);

                break;
            }
                for (int i=0; i<vec[top].size(); i++){
                    if (vis[vec[top][i]] == 0){
                        vis[vec[top][i]] = 1;
                        q.push(vec[top][i]);
                        level[vec[top][i]] = level[top] +1;
                }
            }
        }
        printf("\n");
    }
   }
    return 0;
}
