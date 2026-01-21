#include<stdio.h>
float square(float); //prototype
int main()
{
    float a,b;
    printf("Enter the any number: ");
    scanf("%f",&a);
    b=square(a);
    printf("\nsquare of %f is %f\n",a,b);
}
 float square(float x)
{
    //float y;
    //y=x*x;
    return x*x;
}