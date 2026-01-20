#include<stdio.h>
int z; //this is global variable compare func4.c
void multiplication(int x,int y)
{
    z = x*y; // this is golbal variable
}
void addition(int x,int y)
{
    z = x + y;
}
int main()
{
    int a,b;
    printf("Enter two values: ");
    scanf("%d%d",&a,&b);
    multiplication(a,b);
    printf("Multiplication result: %d\n",z);
    addition(a,b);
    printf("Addition result: %d",z);
}