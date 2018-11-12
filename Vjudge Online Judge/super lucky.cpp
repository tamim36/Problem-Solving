#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char num1[1000], num2[1000], sum1[1000], sum2[1000], c;
    int len1, len2, add, j=0, carry=0, k, dig;
    scanf("%s", num1);
    scanf("%s", num2);

    if (strlen(num1) > strlen(num2)){
        len1 = strlen(num2);
    }
    else {
        len1 = strlen(num1);
    }

    for (int i=len1 -1; i>=0; i--){
        dig = (num1[i]-'0' + num2[i] - '0');

        k = (dig + carry)%10;
        sum1[j] = k + '0';
        if (9<dig){
            carry = 1;
        }
        else {
            carry = 0;
        }
        j++;
    }
    for (int i=len1-1, j=0; i>=0; i--,j++ ){
        sum2[j] = sum1[i];
    }
    printf("%s", sum2);
    return 0;
}
