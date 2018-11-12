#include <stdio.h>
#include <string.h>
#define MAX 50000

int bigsum(char str1[], char str2[])
{
    int len1, len2, len3, i, j, sum, carry=0, temp;
    char str3[MAX], temp3[MAX];
    strrev(str1);
    strrev(str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    //Adding 0 to make equal length
    if (len1>len2){
        len3 = len1;
        for (i=len2; i<len3; i++){
            str2[i] = '0';
        }
    }
    else if (len2>len1){
        len3 = len2;
        for (i=len1; i<len3; i++){
            str1[i] = '0';
        }
    }
    else if (len2=len1){
        len3 = len1;
    }

    //Simply calculate sum and store it another string
    for (i=0; i<len3; i++){
        sum = (str1[i]-'0' + str2[i]-'0');
        str3[i] = ((sum+carry)%10 + '0');
        carry=sum/10;
    }
    if (carry==1){
        str3[len3] = '1';
        len3++;
    }
    str3[len3] = '\0';
    for (i=0, j=0; i<strlen(str3); i++){
        if (str3[i] != '0'){
            temp3[j++] = str3[i];
        }
    }
    temp3[j] = '\0';
    return strrev(temp3);
}

int main()
{
    char str1[MAX];
    char str2[MAX], temp1[MAX], temp2[MAX];
    int sum1 , sum2, i, j, add;
    scanf("%s", &str1);
    scanf("%s", &str2);
    //sum1 = bigsum(str1, str2);

    for (i=0, j=0; i<strlen(str1); i++){
        if (str1[i] != '0'){
            temp1[j++] = str1[i];
        }
    }
    temp1[j] = '\0';
    for (i=0, j=0; i<strlen(str1); i++){
        if (str2[i] != '0'){
            temp2[j] = str2[i];
            j++;
        }
    }
    temp2[j] = '\0';

    sum1 = bigsum(str1, str2);

    //printf("%s\n", sum1);

    sum2 = bigsum(temp1, temp2);

    printf("%s\n", sum1);
    printf("%s", sum2);
    return 0;
}

