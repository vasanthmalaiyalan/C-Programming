#include<stdio.h>
int main()
{
    char str[30];
    printf("ENter a fullname: ");
    scanf("%[^\n]",str);
    printf("Your name: %s",str);
}