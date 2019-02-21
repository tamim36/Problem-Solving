#include<bits/stdc++.h>
using namespace std;

int fx[] = {-1, +1, +0, +0, +0, +0, +0, +0};
int fy[] = {+0, +0, -1, +1, +0, +0, +0, +0};
int fz[] = {+0, +0, +0, +0, -1, +1, +0, +0};
int fw[] = {+0, +0, +0, +0, +0, +0, -1, +1};

int level[11][11][11][11],vis[11][11][11][11];
int lev, row, col;

struct tetra
{
    int waxis;
    int xaxis;
    int yaxis;
    int zaxis;
        tetra(int a, int b, int c, int d){
            xaxis = a;
            yaxis = b;
            zaxis = c;
            waxis = d;
        }
};

void bfs(int sx,int sy, int sz, int sw, int dx, int dy, int dz, int dw)
{
    bool flag = true;
	memset(level, 0, sizeof(level));
	vis[sx][sy][sz][sw]=1;
	queue <tetra> q;
	q.push(tetra(sx,sy,sz, sw));
	while(!q.empty())
	{
		tetra top=q.front();
		q.pop();
		if (top.xaxis == dx && top.yaxis == dy && top.zaxis==dz && top.waxis==dw){
                cout << level[top.xaxis][top.yaxis][top.zaxis][top.waxis] << endl;
                flag=false;
                break;
            }
		for(int k=0;k<8;k++)
		{
			int tx=top.xaxis+fx[k];
			int ty=top.yaxis+fy[k];
			int tz=top.zaxis+fz[k];
			int tw=top.waxis+fw[k]; //Neighbor cell [tx][ty]

			//cout << tx <<  " " << ty <<  " " << tz <<  " " << tw << endl;

			//As it is a wheels
			if (tx == -1) tx = 9;
			else if (tx == 10) tx = 0;
			if (ty == -1) ty = 9;
			else if (ty == 10) ty = 0;
			if (tz == -1) tz = 9;
			else if (tz == 10) tz = 0;
			if (tw == -1) tw = 9;
			else if (tw == 10) tw = 0;

			if(vis[tx][ty][tz][tw]==0)
			{
				vis[tx][ty][tz][tw]=1;
				level[tx][ty][tz][tw]=level[top.xaxis][top.yaxis][top.zaxis][top.waxis]+1;
				q.push(tetra(tx, ty, tz, tw));
			}
		}
	}
	if (flag==true)
        cout << "-1" << endl;
}

int main ()
{
    //freopen("Output.txt", "w", stdout);
    int sx, sy, sz, sw, dx, dy, dz, dw;
    int a,b,c,d;
    int tc, edg;
    cin >> tc;

    while (tc--){

    memset(vis,0,sizeof vis);

    cin >> sx >> sy >> sz >> sw >> dx >> dy >> dz >> dw >> edg;

    for (int i=0; i<edg; i++){
        cin >> a >> b >> c >> d;
        vis[a][b][c][d] = 1;
    }

    bfs(sx, sy, sz, sw, dx, dy, dz, dw);
    }

    return 0;
}

