/*Logical operator:
    AND op: && ex: a&&b
    OR op:  || example: a||break
    NOT op:  ! ex: !(a<b)
    */
#include<stdio.h>
int main()
{
    int a=2,b=4;
    printf("a&&b = %d\n",a&&b);
    printf("a || b = %d\n",a||b);
    printf("!(a<b) = %d\n",!(a<b));
}