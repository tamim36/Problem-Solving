#include <stdio.h>
#include <string.h>
int main ()
{
    int t, len, i,j, k, count=0, m;
    char str[1000], ch;
    scanf("%d", &t);

    for (i=0; i<t; i++){
        scanf("%d", &len);
        scanf(" %[^\t\n]s",&str);
        ch='\0';
        count=0;
        for (j=0; j<len; j++){
            if ((ch!='a')&&(ch!='e')&&(ch!='i')&&(ch!='o')&&(ch!='u')){
                if ((str[j]=='a')||(str[j]=='e')||(str[j]=='i')||(str[j]=='o')||(str[j]=='u')){
                    count++;

                }
        }
        ch=str[j];
        }
        printf("Case %d: %d\n", i+1, count);
    }
    return 0;
}
