#include<stdio.h>
int calsum(int,int,int); //int calsum(int x,int y,int z) //this is function prototye
int main()
{
    int a,b,c,sum;

    printf("\nEnter any three numbers: ");
    scanf("%d%d%d",&a,&b,&c);

    sum=calsum(a,b,c);
    printf("\nSum= %d\n",sum);
}
int calsum(int x,int y,int z)
{
    return (x+y+z);
}