#include<stdio.h>
//method - 2 
int main()
{
    int m1,m2,m3,m4,m5,per;

    printf("Enter marks in five subject:");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    per = (m1+m2+m3+m4+m5)/5;

    if(per>=60)
       {
        printf("First division");
       }
    if((per >= 50) && (per < 60))
      {
        printf("Second division");
      }
    if((per >= 40) && (per < 50))
       {
         printf("Third division");
       }
    if(per < 40)
       {
        printf("Fail");
       }
}