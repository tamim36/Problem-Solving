#include <bits/stdc++.h>
using namespace std;

int weight[100];
int cost[100];
int dp[100][100];
int n, cap;

int func (int i, int w)
{
    int profit1, profit2;
    if (i==n
        ) return 0;
    if (w+weight[i] <= cap){
        profit1 = cost[i] + func(i+1, w+weight[i]);
    }
    else {
        profit1 = 0;
    }

    profit2 = func(i+1, w);
    return max(profit1, profit2);
}

int main ()
{
    int a, b,c;
    cin >> n >> cap;
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            dp[j][i] = -1;
        }
    }
    for (int i=0; i<n; i++){
        cin >> weight[i] >> cost[i];
    }

    c = func(0,0);
    cout << c;
    return 0;
}
