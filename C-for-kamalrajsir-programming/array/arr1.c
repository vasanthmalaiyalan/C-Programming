#include <stdio.h>
int main()
{
    //static intialization
    int a[5] = {10,1,2,35,6};
    int i;
    printf("The values are : \n");
    for(i=0;i<5;i++)
        printf("value[%d] = %d\n",i,a[i]);
}