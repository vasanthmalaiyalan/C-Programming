#include<stdio.h>
#include<string.h>
int main()
{
    char source[]="Sayonara zz";
    char target[20];

    strcpy(target,source);
    printf("source string = %s\n",source);/// %s print address form the inside string character
    printf("source string = %p\n",source);
    printf("target string = %s\n",target);
}