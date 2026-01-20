#include<stdio.h>
int main()
{
    int x[5],i,max;
    printf("Enter the max no.of values to insert: ");
    scanf("%d",&max);
    for(i=0;i<max;i++)
       scanf("%d",&x[i]);
    printf("The given values are : \n");
    for(i=0;i<5;i++)
        printf("%d\t",x[i]);   
}