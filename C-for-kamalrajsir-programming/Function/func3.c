//function has no input  but return the values
#include<stdio.h>
int addition()
{
    int x,y;
    printf("Enter two values : ");
    scanf("%d%d",&x,&y);
    return x+y;
}
int main()
{
    //int res = addition();
    printf("Addition of two numbers: %d\n",addition());
}