#include<stdio.h>

int main()
{
    increment();
    increment();
    increment();
}
increment()
{
    auto int i=1;// auto is defalult one 
    printf("%d\n",i);
    i=i+1;
}

/*
auto variable என்றால் என்ன?
auto int i = 1;


உண்மையில்:
👉 C-ல் function உள்ளே declare பண்ணும் எல்லா variables-உம் default-ஆவே auto தான்.

அதாவது:

int i = 1;


இதே தான்:

auto int i = 1;

auto variable behavior:

Function call ஆகும் போதெல்லாம் புதிய memory உருவாகும்

Function முடிந்தவுடன் → variable destroy ஆகும்

அடுத்த call-க்கு மீண்டும் fresh variable

அதனால் தான்:

increment();
increment();
increment();


ஒவ்வொரு call-லும் i புதிதாக 1 ஆக உருவாகிறது.

Output:

1
1
1
*/