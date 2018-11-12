#include <bits/stdc++.h>
int fx[] = {+1, -1, +1, -1, +2, -2, +2, -2};
int fy[] = {+2, +2, -2, -2, +1, +1, -1, -1};
int vis[10][10];
int level[10][10];
using namespace std;
int main ()
{
    //freopen("Output.txt", "w", stdout);
    int temp=0;
    int res, ans1, ans2;
    char a[10], b[10];

    while(scanf("%s%s", a, b)){
        int sx, sy, dx, dy;
        sx = a[0] - 'a' + 1;
        sy = a[1] - '0';
        dx = b[0] - 'a' + 1;
        dy = b[1] - '0';

        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));

        queue <pair <int,int > > q;
        q.push(pair <int,int> (sx,sy));
        vis[sx][sy] = 1;
        while (!q.empty()){
            pair <int,int> top = q.front();
            q.pop();

            if (top.first == dx && top.second == dy){
                printf("To get from %s to %s takes %d knight moves.\n", a, b, level[top.first][top.second]);
                \
                break;
            }
            for (int i=0; i<8; i++){
                int nx = top.first + fx[i];
                int ny = top.second + fy[i];
                if (nx>0 && nx<=8 && ny>0 && ny<=8 && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    level[nx][ny] = level[top.first][top.second] + 1;
                    q.push(pair<int,int> (nx,ny));
                }
            }
        }
    }
    return 0;
}
