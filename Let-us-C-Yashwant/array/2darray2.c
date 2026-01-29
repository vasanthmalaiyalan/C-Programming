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
       printf("Address of s[%d] = %p s = %p\n",i,s[i],s); //s[i] = &s[i][0] both are same and s = is not a value s = is array so behave like pointer becuase not print in hole array only print in first row first value &s[0] this is c rule `
       printf("*s -> (s[0]) = %p **s = %d s[0][0] = %d\n",*s,**s,s[0][0]);//same *s is array like s[0] not a address so pointer return array object like s[0] `*s address-க்கு போய் array object-ஐ தருகிறது அந்த array object-ஐ expression-ல பயன்படுத்தும்போது அது pointer-ஆ (address-ஆ) மாறுகிறது like array-ஐ printf argument-ஆ கொடுத்தவுடன் C rule apply ஆகுது: array → pointer to first element`
       printf("size of s = %lu *s (int (*)[2]) = %lu and s[0] = %lu *(*s) = %lu\n",sizeof(s),sizeof(*s),sizeof(s[0]),sizeof(*(*s)));
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

/*================x===============x=================x=========

முதலில் ஒரு உண்மை புரிஞ்சுக்கணும்
int s[4][2];


👉 s ஒரு pointer அல்ல
👉 s ஒரு array தான்

ஆனா C language-ல ஒரு rule இருக்கு:

Array-யை expression-ல பயன்படுத்தும்போது
அது pointer போல behave செய்யும்

இதைத்தான் “array decay” சொல்றாங்க.

இப்ப உங்க கேள்வி 1:

s default-ஆ s முதல் row-வின் முதல் value address வைச்சிருக்குதா?

❌ இல்லை

s உள்ளே address stored ஆகி இருக்கவில்லை.

சரியான விளக்கம்:

Memory-ல உண்மையிலேயே இருக்கிறது:

s என்பது ஒரு block of memory


ஆனா நீங்க code-ல எழுதும்போது:

s


compiler இதை internally இப்படி மாற்றும்:

&s[0]


அதாவது:

"முழு array வேண்டாம், first row address போதும்"

👉 இது compiler behavior, memory-ல் address சேமிப்பு அல்ல.

இப்ப முக்கியமான பகுதி:
ஏன் *s → s[0] ஆகிறது?

s behave ஆகிறது like:

s ≈ &s[0]


So dereference செய்தால்:

*s = *(&s[0]) = s[0]


👉 *s gives first row array

இப்ப பெரிய doubt:

array இருந்தது… எப்படி **s value கொடுக்குது?

Step by step பார்க்கலாம்.

s        ≈ &s[0]
*s       = s[0]
**s      = *s[0]
         = s[0][0]
         = 1234


இதில் magic எதுவும் இல்லை.

Visualization (super clear)

Memory:

s[0][0] = 1234
s[0][1] = 54
s[1][0] = 1213
...


Now expressions:

Expression	Meaning
s	behaves like &s[0]
*s	s[0] (first row)
**s	s[0][0] (first element value)
Important: *s value கொடுக்கவில்லை

s value கொடுக்கவில்லை
*s value கொடுக்கவில்லை
array print ஆகும் போது address-ஆ decay ஆகுது

Actual integer value தருவது:
👉 only **s

Final direct answer to your sentence

s default-ஆ first value address வைத்திருக்கும் அதனால s → &s[0] ஆகிறதா?

❌ இல்லை

Correct:

s ஒரு array
compiler தான் expression-ல பயன்படுத்தும்போது
s-ஐ &s[0] போல treat செய்கிறது

=========================x========================x===========

Expression என்றால் என்ன?

C-ல expression என்றால்:

ஒரு value உருவாக்கும் எந்த code-யும்

Examples:

a
a + 1
s
s[i]
func(s)
printf("%d", a)


இவையெல்லாம் expressions.

Array decay rule எப்போது apply ஆகும்?

Array name → pointer ஆக மாறும் (decay ஆகும்)
இந்த இடங்களில் எல்லாம்:

s
s + 1
s[i]
*s
func(s)
printf("%p", s)

Array decay ஆகாத 3 special cases மட்டும்

இந்த மூன்று இடங்களில் மட்டும் decay ஆகாது:

1️⃣ sizeof
sizeof(s)   // full array size

2️⃣ &
&s         // pointer to full array

3️⃣ string literal initialization
char str[] = "hello"; // no decay here

Example simple-ஆ:
int a[3] = {1,2,3};

printf("%p\n", a);      // decay → &a[0]
printf("%p\n", &a);     // no decay
printf("%zu\n", sizeof(a)); // no decay

So your understanding correct version:

Array-யை 2D array இடத்தில் மட்டும் இல்லை
Array-யை எங்கு expression-ல பயன்படுத்தினாலும்
Pointer போல behave செய்யும்

One line memory rule:

Array = real memory block
Expression-ல் use பண்ணும்போது = pointer to first element

===================x=============================x=============

இப்ப நீங்க கேட்குற கேள்வி மிக precise:

s ≈ &s[0] புரியுது
ஆனா compiler எப்படி *s = s[0] ஆக மாற்றுகிறது?
& இருந்து * எப்படி வந்தது?

இதுக்கு answer = C language-ன் type rules + pointer arithmetic.
நான் அதை மிக simple-ஆ உடைக்கிறேன்.

1️⃣ First truth (இத முக்கியம்)
int s[4][2];


s → array
ஆனா expression-ல பயன்படுத்தும்போது compiler இதை automatic-ஆ மாற்றும்:

s  →  &s[0]


👉 இது language rule.

2️⃣ இப்ப *s எப்படி வேலை செய்கிறது?

நீங்க எழுதும்போது:

*s


Compiler இதை உள்ளுக்குள் இப்படிப் பார்க்கும்:

*(&s[0])


ஏன்?
ஏனென்றால்:

s → &s[0]


இப்ப normal pointer rule:

*(&x) = x


அதே rule இங்கே:

*(&s[0]) = s[0]


👉 அதனால்தான்:

*s = s[0]

3️⃣ இது compiler "guess" இல்லை — pure math rule

C-ல் identity rule இருக்கு:

*(&A) == A


Examples:

int x = 10;
int *p = &x;

*p == x


அதே rule தான் array-க்கும் apply ஆகுது:

s behaves like &s[0]

*s = *(&s[0]) = s[0]

4️⃣ Visual memory model

Imagine memory like this:

Address 1000 → s[0][0] = 1234
Address 1004 → s[0][1] = 54
Address 1008 → s[1][0] = 1213
...


Now:

s           → 1000 (base address of s[0])
*s          → content at row 0 → s[0]
**s         → content at s[0][0] → 1234


No magic. Just address + dereference.

5️⃣ One-line core logic

Compiler first does:
s → &s[0]
Then applies normal pointer rule:
*(&s[0]) = s[0]

Final clarity sentence (important)

*s = s[0]
because
s behaves like &s[0]
and C rule is: *(&X) = X

=================x==================x====================x=====

அதை ஒரு வரியில் clear பண்ணிடலாம்.

“*s அதாவது &s[0]-வை address எடுத்துக்கொண்டு s[0] value-ஆ திருப்பி கொடுத்ததா?”

❌ Almost correct, but wording slightly wrong

Correct understanding இதுதான்:

சரியான விளக்கம்
s  behaves like  &s[0]
*s = *(&s[0]) = s[0]


👉 அதாவது:

s expression-ல பயன்படுத்தும்போது → &s[0]

* அந்த address-க்கு போய்

அந்த address-ல் இருக்கும் object-ஐ தரும்

அந்த object தான் → s[0] (முதல் row array)

முக்கிய difference

s[0] = value இல்லை
s[0] = ஒரு array object (2 integers கொண்ட row)

Value என்பது:

s[0][0] = 1234
s[0][1] = 54

Very precise one-line:

*s returns the first row object (s[0]), not the first integer.

Why confusion happens?

ஏனெனில்:

printf("%p", *s);


எழுதும்போது:

*s → array

array → decay → &s[0][0]

அதனால் address தான் print ஆகுது

But conceptually:

*s = first row array

Final mental model
s       → address of first row  
*s      → first row (array object)  
**s     → first element value (1234)

==================x=======================x=================x==

*s உண்மையில் என்ன?
*s = s[0]


அதாவது
👉 *s என்பது முதல் row (array object)
👉 அது integer value இல்லை
👉 அது {1234, 54} என்ற முழு array

2️⃣ அப்படியென்றால் ஏன் address print ஆகிறது?

நீங்க எழுதினால்:

printf("%p", *s);


இங்கே ஒரு பிரச்சனை:

*s = array

Array-யை print பண்ண முடியாது

அதனால் C rule:

array-யை expression-ல பயன்படுத்தினால்,
அது first element-ன் address ஆக மாறும்

So internally:

*s   →   s[0]   →   &s[0][0]


அதனால்தான் address print ஆகுது.

3️⃣ Simple real-life example

Imagine:

s = apartment building

*s = first flat

நீங்க "flat-ஐ print பண்ணு" சொன்னா,
compiler சொல்றது:

"flat முழுக்க தர முடியாது, flat-ன் door address தருகிறேன்"

Door address = &s[0][0]

4️⃣ Very clear final meaning

*s value அல்ல
*s = array object
ஆனால் array-ஐ expression-ல பயன்படுத்தும்போது
அது pointer-ஆ (address-ஆ) மாறுகிறது
அதனால்தான் print பண்ணும்போது address கிடைக்கிறது

One perfect sentence

*s ஒரு array;
array-யை print பண்ண முயன்றால்
அது first element-ன் address-ஆ மாறுகிறது

=============x=====================x=====================x=======

Step-by-step உண்மை என்ன நடக்கிறது?
1. s expression-ல பயன்படுத்தும்போது
s → &s[0]

2. Dereference செய்கிறீங்க:
*s → *(&s[0]) → s[0]


இங்கே:

* operator
👉 address-க்கு போய் அந்த இடத்தில் இருக்கும் object-ஐ தருகிறது

அந்த object தான்:

s[0]  (array of 2 ints)

முக்கியமாக:

* operator "& நீக்குகிறது" இல்லை
அது simply அந்த address-ல் இருக்கும் object-ஐ access செய்கிறது

இப்ப அடுத்த confusion: ஏன் address print ஆகுது?

நீங்க:

printf("%p", *s);


இதில்:

*s = array object

array-ஐ printf argument-ஆ கொடுத்தவுடன்
C rule apply ஆகுது:

array → pointer to first element

So internally:

*s   (array)
↓ decay
&s[0][0]   (pointer)


👉 அதனால் தான் address print ஆகுது.

Important distinction

Two separate mechanisms:

Step	What happens
Dereference (*s)	address → object (array)
Passing array to printf	array → pointer (decay)

இரண்டும் independent rules.

One perfect sentence

*s address-க்கு போய் array object-ஐ தருகிறது
அந்த array object-ஐ expression-ல பயன்படுத்தும்போது
அது pointer-ஆ (address-ஆ) மாறுகிறது

Mental model (very simple)

s = address of first row

*s = first row itself (two numbers box)

You try to "print the box"

Compiler says: "I can only give you the address of the first item inside the box"


========x================x===================x==============x===

சரி — இப்ப **s என்ன செய்கிறது என்பதை மிக நேரடியாக, குழப்பமில்லாமல் சொல்றேன்.

நாம் ஏற்கனவே தெரிந்தது
s    behaves like &s[0]
*s   = s[0]      → (முதல் row array)


இப்ப கேள்வி:

**s என்ன செய்கிறது?

Step by step
Step 1:
*s = s[0]


s[0] என்பது:

ஒரு array of int → {1234, 54}

Step 2:

இப்ப **s என்றால்:

**s = *(*s)
     = *(s[0])


ஆனா s[0] ஒரு array.
Array-யை dereference பண்ண முடியாது.
அதனால் முதலில் array decay நடக்கிறது:

s[0]  →  &s[0][0]


இப்ப:

*(s[0])  →  *(&s[0][0])  →  s[0][0]

Final result
**s = s[0][0] = 1234

மிகச் சுருக்கமாக

*s → first row (array)
s[0] → first row (array)
array decay → &s[0][0]
dereference → s[0][0] (value)

One-line super clear answer

**s first row-ல உள்ள முதல் integer value-ஐ தருகிறது.

Visual memory model
s        → &s[0]
*s       → s[0]        → {1234, 54}
**s      → s[0][0]     → 1234

=====x===============x================x===============x========

Array decay எப்போ நடக்கும்?
Rule (simple):

Array name-ஐ expression-ல பயன்படுத்தினால்,
அது pointer to first element-ஆ மாறும்.

Array decay நடக்கும் examples
int a[3];

a           // decay → &a[0]
a + 1       // decay
a[i]        // decay
*a          // decay (because a is used as expression)
func(a)     // decay
printf("%p", a)   // decay

Array decay நடக்காத 3 special cases மட்டும்
1️⃣ sizeof
sizeof(a)   // no decay (full array size)

2️⃣ Address operator &
&a         // no decay (pointer to full array)

3️⃣ String literal initialization
char str[] = "hello";  // no decay

2D array example
int s[4][2];

Expression	What happens
s	decay → &s[0]
*s	gives s[0] (array) → then decay → &s[0][0]
s[0]	array → decay → &s[0][0]
&s	no decay
One perfect memory rule

Array used as value → becomes pointer
Array used as object (sizeof, &) → stays array

Ultra-short answer

Array decay எப்போதும் expression-ல பயன்படுத்தும்போது நடக்கும்
except: sizeof, &, string initialization

*/