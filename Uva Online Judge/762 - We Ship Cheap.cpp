#include<bits/stdc++.h>
using namespace std;
#define max 100
int check;
int vis[100];
int level[100];

int flag ;
   // map <string,int> mp1;
   // map <int, string> mp2;
vector <int> vec[max];
queue <int> path;
void bfs (int source, int des)
{
    queue <int> q;
    int prev= -1;
    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));

    q.push(source);
    vis[source] = 1;


    while(!q.empty()){
        int top = q.front();

        if (level[top] == prev+1){
                path.push(top);
                prev = level[top];
        }
        if (top == check){
            flag = 1;
            break;
        }

        q.pop();
        for (int i=0; i<vec[top].size(); i++){
            if (vis[vec[top][i]] == 0){
                vis[vec[top][i]] = 1;
                level[vec[top][i]] = level[top] +1;
                q.push(vec[top][i]);
            }
        }
    }
}
int main()
{
    freopen("Output.txt", "w", stdout);
    int edge;
    string a, b;

    while (scanf("%d", &edge)){
            for (int i=0; i<max; i++){
                vec[i].clear();
            }
        while (!path.empty()){
            path.pop();
        }
            flag = 0;
        map <string,int> mp1;
        map <int, string> mp2;
        int i=1, j=1;
        for (int k=0; k<edge; k++){

                    cin >> a >>b;
                    if (mp1[a] == 0){
                        mp1[a] = i++;
                        mp2[j++] = a;
                    }
                    if (mp1[b] == 0){
                        mp1[b] = i++;
                        mp2[j++] = b;
                    }

        vec[mp1[a]].push_back(mp1[b]);
        vec[mp1[b]].push_back(mp1[a]);
    }
    string source, des;
    cin >> source >> des;
    if(mp1[source] == 0){
        cout << "No route\n";
    }
    else {
    check = mp1[des];
    bfs(mp1[source], mp1[des]);
    if (flag == 0){
        cout << "No route\n";
    }
    else {
        int top1 = path.front();
        path.pop();
        while (!path.empty()){


            int top2 = path.front();
            path.pop();
            cout << mp2[top1] << "\t" << mp2[top2] <<endl;
            top1 = top2;
            }
        }
    }
    }
    return 0;
}
