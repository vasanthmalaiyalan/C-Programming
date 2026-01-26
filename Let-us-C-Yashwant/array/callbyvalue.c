#include<stdio.h>
//demonstration of call by value
int display(int);
int main()
{
    int i;
    int marks[]={11,23,45,56,79,60,48};

    for(i=0;i<=6;i++)
       display(marks[i]);
}
int display(int m){
    printf("%d\n",m);
}