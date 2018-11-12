#include <stdio.h>
#include <string.h>
int main ()
{
    int i,j, length1, length2;
    char str[1000];
    char res[1000];
    char key[] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\ZXCVBNM,./  ";
    length1 = strlen(key);
    while (gets(str)){
    length2 = strlen(str);
    for (i=0; i<length2; i++){
        for (j=0; j<length1; j++){
            if (str[i] == key[j]){
                res[i] = key[j-1];
            }
        }
    }
    res[length2] = '\0';

    printf("%s\n", res);
    }
    return 0;
}
