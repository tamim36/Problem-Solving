#include <stdio.h>
int main ()
{
    int ara[100];
    int i,j,k,sort,temp;
    scanf("%d", &j);
    for (i=0;i<j; i++){
        scanf("%d", &ara[i]);
    }
    printf("The Given Array is : ");
    for (i=0;i<j; i++){
        printf("%d ", ara[i]);
    }
    for (i=0; i<j; i++){
        for (k=i+1; k<j; k++){
            if (ara[i]<ara[k]){
                temp = ara[i];
                ara[i] = ara[k];
                ara[k]=temp;
            }
        }
    }
    printf("\n\n");
    printf("The Sorting of The Array is : ");
    for (i=0; i<j; i++){
        printf("%d ", ara[i]);
    }
    printf("\n\n");
    return 0;

}
