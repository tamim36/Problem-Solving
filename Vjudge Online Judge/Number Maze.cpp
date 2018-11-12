#include <bits/stdc++.h>
#define  max 1000
#define infi 2147483600
int fx[] = {+1, -1, +0, -0};
int fy[] = {+0, -0, +1, -1};
int row, col;
using namespace std;

//Like STL pair Function
struct data
{
    int nodex, nodey, weight;
    //constructor
    data() {}
    data (int a, int b, int c)
    {
            nodex = a;
            nodey = b;
            weight = c;
    }
    //operator overloading
    bool operator < (const data& p) const
    {
        return p.weight < weight;
    }
};

int dist[max][max];
int maze[max][max];

void dijkstra(const int start)
{
     priority_queue <data> q;
     int ux, uy, vx, vy, w, co;
    dist[0][0] = 0;
    q.push(data(0, 0, 0));
    while (!q.empty())
    {

        ux = q.top().nodex;
        uy = q.top().nodey;
        w = q.top().weight;
        q.pop();
      //  if (dist[ux][uy] < w)
          //  continue;

        for (int i=0; i < 4; i++){
            vx = ux + fx[i];
            vy = uy + fy[i];
            if (vx>=0 && vx<row && vy >=0 && vy < col){
                co = maze[vx][vy];
                co = co + w;
                if (dist[vx][vy] <= co)
                    continue;
                dist[vx][vy] = co;
                q.push(data(vx, vy, dist[vx][vy]));
            }
        }
    }
    return ;
}

int main ()
{
    //Fast I/O technique
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cost, maze_num;
    cin >> maze_num;
    for (int m=0; m<maze_num; m++){
        cin >> row >> col;
        for (int i=0; i<row; i++){
                for (int j=0; j<col; j++){
                    dist[i][j] = infi;
                }
        }
        for (int i=0; i < row; i++){
            for (int j=0; j<col ; j++){
                cin >> maze[i][j];
            }
        }


        dijkstra(1);
        /*if (dist[row-1][col-1] == infi)
            cout << "impossible\n";
        else*/
            cout << dist[row-1][col-1] << "\n";
    }

    return 0;
}
