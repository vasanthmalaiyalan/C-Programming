#include<stdio.h>
#include<string.h>

int main()
{
    char arr[]="bamboozled";
    int len1,len2;

    len1=strlen(arr);
    len2=strlen("humpy dumpty");

    printf("string=%s length=%d\n",arr,len1);
    printf("string=%s length=%d\n","humpty dumpty",len2);
}