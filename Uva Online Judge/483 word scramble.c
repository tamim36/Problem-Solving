#include <stdio.h>
#include <string.h>
int main ()
{
    char str[1200];
    char word[1200];
    char rev_str[1200];
    //int i=0, j=0, num=0,word_start=0, word_end=0, len, index=0,temp;
        while (gets(str)){
        int i=0, j=0, num=0,word_start=0, word_end=0, len, index=0,temp;
        len = strlen(str);                        //YOU ARE THE

        for (i=0; i<=len; i++){

            if (str[i]==' ' || str[i] == '\0'){
                while (word_start>=word_end){     //you are the best
                    temp = word_start; //2
                    //word_start--;
                    rev_str[index] = str[word_start];
                    word_start--;
                    index++;
                }
                rev_str[index++] = ' ';
                word_end = i+1;

            }
    else {
        word_start = i;
    }
        }
        //rev_str[len] = '\0';
        rev_str[len] = '\0';
        printf("%s\n", rev_str);
        }
        return 0;
}
