#include<stdio.h>
//demonstration of call by reference
int display(int *);
int main()
{
    int i;
    int marks[]={23,34,45,67,89,12,56};
     for(i=0;i<=6;i++)
       display(&marks[i]); //& -> means geather address
}
int display(int *m)// *m -> means pointer only value
{
      printf("%d\n",*m);
}
