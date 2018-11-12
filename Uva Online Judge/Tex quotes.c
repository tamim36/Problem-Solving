#include <stdio.h>
#include <string.h>
int main ()
{
    int i, k=0, nw=0;
    char str[1000], res[1000];
    while (gets(str)){
            nw=0;
    for (i=0; i<strlen(str); i++){
        if (str[i]!='"'){
            res[nw] = str[i];
            nw++;
        }

        else if ((str[i]=='"')&&(k==0))  {
            k++;
            res[nw]='`';
            res[nw+1]='`';
            nw=nw+2;
        }
        else if ((str[i]=='"')&&(k==1))  {
            k--;
            res[nw]=39;
            res[nw+1]=39;
            nw=nw+2;
        }
    }
    res[nw] = '\0';
    printf("%s\n", res);
    }
    return 0;
}
