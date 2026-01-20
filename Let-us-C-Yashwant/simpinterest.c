#include<stdio.h>
// calculation of simple interest
int main()
{
    int p,n;
    float r,si;

    p = 1000;
    n = 3;
    r = 85;

    // formula for simple interest
    si=p * n * r/100;

    printf( "%f\n", si);
printf ( "%d %d %f %f\n", p, n, r, si ) ; 
printf ( "Simple interest = Rs. %f\n", si ) ; 
printf ( "Prin(P) = %d \nRate(R) = %f\n", p, r ) ; 
}
