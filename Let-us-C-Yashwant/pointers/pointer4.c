#include<stdio.h>
int main()
{
    int i=3,*x;
    float j=1.5,*y;
    char k='c',*z;

    printf("value of i = %d\n",i);
    printf("value of j = %f\n",j);
    printf("value of k = %c\n",k);
    x=&i;
    y=&j;
    z=&k;
    printf("original address of x = %p\n",x);
    printf("original address of y = %p\n",y);
    printf("original address of z = %p\n",z);
    x++;
    y++;
    z++;
    printf("new address of x = %p\n",x);
    printf("new address of y = %p\n",y);
    printf("new address of z = %p\n",z);
    
}