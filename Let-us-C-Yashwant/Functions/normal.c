#include<stdio.h>
float square(float x) //because c compailer is reding in program C is top to bottom
{
    return x*x;
}
int main()
{
    float a,b;
    printf("Ente the value any number: ");
    scanf("%f",&a);
    b=square(a);
    printf("%f is %f\n",a,b);
}