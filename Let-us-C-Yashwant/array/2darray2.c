#include<stdio.h>
int main(){
    int s[4][2] = {
        {1234,54},
        {1213,33},
        {1434,54},
        {1312,78}
    };
    int i;
    for(i=0;i<=3;i++)
       printf("Address of %d th 1-D array = %p\n",i,s[i]); //s[i], &s[i][0] both are same 
}

/*
Expression	Meaning
s	whole 2D array
s[0]	first row → {1234, 54}
s[1]	second row → {1213, 33}
s[2]	third row
s[3]	fourth row
Memory-ல் எப்படி store ஆகிறது?

Assume: sizeof(int) = 4 bytes

s[0][0]  1234   address 1000
s[0][1]  54     address 1004

s[1][0]  1213   address 1008
s[1][1]  33     address 1012

s[2][0]  1434   address 1016
s[2][1]  54     address 1020

s[3][0]  1312   address 1024
s[3][1]  78     address 1028

அப்படியெனில் s[i] என்ன?
Expression	Actually equals
s[0]	&s[0][0]
s[1]	&s[1][0]
s[2]	&s[2][0]
s[3]	&s[3][0]

👉 s[i] gives address of first element of that row

Output-ல் நீ பார்த்தது:
0x...880
0x...888
0x...890
0x...898


Difference = 8 bytes each time.

ஏன்?

Each row = 2 integers
Each int = 4 bytes
So one row size = 2 × 4 = 8 bytes

அதனால்:

s[1] = s[0] + 8 bytes
s[2] = s[1] + 8 bytes
s[3] = s[2] + 8 bytes
*/