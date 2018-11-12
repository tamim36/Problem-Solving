#include <stdio.h>
#include <ctype.h>
int main ()
{
    int count, i , j;
    char str[1000];
    while (gets(str)){
            count=0;
        for (i=0; i<=strlen(str); i++){
            if (isalpha(str[i])){
                if (!isalpha(str[i+1])){
                    count ++;
                }
            }

        }
        printf("%d\n", count);
    }
    return 0;
}
