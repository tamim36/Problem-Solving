#include <stdio.h>
#include <string.h>
int main ()
{
    int i, length, count=0;
    char str[1000];
    char prevchar=' ';
    while (gets(str)){
        for (i=0; i<strlen(str); i++){
            if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
                if (prevchar==' ' || prevchar =='\0'){
                    count++;
                }
            }
            prevchar=str[i];
        }
        printf("%d\n", count);
        count = 0;
        prevchar=' ';
    }
    return 0;
}
