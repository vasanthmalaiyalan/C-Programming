#include<stdio.h>
int main()
{
    char c[10];
    int i;
    printf("Enter the chars : \n");
    for(i=0;i<5;i++)
        scanf("%c",&c[i]);
    c[i]='\0';
    printf("given input is : %s",c);
}