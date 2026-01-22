#include<stdio.h>
int main()
{
    int i=10;
    int *p = &i; // already os allocated address i=10 is created just that address &i is take it and return it

    printf("i=%d\n",i);
    printf("*p=%d\n",*p); //but *p is pointer so this one is that returned addres of &i that values only point and get it 
}