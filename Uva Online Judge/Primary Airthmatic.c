#include <stdio.h>
#include <string.h>

int main()
{
    int i, j , len1, len2, len3, num, sum, temp, carry=0,numcarry=0;
    char s1[15], s2[15], s3[15], s4[15], s5[15];
    while(1){
            numcarry=0;
            carry = 0;
    scanf("%s", s4);
    scanf("%s", s5);

    len1 = strlen(s4);
    len2 = strlen(s5);
    if (len1==1 && len2==1){
        if ((s4[0]=='0')&&(s5[0]=='0')){
        break;
    }
    }
    for (i=0,j=len1 -1; i<len1; i++, j--){
        s1[i] = s4[j];
    }
    for (i=0,j=len2 -1; i<len2; i++, j--){
        s2[i] = s5[j];
    }
    if (len1>len2){
        len3 = len1;
        for (i=len2; i<len3; i++){
            s2[i] = '0';
        }
        for (i=len1; i<len3; i++){
            s1[i] = '0';
        }
    }
    else if (len2>len1){
        len3 = len2;
        for (i=len1; i<len3; i++){
            s1[i] = '0';
        }
        for (i=len2; i<len3; i++){
            s2[i] = '0';
        }
    }
    else if (len1==len2){
        len3 = len1;
    }
    s1[len3] = '\0';
    s2[len3] = '\0';


    for (i=0; i<len3; i++){
        sum = (s1[i] - '0' + s2[i]-'0');
        s5[i] = ((sum+carry)%10 + '0');
        carry = (sum+carry)/10;
        if (carry == 1){
            numcarry++;
        }
    }

    if (numcarry==0){
        printf("No carry operation.\n");
    }
    else if (numcarry==1){
        printf("%d carry operation.\n", numcarry);
    }
    else {
    printf("%d carry operations.\n", numcarry);
    }
    }
    return 0;
}


