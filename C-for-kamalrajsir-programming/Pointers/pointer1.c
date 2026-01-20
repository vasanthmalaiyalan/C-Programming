#include<stdio.h>
int main()
{
    int a=10;
    int *ptr;
    ptr = &a;
    printf("Data in *ptr is %d\n",*ptr);
    printf("Address of a like &a: %p\n",&a);
    printf("Address of a using ptr: %p\n",ptr);
    printf("Data a : %d",a);
    *ptr = *ptr *20;
    printf("\nthe value of a = %d",a);
    return 0;
}