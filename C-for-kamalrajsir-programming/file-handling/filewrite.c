#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int i;
    fp = fopen("input.txt","w");
    char ch[20];
    int choice=1;
    while(choice!=0)
    {
    printf("Enter the string : ");
    scanf("%[^\n]",ch); 
    /*for(i=0;ch[i]!='\0';i++)
    {
        fputc(ch[i],fp);
    }*/
    fputs(ch,fp);
    printf("do you want to continue (yes=1,no=0): ");
    scanf("%d",&choice);
    }
    fclose(fp);
}