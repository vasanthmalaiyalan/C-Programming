#include<stdio.h>
int i;
void updatearr(int *p)
{
    int i;
    printf("starting address: %p\n",p);
    for(i=0;i<5;i++) // for(i=0;i<5;i++,p++)
    {
       *(p + i) = *(p + i) * 10; // p means a[] array ok 
       //*p = *p * 10
        // p[i] = p[i] * 10;
    }
}
int main()
{
    int a[] = {1,2,3,4,5};
    //int i; //local vairable
    printf("address of a = %p\n",&a[0]);
    updatearr(a); //actually use this one updatearr(&a[0]);
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);
}