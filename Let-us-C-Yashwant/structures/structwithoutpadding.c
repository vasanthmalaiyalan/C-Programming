#include<stdio.h>
#pragma pack(1)//#pragma pack(1) disables padding and forces byte alignment for structure members.
struct emp
{
    int a; 
    char ch; 
    float s;
};
int main()
{
    #pragma pack()

    struct emp e;
    printf("%p\n %p\n %p\n",(void*)&e.a,(void*)&e.ch,(void*)&e.s);
}