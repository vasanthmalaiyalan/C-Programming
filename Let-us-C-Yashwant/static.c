
#include<stdio.h>

int main()
{
    increment();
    increment();
    increment();
}
increment()
{
    static int i=1;
    printf("%d\n",i);
    i=i+1;
}

/*
static variable என்றால் என்ன?
static int i = 1;


இதன் behavior:

Memory ஒரே முறை தான் உருவாகும்

Program முழுக்க அந்த variable வாழும்

Function முடிந்தாலும் value அழியாது

Next call-ல previous value தொடரும்

அதனால்:

First call:

i = 1 → print 1 → i becomes 2


Second call:

i = 2 → print 2 → i becomes 3


Third call:

i = 3 → print 3


Output:

1
2
3

*/