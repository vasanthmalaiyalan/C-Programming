#include<stdio.h>

int main()
{
    char name[3];//expression decay default because array just use like scanf call like -> name,default array+decay  alway first element address     
    float price[3];
    int pages[3],i;

    printf("Enter names,prices and no. of pages of 3 books: \n");
    for(i=0;i<3;i++)
    {
        scanf(" %c %f %d",&name[i],&price[i],&pages[i]);
    }

    printf("And this is what you enter: \n");
    for(i=0;i<3;i++)
    {
        printf(" %c\t %f\t %d\n",name[i],price[i],pages[i]);//this si value store array like this one 
    }
}