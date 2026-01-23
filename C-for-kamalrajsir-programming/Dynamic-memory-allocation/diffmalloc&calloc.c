#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,*p1;
    int i;
    p = (int *)malloc(3*sizeof(int));
    p1 = (int *)calloc(3,sizeof(int));
    printf("Values in *p \n");
    for(i=0;i<3;i++)
       printf("%d\t",p[i]);

    printf("\n values in *p1\n");
    for(i=0;i<3;i++)
       printf("%d\t",p1[i]);   
}