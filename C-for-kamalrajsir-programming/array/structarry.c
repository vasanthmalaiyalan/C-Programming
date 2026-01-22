#include<stdio.h>
struct Point{int x,y};
int main()
{
    struct Point p[3];
    int i;
    for(i=0;i<2;i++){
        printf("Enter x & y values: ");
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    p[2].x = p[0].x + p[1].x;
    p[2].y = p[0].y + p[1].y;

    for(i=0;i<3;i++)
    {
        printf("P%d (x,y) is : %d,%d\n",i,p[i].x,p[i].y);
    }

   // printf("Output is P[2] is (x,y) : %d, %d",p[2].x,p[2].y);
}