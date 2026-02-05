#include<stdio.h>

int main()
{
    char name[3];
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
        printf(" %c\t %f\t %d\n",name[i],price[i],pages[i]);
    }
}