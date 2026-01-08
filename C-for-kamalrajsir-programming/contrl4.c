#include<stdio.h>
int main()
{
    int choice,a,b;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("Enter two values a & b: ");
    scanf("%d%d",&a,&b);
    if(choice==1){
        printf("Addition of a & b = %d",a+b);
    } 
    else if(choice==2)
    {
        printf("Diffrence b/w a & b = %d",a-b);
    }
    else if(choice==3)
    {
        printf("Multiplication of a & b = %d",a*b);
    }
    else if(choice==4)
    {
        printf("Division of a & b = %d",a/b);
    }
    else
    {
        printf("Error: your input not within 1 to 4");
    }   
}