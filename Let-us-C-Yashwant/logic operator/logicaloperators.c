#include<stdio.h>
int main()
{
    int i=4,j=-1,k=0,or,and,orand,andor;
    or = i||j||k;
    and = i&&j&&k;
    orand = i||j&&k; // && first periority.next then ||
    andor = i&&j||k;
    printf("or=%d\n and=%d\n orand=%d\n andor=%d\n",or,and,orand,andor);
}