#include<stdio.h>
struct emp
{
    int a;//starting address 0x7fffd6cba29c
    char ch;//after 4 byte starting address 0x7ffe46900db0
    char com;//after 1 byte stating address 0x7ffe46900db1
    float s;//after 1 byte with compailer alignment 2 byte padding starting address is 0x7ffe46900db4
};
int main()
{
struct emp e;
printf("%p\n %p\n %p\n %p\n",(void*)&e.a,(void*)&e.ch,(void*)&e.com,(void*)&e.s);
}

/*
0x...29c = start address

int a occupies:

0x...29c
0x...29d
0x...29e
0x...29f


Next free address = 0x...2a0

🧠 Now your explanation rewritten perfectly

int a 4 bytes occupy செய்த பிறகு next free address 0x...2a0-ல்
char ch வைக்கப்படுகிறது,
அதற்குப் பிறகு char com 0x...2a1-ல் வைக்கப்படுகிறது.

அடுத்த member float s 4-byte alignment வேண்டும் என்பதால்
compiler இரண்டு padding bytes (0x...2a2, 0x...2a3) சேர்த்து,
float s-ஐ aligned address 0x...2a4-ல் தொடங்குகிறது.

✔️ 100% correct

📐 Address flow (clean view)
0x...29c  int a (byte 0)
0x...29d  int a (byte 1)
0x...29e  int a (byte 2)
0x...29f  int a (byte 3)

0x...2a0  char ch
0x...2a1  char com

0x...2a2  padding
0x...2a3  padding

0x...2a4  float s (byte 0)
0x...2a5  float s (byte 1)
0x...2a6  float s (byte 2)
0x...2a7  float s (byte 3)

🔑 Golden sentence (exam-perfect)

Compiler alignment தேவைக்காக structure உறுப்பினர்களுக்கு இடையில் padding bytes சேர்க்கலாம்; அதனால் உறுப்பினர்களின் address-கள் தொடர்ச்சியாக இருக்காமல் இருக்கலாம்.
*/
