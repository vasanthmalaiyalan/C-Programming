#include<stdio.h>
#include<string.h>

int constxstrlen(const char *);
int main(void)
{
    char arr[]="jarvis";
    int len1,len2;
    len1=constxstrlen(arr);
    len2=constxstrlen("hello bro");//&"hello bro"[0] = 'h' and this type of value means literal value read only value by default

    printf("string = %s lenght = %d\n",arr,len1);
    printf("string = %s lenght = %d\n","hello bro",len2);

}
int constxstrlen(const char *s)//s belike inside &arr[0] and add pointer arr[0]
{
    int length=0;
    while(*s!='\0')
    {
        length++;
        s++;
    }
    return(length);
}