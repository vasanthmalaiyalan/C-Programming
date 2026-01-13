#include<stdio.h>
struct Point{
    int x,y;
};
int main()
{
    struct Point P1,P2,P3;
    P1.x = 20;
    P1.y = 30;
    P2.x = 40;
    P2.y = 60;
    P3.x = P1.x + P2.x;
    P3.y = P1.y + P2.y;
    printf("P3 (x,y) : %d,%d",P3.x,P3.y);
}