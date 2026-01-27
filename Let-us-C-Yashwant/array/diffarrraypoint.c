#include<stdio.h>

int main()
{
    int num[]={20,30,40,50,60,100};
    int i;
     for(i=0;i<=5;i++)
     {
        printf("address of &num[%d] = %p\n",i,&num[i]);
        printf("element of num[%d] = value of %d\n",i,num[i]);
        printf("*(num+%d) =  %d\n address of num[%d] = %p\n",i,*(num+i),i,&num[i]);
        printf("*(%d+num) = %d\n address of num[%d] = %p\n",i,*(i+num),i,&num[i]);
     }
}