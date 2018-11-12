#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int cost[MAX], weight[MAX];
int dp[MAX][32];
int items, limit;

int superSale(int i, int w)
{
    int prof1 = 0, prof2 = 0;

    if (i == items)
        return 0;

    if (dp[i][w] != -1)
       return dp[i][w];

    if (w + weight[i] <= limit)
        prof1 = cost[i] + superSale(i+1, w+weight[i]);
    else
        prof2 = 0;


    prof2 = superSale(i+1, w);

    dp[i][w] = max(prof1, prof2);
        return dp[i][w];
    //return max(prof1, prof2);
}


int main()
{
    //freopen("Output.txt", "w", stdout);
    int T, w, c,g;
    scanf("%d", &T);
    while(T--)
    {
        memset(cost, 0 , sizeof(cost));
        memset(dp,-1,sizeof(dp));
        memset(weight,0,sizeof(weight));
        int total =0;
        scanf("%d", &items);
        for (int i=0; i<items; i++){
            cin >> c >> w;
            cost[i] = c;
            weight[i] = w;
        }
        scanf("%d", &g);
        for (int i=0; i<g; i++)
        {
            cin >> limit;
            memset(dp,-1,sizeof(dp));
            int res = superSale(0, 0);
            total = res + total;
        }
        printf("%d\n", total);
    }
    return 0;
}
