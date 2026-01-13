#include<stdio.h>
#include<stdlib.h>
int main()
{
    char inp[]="234";
    int x;
    x = atoi(inp);
    x = x * 10;
    printf("Converted data : %d",x);
}