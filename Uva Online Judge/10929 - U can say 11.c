#include <stdio.h>
int main ()
{
    long long num;
    int i;
    while (scanf("%lld", &num)){
        if (num == 0){
            break;
        }
        else if (num%11==0){
            printf("%0lld is a multiple of 11.\n", num);
        }
        else {
            printf("%0lld is not a multiple of 11.\n", num);
        }
    }
    return 0;
}
