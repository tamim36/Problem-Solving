#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
    freopen("vOutput.txt", "w", stdout);
    int lift_pos, my_pos, tes_cas, sum;
    cin >> tes_cas;
    for  (int t=1; t<=tes_cas; t++){
            sum = 0 ;
        cin >> my_pos >> lift_pos;
        if (my_pos > lift_pos ){
            int a = my_pos - lift_pos;
            lift_pos = my_pos + a;
        }
        for (int i=lift_pos; i>0; i--){
            if (i==my_pos){
                sum = sum + 15;
            }
            else
            sum = sum + 4;
        }
    sum = sum + 8;
    printf("Case %d: %d\n", t, sum);
    }

    return 0;
}
