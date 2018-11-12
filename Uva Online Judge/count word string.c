#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int count=0, i, j;
    char str[1000];
    char prevchar=' ';
    while (gets(str)){

    for (i=0; i<strlen(str); i++){
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') ){
            if (prevchar<'a' || prevchar>'z'){
                count++ ;
            }
        }
        prevchar = str[i];
    }
    printf("%d\n", count);
    count=0;
    prevchar=' ';
    }
    return 0;
}
