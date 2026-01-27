#include<stdio.h>
int main()
{
    int num[]={23,45,67,87,12,78};
    int i;

    for(i=0;i<=5;i++)
    {
        printf("element of array no. %d\t",i);
        printf("value of array no. %d\t",num[i]);
        printf("Address of array : %p\t",&num[i]);
    }
}