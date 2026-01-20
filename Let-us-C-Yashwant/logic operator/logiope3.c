#include<stdio.h>
int main()
{
    int i=-3,j=3;
    if(!i+!j*1){ //non-zero values are always consider true ok so if(0+0*1 = 0)else block executed
       printf("\nhey iam C");
    }
    else{
        printf("\nError !");
    }
}