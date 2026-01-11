#include<stdio.h>
int main()
{
    int x,y;
    char choice;
    printf("+ => addition\n-=> subtraction\n");
    printf("Enter your choice(+ or -): ");
    scanf("%c",&choice);
    printf("Enter values for x & y: ");
    scanf("%d %d",&x,&y);
    switch(choice)
    {
        case '+':
             printf("Add x & y = %d\n",x+y);
             break;
        case '-':
             printf("Diff x & y = %d\n",x-y);
             break;
        default:
              printf("Error: choice can be x or y\n");
              break;     
    }
}