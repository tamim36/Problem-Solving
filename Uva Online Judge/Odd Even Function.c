#include <stdio.h>


/**
 * Checks whether the least significant bit of the number is 1 or not. If it is
 * 1 then the number is odd else even.
 */
int isOdd(int num)
{
    return (num & 1);
}


int main()
{
    int num;

    /*
     * Reads a number from user
     */
    printf("Enter any number: ");
    scanf("%d", &num);


    /* If isOdd() function returns 1 then the number is odd */
    if(isOdd(num))
    {
        printf("The number is odd.");
    }
    else
    {
        printf("The number is even.");
    }

    return 0;
}
