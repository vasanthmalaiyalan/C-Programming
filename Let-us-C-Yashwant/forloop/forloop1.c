#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<=2;i++)
    {
        for(j=1;j<=2;j++)
        {
            if(i==j)
               continue;// if condition true only excute continue otherwise print excute
            printf("\ni=%d == j=%d\n",i,j);   
        }
    }
}