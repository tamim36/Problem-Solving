#include <bits/stdc++.h>
using namespace std;

queue <int> q;

//map <string,int> visited;

int bfs(string snode, string des, map<string, vector<string> > graph, map <string,int> visited)
{
    queue <string> q;
    q.push(snode);
    visited[snode] = 0;

    while(!q.empty())
    {
        string top = q.front();
        //cout << top << "   " << visited[top] << endl;
        q.pop();

        if (top == des)
            return visited[top];

        for (int i=0; i<graph[top].size(); i++)
        {
            string n = graph[top][i];

            if (visited[graph[top][i]] == -1)
            {
                visited[graph[top][i]] = visited[top] + 1;
                q.push(graph[top][i]);
            }
        }
    }
    return -1;
}


int main()
{
    //freopen("Output.txt", "w", stdout);
    bool ent = false;
    int t;
    cin >> t;
    while(t--)
    {
        if (ent == true)
            cout<< endl;
        ent = true;
        map <string,int> visited;
        string word;
        vector<string>vec[100];
        map<string, vector<string> > graph;
        int i = 5;
        while(word != "*")
        {
            cin >> word;
            int len = word.length();
            vec[len].push_back(word);
        }
        for (int index = 0; index <11; index++)
        {
            for (int j=0; j<vec[index].size(); j++)
            {
                string a = vec[index][j];
                for(int x=0; x<vec[index].size(); x++)
                {
                    string b = vec[index][x];
                    int diff = 0;
                    //cin >> a >> b;
                    for (int i=0; i<index; i++)
                    {
                        if (a[i] != b[i])
                            diff++;
                    }
                    if(diff==1)
                    {
                        graph[a].push_back(b);
                        //graph[b].push_back(a);
                        visited[a] = -1;
                        visited[b] = -1;
                    }
                }

            }
        }
        getchar();
        string abcd = " ";
        while(getline(cin, abcd))
        {
            if(abcd == "")
                break;
            stringstream ss;
            string snode, des;
            ss<<abcd;
            ss>>snode;
            ss>>des;
            int ans = bfs(snode, des, graph, visited);
            cout << snode << " " << des << " " << ans << endl;
        }
    }

    return 0;
}
