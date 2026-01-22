#include<stdio.h>
int main()
{
    int a[3][3];
    int i,j;
    printf("Enter values for 3x3 matrix: ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
           scanf("%d",&a[i][j]);
    }
    printf("\n input matrix is : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          printf("%d\t",a[i][j]); //\n
        printf("\n");  
    }
}