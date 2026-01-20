/*Logical operator:
    AND op: && ex: a&&b
    OR op:  || example: a||break
    NOT op:  ! ex: !(a<b)
    */
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter value how works operators,&&,||,!(a,b): ");
    scanf("%d %d",&a,&b);
    printf("a&&b = %d\n",a&&b);
    printf("a || b = %d\n",a||b);
    printf("!(a<b) = %d\n",!(a<b));
}