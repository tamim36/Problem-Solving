#include <stdio.h>
#include <math.h>

long isprime(long num)
{
    long i;
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(i = 3; i < sqrt(num); i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
int main ()
{
    long i, j, num, temp=0;
    while (scanf("%ld", &num)){
                if (isprime(num)){
                    printf("%ld", num);
                }
    }
    return 0;
}
