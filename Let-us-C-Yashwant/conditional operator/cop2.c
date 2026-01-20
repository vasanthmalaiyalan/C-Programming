#include<stdio.h>
int main()
{
    int k, num = 30;
    k=(num>5 ? (num <= 10 ? 100:200):500); //similar to if-else statement
    printf("\nk=%d\n",k);
}