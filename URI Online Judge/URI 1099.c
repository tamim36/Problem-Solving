#include <stdio.h>
int main ()
{
    double i, j, k,l,x=1,y=3,z=2;

    for (i=0; i<=2; ){
        for (j=1; j<4; ){
            printf("I=%0.1lf J=%0.1lf\n", i,x);
            break;
        }
        for (k=2; k<4; ){
            printf("I=%0.1lf J=%0.1lf\n", i,z);
            break;
        }
        for (l=3; l<4; ){
            printf("I=%0.1lf J=%0.1lf\n", i,y);
            break;
        }
        y=y+0.2;
        z=z+0.2;
        x=x+0.2;
        i=i+0.2;
    }
    return 0;
}

