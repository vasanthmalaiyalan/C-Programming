#include<stdio.h>

int main()
{
static int a[]={0,1,2,3,4};

int *p[]={a,a+1,a+2,a+3,a+4};//a,a+1 all are address compailer expect treat as pointer expect data type int *
int c[]={1,2,3,4,5};
printf("a = %p\n p = %p\n *p = %p\n *(*p) = %d\n",a,p,*p,*(*p));
printf("c[] = %p\n",c);
}



/*
உங்க கேள்வியின் மையம்

நீங்க சொல்வது:

int p[] = { a, a+1, a+2, ... };


compiler எதிர்பார்ப்பது

int p[] = { 1, 3, 4, 5, ... };


int values தானே?

அப்போ a, a+1 ஏன் “pointer value”ன்னு சொல்றீங்க?

👉 இதுதான் exact doubt.

இதை புரிஞ்சுக்க ஒரே rule போதும்
🔑 C rule (இத தான் எல்லாம்)

Expression-ன் type தான் முக்கியம்,
அது ultimately எந்த number-ஆ print ஆகுதுன்னு இல்லை.

இப்ப a என்ன?
int a[] = {0,1,2,3,4};

a-வை expression-ல பயன்படுத்தினால்:
a  →  &a[0]


type = int *

meaning = address

value = (example) 0x7ffd85d8a010

👉 இது integer value 0 இல்லை
👉 இது memory address

இப்ப a+1 என்ன?
a+1 → &a[1]


type = int *

value = (example) 0x7ffd85d8a014

👉 இதுவும் address

இப்ப முக்கியமான point 👇
Compiler எப்படி பார்க்கிறது?
int p[];


Compiler expectation:

“p array-ல உள்ள ஒவ்வொரு element-மும்
int type value ஆக இருக்கணும்”

Example:

{1, 3, 4, 5}

ஆனா நீங்க கொடுக்கிறது:
{ a, a+1, a+2, ... }


இதன் types:

Expression	Type
a	int *
a+1	int *
a+2	int *

👉 அவை numbers போல print ஆகினாலும்
👉 type-wise அவை pointers தான்

ஏன் “pointer value”ன்னு சொல்லுறோம்?

ஏனெனில்:

a = memory address

a+1 = memory address

memory address = pointer value

👉 C-ல address itself ஒரு value தான்,
ஆனா அது int value இல்லை,
அது pointer value.

Very important distinction (இத gold)
int x = 5;          // integer value
int *p = &x;        // pointer value


5 → integer data

&x → address (pointer data)

இரண்டும் numbers மாதிரி தோணலாம்,
ஆனா types completely different.

அதனால்தான் compiler reject பண்ணுது
int p[] = { a, a+1 };


Reason:

“நீ int array declare பண்ணிருக்க
ஆனா int * values initialize பண்ணுற”

👉 type mismatch

Correct mental sentence (Tamil)

a, a+1 எல்லாம்
array-ன் element values இல்லை
அவை memory address values

அதனால்தான் compiler அவைகளை
pointer valuesன்னு treat பண்ணுகிறது

Final one-line answer

Compiler “pointer value”ன்னு சொல்றது
because a மற்றும் a+1
address expressions,
int values இல்லை —
even though they look like numbers.
*/