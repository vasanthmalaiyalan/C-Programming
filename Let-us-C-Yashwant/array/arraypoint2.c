#include<stdio.h>
int main()
{
    int num[]={20,30,40,20,40,50,60};
    int i,*j;

    j=&num[0];
    for(i=0;i<=5;i++)
    {
        printf("address of j = %p\n",j);
        printf("element of *j = %d\n",*j);
        j++; //increment pointer to point to next address
    }
}