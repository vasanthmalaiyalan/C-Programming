#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int noe,i;//number of elements
    printf("Enter the no.of elements: ");
    scanf("%d",&noe);
    p = (int *) calloc(noe,sizeof(int));
    printf("calloc initialized 0 value= %d\n",p[0]);
    printf("Enter the values: ");
    for(i=0;i<noe;i++)
        scanf("%d",&p[i]);
    printf("Values in array: \n");
    for(i=0;i<noe;i++)
      printf("%d\t",*(p+i));    
}