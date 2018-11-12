#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int i,length;
    long long evensum, oddsum,res;
    char str[1050];
    while (gets(str)){
        evensum = 0;
        oddsum = 0;

        for (i=0; i<strlen(str); i++){
            evensum = evensum + (str[i]-48);
            i++;
            evensum = evensum + (s)
        }
        res = evensum - oddsum;
        if (str[i] == '0'){
            break;
        }
        else if (res%11==0){
            printf("%s is a multiple of 11.\n", str);
        }
        else {
            printf("%s is not a multiple of 11.\n", str);
        }
    }

    return 0;
}
