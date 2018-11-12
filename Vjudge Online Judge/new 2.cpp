#include <bits/stdc++.h>
using namespace std;

int banana[200][200];

int main()
{

int i,j,n,test,t,k;

    scanf("%d", &test) ;

    for (t=1; t<=test; t++){
        scanf("%d", &n);
        for (i=0, k=1; i<2*n-1; i++){
            for (j=0; j<k; j++){
                scanf("%d", &banana[i][j]);

                if (i==0)
                    continue;
                if (i<n && j==0)
                    banana[i][0] += banana[i-1][0];
                else if (i<n && j==k-1)
                    banana[i][j] +=banana[i-1][j-1];
                else if (i<n)
                    banana[i][j] += max( banana[i-1][j-1] , banana[i-1][j] );
                else
                    banana[i][j] += max( banana[i-1][j], banana[i-1][j+1]);
            }
            if (i<n-1)
                k++;
            else k--;
        }
        printf ("Case %d: %d\n", t, banana[2*n-2][0]);
    }
    return 0;
}
