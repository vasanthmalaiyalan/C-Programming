#include<stdio.h>

int main()
{
    int *j;
    int *func();
    j=func();
    printf("*j = %d\n",*j);
    printf("j = %p\n",j);
    printf("&j = %p\n",&j);
}
int *func()
{
    static int k=35; //if you didn't use static program will be carsh because  
    return (&k);
}
/*
Memory visualization
func() start:
Stack:
| k = 35 |  <-- valid

func() end:
Stack cleaned:
| garbage |  <-- k no longer exists

j still holds that address → but memory is invalid
*/