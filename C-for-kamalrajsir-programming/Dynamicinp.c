#include<stdio.h>
int main()
{
    int x;
    float y;
    char ch;
    printf("Enter a char :");
    scanf("%c",&ch);
    printf("\nEnter int value :");
    scanf("%d",&x);
    printf("\nEnter a float value :");
    scanf("%f",&y);
    printf("\nGiven int value = %d",x);
    printf("\nGiven float value = %f",y);
    printf("\nGiven char input = %c",ch);
}