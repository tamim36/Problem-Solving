#include <stdio.h>
#include <string.h>
int main ()
{
    char str[1000];
    char dec[1000];
    int i , j , length;
    length = strlen(str);
    while (gets(str)){
    for (i=0; i<strlen(str); i++){
        dec[i] = str[i]-7;
    }

    dec[strlen(str)] = '\0';
    printf("%s\n", dec);
    }
    return 0;
}
