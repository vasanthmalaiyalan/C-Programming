/*
if(condition1)
{

}
else if(condition2){

}else{

}
*/
#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    if(a>0)
    {
        printf("+ve");
    }
    else if(a<0)
    {
        printf("-ve");
    }
    else
    {
        printf("Given is zero");
    }
}