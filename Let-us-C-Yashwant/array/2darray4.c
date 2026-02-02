#include<stdio.h>
int main()
{
    int n[3][3]={
            2,4,3,
            6,8,5,
            3,5,1
        };
    printf("%p\n%d\n%d\n",*n,n[2][2],n[1][1]);    
}