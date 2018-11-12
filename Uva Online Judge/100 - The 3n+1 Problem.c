#include <stdio.h>
int main ()
{
    int i, j,num, count=1, k, l, prev=0, m,n,now,temp;
    while (scanf("%d%d", &i, &j)==2){
        k=i;
        l=j;
        if (i>j){
            temp = i;
            i = j;
            j = temp;
        }

        num = i;
        prev = 0;

        while (num<=j){
                count = 1;

            while (num>1){
                if (num%2==1){
                    num = 3*num+1;
                }
                else {
                    num = num/2;
                }
                count ++;
            }
            if (count>prev){
                prev = count;
            }

            num=i++;
        }
    printf("%d %d %d\n", k, l, prev);
    }
    return 0;
}
