#include<stdio.h>
int display (int* , int);
int main()
{
    int num[]={23,45,67,76,75,46};
    display(&num[0],6);
}
int display(int *j, int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
       printf("num[%d] of value : %d\n",i,*j);
       j++;
    }
}