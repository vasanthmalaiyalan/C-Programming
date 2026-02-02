#include<stdio.h>
int main()
{
    char name[]="vasanth";
    char *ptr;

    ptr=name; //store base address of string
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    } 
}