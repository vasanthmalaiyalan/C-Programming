#include<stdio.h>

int main()
{
    int arr[]={10,20,30,45,67,56,74};
    int *i,*j;

    i=&arr[1];
    j=&arr[5];

    printf("j-i= %ld\n *j-*i = %d\n value of i = %p\n value of j = %p\n arr[1] address = %p\n arr[5] address = %p\n",j-i,*j-*i,i,j,&arr[1],&arr[5]); 
}

/* this si output
j-i= 4
 *j-*i = 36
 value of i = 0x7ffea3bbe744
 value of j = 0x7ffea3bbe754
 arr[1] address = 0x7ffea3bbe744
 arr[5] address = 0x7ffea3bbe754

/*
j-i this one like 
 0x7ffea3bbe744 - 0x7ffea3bbe754 = 0x10 => 16 bytes
16/sizeof(int)
16/4 = 4
j-i = 4
*/

/*
Hexadecimal என்றால் என்ன?

Hexadecimal = Base-16 system

அதாவது:
👉 ஒரே digit-க்கு 16 symbols தேவை

Digits:

0 1 2 3 4 5 6 7 8 9 A B C D E F


இதில்:

A = 10
B = 11
C = 12
D = 13
E = 14
F = 15

3. ஏன் A, B, C, D, E, F பயன்படுத்துகிறோம்?

ஏனெனில்:

Decimal-ல் digits முடிவது:

0 → 9  (10 digits)


Hex-ல் digits தேவை:

0 → 15  (16 values தேவை)


ஆனா 0–9 மட்டும் 10 digits தான் இருக்கு.
அதற்கு மேல 6 digits இல்ல.

அதனால் programmers இப்படிப் பண்ணினாங்க:

Decimal	Hex symbol
10	A
11	B
12	C
13	D
14	E
15	F

இது just a naming convention.
"10க்கு A என்று பெயர் வைக்கலாம்" என்று மனிதர்கள் decide செய்தது.

4. இப்போ 0x prefix என்ன?
0x


இது simply:

"இந்த number hex-ல எழுதப்பட்டிருக்கு" என்று compiler-க்கு சொல்லும் mark.

Example:

10      → decimal ten
0x10    → hex ten (but value = 16 decimal)
*/