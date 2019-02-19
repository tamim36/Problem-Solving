#include<bits/stdc++.h>
using namespace std;

int fx[] = {+1, -1, +0, +0, +0, +0};
int fy[] = {+0, +0, +1, -1, +0, +0};
int fz[] = {+0, +0, +0, +0, +1, -1};
int level[31][31][31],vis[31][31][31];
int lev, row, col;

struct triple
{
    int xaxis;
    int yaxis;
    int zaxis;
        triple(int a, int b, int c){
            xaxis = a;
            yaxis = b;
            zaxis = c;
        }
};

void bfs(int sx,int sy, int sz, int dx, int dy, int dz)
{
    bool flag = true;
	memset(level, 0, sizeof(level));
	vis[sx][sy][sz]=1;
	queue <triple> q;
	q.push(triple(sx,sy,sz));
	while(!q.empty())
	{
		triple top=q.front();
		q.pop();
		if (top.xaxis == dx && top.yaxis == dy && top.zaxis==dz){
                cout << "Escaped in "<< level[top.xaxis][top.yaxis][top.zaxis] << " minute(s)." << endl;
                flag=false;
                break;
            }
		for(int k=0;k<6;k++)
		{
			int tx=top.xaxis+fx[k];
			int ty=top.yaxis+fy[k];
			int tz=top.zaxis+fz[k]; //Neighbor cell [tx][ty]
			if(tx>=0 && tx<row && ty>=0 && ty<col && tz>=0 && tz<lev && vis[tx][ty][tz]==0)
			{
				vis[tx][ty][tz]=1;
				level[tx][ty][tz]=level[top.xaxis][top.yaxis][top.zaxis]+1;
				q.push(triple(tx, ty, tz));
			}
		}
	}
	if (flag==true)
        cout << "Trapped!" << endl;
}

int main ()
{
    //freopen("Output.txt", "w", stdout);
    int sx, sy, sz, dx, dy, dz;

    while (cin >> lev >> row >> col){

            if (lev == 0 && row == 0 && col == 0)
                break;

    memset(vis,0,sizeof vis);

    for (int l=0; l<lev; l++){
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                char ch;
                cin >> ch;
                if (ch == '.'){
                    //vis[i][j] = 1;
                }
                else if (ch == '#'){
                    vis[r][c][l] = 1;
                }
                else if (ch == 'S'){
                    sx = r;
                    sy = c;
                    sz = l;
                }
                else if (ch == 'E'){
                    dx = r;
                    dy = c;
                    dz = l;
                }
            }
        }
    }
    bfs(sx, sy, sz, dx, dy, dz);
    }
    /*for (int l=0; l<level; l++){
        for (int r=0; r<row; r++){
            for (int c=0; c<col; c++){
                cout << vis[r][c][l];
            }
            cout << endl;
        }
        cout << endl << endl;
    }*/

    return 0;
}
