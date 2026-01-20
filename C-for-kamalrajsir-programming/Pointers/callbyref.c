#include<stdio.h>
void modify(int *x) //this one is decleration
{
    *x = *x * 10; // this line is start with *x means content access
    printf("address in x: %p\n",x);
}
int main()
{
    int a=10;
    modify(&a); //&a => address
    printf("\naddress of a: %p\n",&a);
    printf("\na = %d",a);
}