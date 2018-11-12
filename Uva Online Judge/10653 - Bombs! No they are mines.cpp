#include <bits/stdc++.h>
#define pii pair<int,int>
int vis[1000][1000];
int level[1000][1000];
int cell[1000][1000];
int fx[] = {+1, -1, +0, -0};
int fy[] = {+0, -0, +1, -1};
int row, col;

using namespace std;
int main()
{
    //freopen("Output.txt", "w", stdout);
    queue<pii>q;
    while (scanf("%d%d", &row, &col)){

        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));
        memset(cell, 0, sizeof(cell));
        while (!q.empty()){
            q.pop();
        }

        if (row == 0 && col == 0){
            break;
        }
        int bomb_row;
        cin >> bomb_row;
        for (int i=0; i<bomb_row; i++){
            int num_row,num_bomb;
            cin >> num_row >> num_bomb;
            for (int j=0; j<num_bomb; j++){
                int x;
                cin >> x;
                cell[num_row][x] = 1;
            }
        }
        int sx, sy;
        int dx, dy;
        cin >> sx >> sy;
        cin >> dx >> dy;


        q.push(pii(sx,sy));
        while (!q.empty()){
            pii top = q.front();
            if (top.first == dx && top.second == dy){
                cout << level[top.first][top.second] << endl;
                break;
            }
            q.pop();
            for (int i=0; i<4; i++){
                int nx = top.first + fx[i];
                int ny = top.second  + fy[i];
                if (nx>=0 && nx<row && ny>=0 && ny<col && cell[nx][ny] != 1 && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    level[nx][ny] = level[top.first][top.second] + 1;
                    q.push(pair<int,int> (nx,ny));
                }
            }
        }
    }
    return 0;
}
