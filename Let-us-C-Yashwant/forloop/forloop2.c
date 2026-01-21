#include<stdio.h>
int main()
{
    int i,j;
     //increasing part
     for(i=1;i<=7;i++)
     {
        for(j=1;j<=i;j++)
           printf(" %c",'A'+j-1); //this is AscII means A value is 65 so you print A value %d then you print character of A %c
         printf("\n");  
     }

     //Decreasing part
     for(i=6;i>=1;i--)
     {
        for(j=1;j<=i;j++)
          printf(" %c",'A'+j-1);
        printf("\n");
}
}