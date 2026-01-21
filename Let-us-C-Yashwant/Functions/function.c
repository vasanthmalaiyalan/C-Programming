#include<stdio.h>
int main()
{
    printf("\nIam in main");
    italy();
    printf("\n Iam finally back in main");
}
italy()
{
    printf("iam in italy\n");
    brazil();
    printf("iam came back italy");
}
brazil()
{
    printf("\nIam in brazil\n");
    england();
    printf("iam came back brazil");
}
england()
{
    printf("Iam in england");
}