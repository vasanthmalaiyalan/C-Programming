/*Bitwise Operator:
      Bitwise & => true va erruntha mattum true mathadu ella false
      Bitwise | => just ethu ella ethu ethavathu true erruntha pothum ellam true
      Bitwise xor ^ => same but diffrent because only change in 2randu true erruntha mattum false mathathu ella same for OR(|) operator ok
a = 4 Binary value=> 100
b = 2 Binary value=> 010
Bitwise AND a&b =>   000

Bitwise OR a|b =>    110 (6)
Bitwise xor a^b =>   110 (6) */
#include<stdio.h>
int main()
{
      int a=4,b=2;
      printf("Bitwise AND a & b = %d\n",a&b);
      printf("Bitwise OR a & b = %d\n",a|b);
      printf("Bitwise xor a ^ b = %d\n",a^b);
}

