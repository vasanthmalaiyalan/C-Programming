#include<stdio.h>
//usage of pointer to an array
int main()
{
    int s[5][2] = {
        {1234,56},
        {3456,12},
        {2345,23},
        {2345,44}
    };
    int (*p)[2]; 
    int i,j,*pint;

    for(i=0;i<=3;i++)
    {
        p = &s[i];
        pint = p;
        printf("\n");
        for(j=0;j<=1;j++)
            printf("%d ",*(pint+j));// like *(s[o]+0) => 
    }
}