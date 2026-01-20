#include<stdio.h>
int main()
{
    int num,i;
    printf("Enter a number: ");
    scanf("%d",&num);//if enter 7

    i=2;
    while(i<=num-1) //6 times run loop and 7th time check and end the loop last if staatement
    {
        if(num%i==0)
        {
            printf("Not a prime number\n");
            break;
        }
        i++;
    }
    if(i==num) //then if statement that 7 is apply 
       {
        printf("prime number\n");
       }
}