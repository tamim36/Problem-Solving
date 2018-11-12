#include<bits/stdc++.h>
using namespace std;
char a[10], b[10];
int fx[] = {+1, -1, +1, -1, +2, -2, +2, -2};
int fy[] = {+2, +2, -2, -2, +1, +1, -1, -1};
int level[10][10],vis[10][10];
int row=8,col=8;
void bfs(int sx,int sy, int dx, int dy)
{
	memset(vis,0,sizeof vis);
	memset(level, 0, sizeof(level));
	vis[sx][sy]=1;
	queue <pair<int,int > > q;
	q.push(pair<int,int>(sx,sy));
	while(!q.empty())
	{
		pair<int,int> top=q.front(); q.pop();
		if (top.first == dx && top.second == dy){
                printf("To get from %s to %s takes %d knight moves.\n", a, b, level[top.first][top.second]);
                break;
            }
		for(int k=0;k<8;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
			if(tx>0 && tx<=row && ty>0 && ty<=col && vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				level[tx][ty]=level[top.first][top.second]+1;
				q.push(pair<int,int>(tx,ty));
			}
		}
	}
}
int main()
{
    freopen("Output.txt", "w", stdout);
    int sx, sy, dx, dy;

    while(scanf("%s%s", a, b)==2){
        int sx, sy, dx, dy;
        sx = a[0] - 'a' + 1;
        sy = a[1] - '0';
        dx = b[0] - 'a' + 1;
        dy = b[1] - '0';
        bfs(sx, sy, dx, dy);
    }
    return 0;
}
