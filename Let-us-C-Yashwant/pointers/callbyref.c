#include<stdio.h>
void swapv(int*, int*);

int main()
{
    int a=10,b=20;
    swapv(&a,&b);
    printf("\na = %d b = %d\n",a,b);
}
void swapv(int *x,int *y) // This is compiler perspective(int *x=&a) this is pointer didn't change address only change address inside value ok
{
    int t;

    t=*x;
    *x=*y;
    *y=t;
}