#include<stdio.h>
int size; // global variable
void func(int arr[])
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
}
int main()
{
    int a[30],i;
    printf("Enter the no.f of elements to process: ");
    scanf("%d",&size);
    printf("Enter the values: ");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    func(a);
}