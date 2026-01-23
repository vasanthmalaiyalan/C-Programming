#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int noe,i;//number of elements
    printf("Enter the no.of elements: ");
    scanf("%d",&noe);
    p = (int *) malloc(noe*sizeof(int));
    printf("malloc uninitialized garbage value= %d\n",p[0]);
    printf("size of p = %ld\n",sizeof(*p));
    printf("Enter the values: ");
    for(i=0;i<noe;i++)
        scanf("%d",&p[i]);
    printf("Values in array: \n");
    for(i=0;i<noe;i++)
      printf("%d\t",*(p+i));    
}