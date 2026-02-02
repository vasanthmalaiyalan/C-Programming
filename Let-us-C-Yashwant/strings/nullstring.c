#include<stdio.h>
int main()
{
    char name[]="vasanth";
    int i=0;

    while(name[i] != '\0')
    {
        printf("%c",name[i]);
        i++;
    }
}