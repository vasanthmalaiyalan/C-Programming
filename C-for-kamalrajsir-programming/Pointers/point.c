#include<stdio.h>
int main()
{
    int a=10;
    int *p=&a;
    printf("&a= %p\n",&a);
    printf("p= %p\n",p);
    printf("&p= %p\n",&p);
}

/*
முதலில் clear rule
int a = 10;
int *p = &a;


இதில்:

p → value = address of a

p type = int * (pointer to int)

*p → அந்த address-க்கு சென்று int value-ஐ access செய்

சரியான technical version இதுதான்:

*p என்றால்
“p-க்குள் இருக்கும் value-ஐ address ஆக treat செய்து,
அந்த address-ல் இருக்கும் int value-ஐ access / modify செய்”

Important distinction (இது தான் core)
Concept	Meaning
int *p	p என்பது int-ஐ point செய்யும் pointer
p	p-ன் value = address
*p	அந்த address-ல் இருக்கும் int value
*p = 20	அந்த address-ல் இருக்கும் int value மாற்றப்படும்

👉 int * என்பதன் அர்த்தம்:
“இந்த pointer எந்த type data-க்கு point செய்கிறது?”
அதாவது dereference செய்தால் (*p) → result type = int

Super clear memory model

Assume:

a  at 0x1000 → value = 10
p  at 0x2000 → value = 0x1000


p = 0x1000

*p → go to 0x1000 → get 10

*p = 99 → memory[0x1000] = 99 → a = 99

No extra jump
No double address
Just one address, used correctly.

Final perfect one-line definition

int *p → p stores an address of an int
*p → go to that address and access/modify the int stored there
*/