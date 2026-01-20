#include<stdio.h>
int main()
{
    int bonus,cy,yoj,yr_of_ser;
    printf("Ente the year of current and joining: ");
    scanf("%d %d",&cy,&yoj);

    yr_of_ser = cy - yoj;

    if(yr_of_ser > 3)
    {
        bonus = 2500;
        printf("Bonus = Rs. %d",bonus);
    }
}