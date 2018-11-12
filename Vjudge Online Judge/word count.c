#include <stdio.h>
#include <string.h>
int main ()
{
    int count , i , len;
    char str[1000];
    while (gets(str)){
        count = 1;

        len = strlen(str);
        for (i=0; i<len; i++){
            if (str[i]==' '){
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
