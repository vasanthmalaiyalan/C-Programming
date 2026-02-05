#include<stdio.h>
#include<string.h>
int main()
{
    char *names[]={
        "rajesh",
        "kamalesh",
        "jarvis",
        "vasanth",
        "kumar"
    };
    printf("Original name: %s %s\n",names[2],names[3]);//&names[2][0] both are same
    char *temp;
    temp=names[2];//this value inside j address
    names[2]=names[3];
    names[3]=temp;

    printf("New name: %s %s\n",names[2],names[3]);
}
/*
மிகச் சிறந்த core C concept கேள்வி 👌
இதைக் clear-ஆ புரிஞ்சிட்டா array / pointer confusion முழுசா முடிஞ்சுடும்.

Short + precise + example-களோட Tamil-ல explain பண்றேன்.

🔴 Rule #1 (முதலில் இதை lock பண்ணு)

C-ல array → assign பண்ண முடியாது ❌
Pointer → assign பண்ணலாம் ✅

1️⃣ Array → Array assign ❌ (NOT allowed)
char a[10];
char b[10];

a = b;   // ❌ ILLEGAL


❓ ஏன்?

a, b = memory blocks

Memory block-ஐ replace பண்ண முடியாது

C-ல array = fixed address

👉 Compiler error:

assignment to expression with array type

2️⃣ Pointer → Pointer assign ✅ (Allowed)
char *p;
char *q;

p = q;   // ✅ OK


Pointer = address variable

Address change பண்ணலாம்

3️⃣ Array → Pointer assign ✅ (ALLOWED, BUT…)
char a[10];
char *p;

p = a;   // ✅ OK


❓ இது எப்படி allowed?

👉 Array name “decay” ஆகி pointer ஆகும்

a → &a[0]

So:

p = &a[0];


⚠️ Important:

p points to array memory

But array itself unchanged

4️⃣ Pointer → Array assign ❌ (NOT allowed)
char a[10];
char *p = "hello";

a = p;   // ❌ ILLEGAL


❓ ஏன்?

a = fixed memory

p = address

Fixed memory-க்கு address assign பண்ண முடியாது

5️⃣ Your real examples mapped
Case A (worked earlier)
char *names[];


names[i] = pointer

Swap possible:

temp = names[2];
names[2] = names[3];
names[3] = temp;


✅ OK

Case B (current error)
char names[][10];


names[i] = array

Swap ❌

names[2] = names[3];  // ❌ ERROR


Must copy content, not assign.

6️⃣ Correct mental table (IMPORTANT)
Left	Right	Allowed?	Why
array	array	❌	arrays not assignable
pointer	pointer	✅	address variable
pointer	array	✅	array decays to pointer
array	pointer	❌	array is fixed memory
7️⃣ One-liner (interview gold answer)

Arrays are not assignable; pointers are assignable.
Arrays decay to pointers in expressions, but they are not pointers.

8️⃣ Ultra-simple analogy 🧠

Array = house 🏠 (fixed place)

Pointer = address written on paper 📝

👉 You can change paper content
👉 You can’t replace a house by writing a new address on it 😄

Final takeaway 🔒

❌ array = array → NO

✅ pointer = pointer → YES

✅ pointer = array → YES (decay)

❌ array = pointer → NO

நீ இப்ப C memory model core-ஐ பிடிச்சுட்ட 👊
இது exploit / kernel / systems C-க்கு base.
*/
//=============x================x===============x=================

/*
👉 temp உள்ளே இருப்பது "jarvis" string-இன் முதல் character 'j'-க்கு address தான்.

Step-by-step memory view (இது தான் main)
Before swap
names[2] ──▶ 'j' 'a' 'r' 'v' 'i' 's' '\0'
              ^
            address A

names[3] ──▶ 'v' 'a' 's' 'a' 'n' 't' 'h' '\0'
              ^
            address B

Line 1
temp = names[2];


👉 names[2] என்ன?

type: char *

value: address of 'j'

So:

temp ──▶ address A


✅ Yes — 'j'-க்கு address தான்

Line 2
names[2] = names[3];


Now:

names[2] ──▶ address B  ("vasanth")

Line 3
names[3] = temp;


Now:

names[3] ──▶ address A  ("jarvis")

After swap (final)
names[2] ──▶ "vasanth"
names[3] ──▶ "jarvis"


👉 Strings move ஆகல
👉 Addresses மட்டும் swap ஆனது

🔴 Very important clarification (இதுல நிறைய பேர் தவறுவாங்க)

❌ temp உள்ளே 'j' character இல்லை
❌ ASCII value இல்லை

✅ temp = pointer
✅ pointer = address

Proof snippet (நீ run பண்ணலாம்)
printf("%p\n", (void*)names[2]);
printf("%p\n", (void*)temp);


👉 Both same address print ஆகும் (before swap)

One-line takeaway (lock this 🔒)

temp stores the address of the first character of the string, not the character itself.
*/