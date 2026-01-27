#include<stdio.h>

int main()
{
    printf("int : %lu bytes\n",sizeof(int));
    printf("long : %lu bytes\n",sizeof(long));
    printf("float : %lu bytes\n",sizeof(float));
    printf("double : %lu bytes\n",sizeof(double));
    printf("sizeof(int *) = %lu\n",sizeof(int *));
    printf("sizeof(float *) = %lu\n",sizeof(float *));
    printf("sizeof(char *) = %lu\n",sizeof(char *));
}