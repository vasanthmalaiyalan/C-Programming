#include<stdio.h>
int main()
{
    char name[25];
    printf("Enter you full name: ");
    fgets(name,sizeof(name),stdin);//if you use fgets mantoatory use this fgets(name = 25 bytes,sizeof(name) = 25,stdin → keyboard input
    puts("Hello!");
    puts(name);
}