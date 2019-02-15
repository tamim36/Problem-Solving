#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int vis[MAX];
int level[MAX];
int ara[MAX];
//vector <int> vec[MAX];
vector <int> path_vec;
queue <int> q;
map <string, int> mpInp;
map <int,string> mpOut;
string snode, des;

int path(int n)
{
    if (n == mpInp[snode])
    {
        return 0;
    }
    path_vec.push_back(ara[n]);
    return path(ara[n]);
}

int main()
{
    //freopen("Output.txt", "w", stdout);
    int index;
    int edge;
    int o = 1;
    while(cin >> edge)
    {
        if(o != 1){
            cout << endl;
        }
        o++;
        index = 1;
        //Ahem make virgin all container
        mpInp.clear();
        mpOut.clear();
        path_vec.clear();
        memset(ara, 0, sizeof(ara));
        vector <int> vec[MAX];
        /*for(int i=0; i<MAX; i++){
            //vec[i].clear();
        }*/


        for (int i=0; i<edge; i++)
        {
            string x, y;
            cin >> x >> y;
            if(mpInp[x] == 0)
            {
                mpInp[x] = index;
                mpOut[index] = x;
                index++;
            }
            if(mpInp[y] == 0)
            {
                mpInp[y] = index;
                mpOut[index] = y;
                index++;
            }
            //mpInp[x] = i
            vec[mpInp[x]].push_back(mpInp[y]);
            vec[mpInp[y]].push_back(mpInp[x]);
        }

        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));


        cin >> snode >> des;
        if(mpInp[des]==0  || mpInp[snode]==0)
        {
            cout << "No route" <<endl;
            //cout << endl;
            continue;
        }

        q.push(mpInp[snode]);
        vis[mpInp[snode]] = 1;

        while(!q.empty())
        {
            int top = q.front();
            //cout << top << "   " << level[top] << endl;
            q.pop();
            for(int i=0; i<vec[top].size(); i++)
            {
                if (vis[vec[top][i]] == 0)
                {
                    q.push(vec[top][i]);
                    vis[vec[top][i]] = 1;
                    ara[vec[top][i]] = top;
                    level[vec[top][i]] = level[top] + 1;
                }
            }
        }
        if((vis[mpInp[des]] == 0)  || (vis[mpInp[snode]] == 0))
        {
            cout << "No route" <<endl;
        }
        else
        {
            int afgd  = path(mpInp[des]);
            for(int i=path_vec.size()-1; i>0; i--)
            {
                //cout << path_vec[i] <<"  "<< path_vec[i-1] << endl;
                cout << mpOut[path_vec[i]] <<" "<< mpOut[path_vec[i-1]] << endl;
            }
            cout << mpOut[path_vec[0]] <<" "<< des << endl;
        }

    }

    return 0;
}

