//function gets inputs and return values
// this is call by value ok
// this code is local variable of function like compare to func5.c
#include<stdio.h>
int multiplication(int x,int y)
{
    return x*y;
}
int main()
{
    int a,b;
    printf("ENter two values: ");
    scanf("%d%d",&a,&b);
    printf("Multiplication result: %d",multiplication(a,b));
}