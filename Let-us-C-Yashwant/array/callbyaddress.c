#include<stdio.h>
int display(int *);
int main()
{
    int i;
    int marks[]={12,34,56,67,56,89,45};
     for(i=0;i<=6;i++)
       display(&marks[i]);
}
int display(int *m){
   printf("show address : %p\n",m);
}