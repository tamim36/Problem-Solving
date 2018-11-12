#include <stdio.h>
#include <string.h>
int strvalue(char str[100])
{
    int i, n, c=0;
    for (i=0; i<strlen(str); i++){
        if (str[i]>='A' && str[i]<='Z'){
            n = str[i]-64;
        }
        else if (str[i]>='a' && str[i]<='z'){
            n = str[i]-96;
        }
        else {
            n=0;
        }
        c = c + n;
    }
    return c;
}
int singlevalue(int num)
{
    int i=0, j, sum=0;

    while (sum>9 || sum == 0){
            if(sum>9){
                num = sum;
            }
            sum = 0;
        while (num>0){
            i=num%10;
            sum = sum +i;
            num = num/10;
        }
    }
    return sum;
}


int main ()
{
    double i, j, num, count=0, word, total1, total2;
    double love, avg;
    char str1[100], str2[100];
    while (gets(str1)){
        gets(str2);

        total1 = strvalue(str1);
        total2 = strvalue(str2);
        total1 = singlevalue(total1);
        total2 = singlevalue(total2);

        if (total1>total2){
            love = (total2/total1)*100;
        }
        else if (total2>total1){
            love = (total1/total2)*100;
        }
        else if (total1 == total2) {
            love = 100;
        }

        printf("%0.2lf %%%\n", love);
    }
    return 0;
}
