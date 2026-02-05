#include<stdio.h>
#include<string.h>

int main()
{
    char source[]="Folks!";
    char target[30]="Hello";

    strcat(target,source);//first target only output like target+source
    printf("source string = %s\n",source);
    printf("target string = %s\n",target);
}