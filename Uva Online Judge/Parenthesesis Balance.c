#include <stdio.h>
int main ()
{
    int leftfirst, rightfirst, leftthird, rightthird, i, j, count;
    char str[10000];
    while(1){
        gets(str);
        leftfirst=0, rightfirst=0, leftthird=0, rightthird=0;
        for (i=0; i<strlen(str); i++){
            if (str[i] == '('){
                    leftfirst++;
                }
            else if (str[i]==')'){
                rightfirst++;
            }
            else if (str[i]=='['){
                leftthird++;
            }
            else if (str[i]==']'){
                rightthird++;
            }
        }
        if ((leftfirst==rightfirst)&&(leftthird==rightthird)){
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
