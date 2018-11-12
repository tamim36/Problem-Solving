#include <stdio.h>
int main ()
{
    long long int row, col, i;
    long long int mat[10][10];
    long long int ara[2];
    scanf("%lld", &i);
    for(row=0; row<i; row++){
        for(col=0; col<3; col++){
            scanf("%lld", &mat[row][col]);
        }
    }
    for(row=0; row<i; row++){
        if(mat[row][0]>mat[row][1]&&mat[row][0]<mat[row][2] || mat[row][0]>mat[row][2]&&mat[row][0]<mat[row][1]){
        ara[row] = mat[row][0];
    }
    else if (mat[row][1]>mat[row][0]&&mat[row][1]<mat[row][2] || mat[row][1]>mat[row][2]&&mat[row][1]<mat[row][0]){
        ara[row] = mat[row][1];
    }
    else {
        ara[row] = mat[row][2];
    }
}
    for(row=0; row<i; row++){
        printf("Case %lld: %lld\n", row+1, ara[row]);
    }
    return 0;
}
