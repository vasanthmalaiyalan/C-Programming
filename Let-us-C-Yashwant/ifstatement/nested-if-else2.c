#include<stdio.h>
//Method - 1
int main()
{
    int m1,m2,m3,m4,m5,per;
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    per = (m1+m2+m3+m4+m5)/5;

    if(per >= 60)
    {
        printf("First division");
    }
    else{
        if(per >= 50)
        {
            printf("Second division");
        }
        else{
            if(per >= 40)
            {
                printf("Third Division");
            }
            else{
                printf("You are Fail");
            }
        }
    }
}