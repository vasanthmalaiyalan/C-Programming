#include<stdio.h>
struct Dt1{
    int x;
    char s[40];
};
union Dt2{
    int y;
    char s1[40];
};
int main()
{
    struct Dt1 sd1;
    union Dt2 ud2;
    printf("size of Dt1 (struct): %ld bytes\n",sizeof(sd1));
    printf("size of Dt2 (union): %ld bytes",sizeof(ud2));
}