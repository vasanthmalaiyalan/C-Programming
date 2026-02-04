#include<stdio.h>
#include<string.h>
void xstrcpy(char * ,const char *);

int main(void)
{
    char source[]="hello";
    char target[10];

    xstrcpy(target,source);//inside data store of target belike target[0]='h',target[1]='e'
    printf("source string = %s\n",source);
    printf("target string = %s\n",target);
}
void xstrcpy(char *t ,const char *s)// sums type of function only return value int uses so another no return value use void
{
    while(*s!='\0')
    {
        *t=*s;// inside s -> belike s=&source[0] -> *s=source[0]
        s++;
        t++;
    }
    *t='\0';