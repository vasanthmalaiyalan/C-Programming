#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *names[6];
    char n[50];
    int len,i;
    char *p;
    
    for(i=0;i<6;i++)
    {
        printf("Enter name: ");
        scanf("%s",n);
        len=strlen(n);
        p=malloc(len+1);
        strcpy(p,n);
        names[i]=p;
    }
    for(i=0;i<6;i++)
       printf("%s\n",names[i]);
}