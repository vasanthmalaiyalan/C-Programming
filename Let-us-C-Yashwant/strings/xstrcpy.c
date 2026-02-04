#include<stdio.h>
#include<string.h>
void xstrcpy( char * ,char *);

int main(void)
{
    char source[]="hello";
    char target[10];

    xstrcpy(target,source);
    printf("source string = %s\n",source);
    printf("target string = %s\n",target);
}
void xstrcpy(char *t ,char *s)
{
    while(*s!='\0')
    {
        *t=*s;
        s++;
        t++;
    }
    *t='\0';
}