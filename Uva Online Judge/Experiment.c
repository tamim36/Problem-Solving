
#include <stdio.h>
#include <string.h>
int main ()
{
    int word_start=0,len, word_end=0, i, j, index=0;
    char str[100], rev[100];
    gets(str);
    len = strlen(str);

    len = len-1;
    word_end =0;

    while (word_start>=word_end){
        rev[index] = str[word_start];
        index++;
        word_start--;
    }
    rev[index++] = '\0';
    printf("%s\n", rev);
    return 0;
}
