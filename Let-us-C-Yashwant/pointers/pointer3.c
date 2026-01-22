#include<stdio.h>
int main()
{
    int i=3,*j,**k;

    j=&i;
    k=&j;
    printf("Address of &i = %p\n",(void*)&i);
    printf("Address of j = %p\n",(void*)j);
    printf("Address of *k (*This is pointer) = %p\n",(void*)*k); //point to address that address only get in to value 
    printf("Address of &j  = %p\n",(void*)&j);
    printf("Address of &k = %p\n",(void*)&k);
    printf("value of k = %p\n",(void*)k);
    printf("value of j = %p\n",(void*)j);
    printf("value of i = %d\n",i);
    printf("value of *j = %d\n",*j);
    printf("value of **k (This means go to *k -> inside *k (&i) address store in value like 0.x456 then **k means go to -> that value represent address of (&i) next you will get that value = %d\n",**k);

}