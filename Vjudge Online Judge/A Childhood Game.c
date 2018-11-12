#include <stdio.h>
int main ()
{
    long long cas, i, j, mar;
    char s1[100];
    scanf("%lld", &cas);
    for (i=0; i<cas; i++){
        scanf("%lld", &mar);
        scanf("%s", &s1);


        if(s1[0]=='A'){
            if (mar%2==1){
                printf("Case %lld: Bob\n", i+1);
            }
            else {
                printf("Case %lld: Alice\n",i+1);
            }
        }
        else if (s1[0]=='B'){
            if (mar%2==1){
                printf("Case %lld: Bob\n", i+1);
            }
            else {
                printf("Case %lld: Alice\n", i+1);
            }
        }
    }
    return 0;
}

