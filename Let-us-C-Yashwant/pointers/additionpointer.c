#include<stdio.h>
int main()
{
    int i=4,*j,*k;
    j=&i;

    printf("j (&i) = %p\n",j);
    j=j+1;
    printf("j (j=j+1) = %p\n",j);
    j=j+9;
    printf("j (j=j+9) = %p\n",j);
    k=j+3;
    printf("k (k=j+3) = %p\n)",k);
}

