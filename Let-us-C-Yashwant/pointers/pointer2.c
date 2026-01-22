#include<stdio.h>
int main()
{
    int i=3;
    int *j;

    j=&i;
    printf("Address of i = %p\n",(void*)&i);
    printf("Adddress of j=&i = %p\n",(void*)j);
    printf("Adrress of j = %p\n",(void*)&j);// j is indiviual address 
    printf("value of j = %p\n",(void*)j);
    printf("value of i = %d\n",i);
    printf("value of i = %d\n",*(&i));
    printf("value of i = %d\n",*j);
}