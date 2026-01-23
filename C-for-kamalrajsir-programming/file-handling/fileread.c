#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;//FILE ->prebuilt libraray function
    fp = fopen("../hello.c","r");
    char ch;
    if(fp==NULL)
    {
        printf("Error....file does not Exit\n");
        exit(-1);// that (-1) or (1) is means terminate
    }
    else{
        while(1)
        {
            ch = fgetc(fp);
            if(ch!=EOF)
               printf("%c",ch);
            else
                break;   
        }
        fclose(fp);
    }

}