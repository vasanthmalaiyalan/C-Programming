#include<stdio.h>
int main()
{
    int i=3;
    printf("\nAddress of i = %p",(void*)&i);//only printf standard use (void*) other vise just use &i
    printf("\nvalues of i = %d",i);
    printf("\nvalue of *(i) = %d\n",*(&i));
}