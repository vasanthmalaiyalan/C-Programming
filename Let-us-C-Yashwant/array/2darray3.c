#include<stdio.h>

int main()
{
    int s[4][2]={
        {1234,43},
        {2345,56},
        {5432.32},
        {1345,56}
    };
    int i,j;

    for(i=0;i<=3;i++)
    {
        printf("\n");
        for(j=0;j<=1;j++)
           printf("%d ",*(*(s+i)+j));
    }
}