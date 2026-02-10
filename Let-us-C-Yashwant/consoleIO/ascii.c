#include<stdio.h>
#include<string.h>
int main()
{
    char ch='z';
    int i=125;
    float a=12.55;
    char s[]="hello there !";

    printf("%c %d %f\n",ch,ch,(double)ch);//float alway automatically act in double in printf
    printf("%s %d %f\n",s,(int)strlen(s),(double)strlen(s));
    printf("%c %d %f\n",(char)i,i,(double)i);
    printf("%f %d\n",a,(int)a); //float arguments → automatically promoted to double in printf

    return 0;
}
/*
ஆம் 👍 அப்படியே சொல்லலாம் —
நீங்க சொன்ன sentence technical-ஆ correct, C internals point of view-ல perfect.

நான் அதை ஒரு clean, exam-ready + system-level sentence-ஆ polish பண்ணித் தர்றேன்.

✅ Correct way to say it (your idea, refined)

%s ஒரு address-ஐ argument-ஆ வாங்கி,
அந்த address-ஐ char * pointer போல treat பண்ணி,
sequence-ஆ memory-யை read பண்ணி,
'\0' (null character) வரும் வரை characters-ஐ print செய்கிறது.

✔ இது 100% correct
✔ Compiler / runtime behavior-ஐ சரியாக describe பண்ணுது

🔍 Why “pointer போல”ன்னு சொல்வது சரி?

Because internally %s behaves exactly like pointer traversal:

Conceptual code:

char *p = s;   // s already decayed to char*

while (*p != '\0') {
    putchar(*p);
    p++;
}


👉 இதுதான் %s logic
👉 address arithmetic + dereference

🔴 Small but important clarification (for perfection)

❌ %s address-ல இருக்கும் value-வை print செய்கிறது
(இதைக் கேட்டா “ஒரே value”ன்னு confuse ஆகலாம்)

✅ Better wording:

%s address-ல இருந்து sequence of values read பண்ணுகிறது

🧠 Ultra-clean mental model (lock this 🔒)
Thing	Reality
s	address (char *)
%s	pointer traversal
Stop condition	'\0'
Printed unit	char (1 byte)
🏁 Final one-line answer (perfect Tamil)

ஆம், %s ஒரு address-ஐ pointer போல treat பண்ணி,
அந்த address-ல இருந்து sequence-ஆ characters-ஐ read பண்ணி,
'\0' வரைக்கும் print செய்கிறது.

🔥 இது printf internals explanation-க்கு textbook-level answer.
நீங்க இப்போ strings + pointers + printf மூன்றையும் perfectly connect பண்ணிட்டீங்க.
*/
//================x=============x=================x=======
/*
ஆம் 👍 நீங்க சொன்ன விளக்கம் அடிப்படையில் சரிதான்.
சின்ன சின்ன precision points சேர்த்தா இது 100% correct mental model ஆகும்.

🔑 Short answer (confirm)

ஆம் —

s[] array

function call-ல s → array decay → pointer (char *)

%s அந்த address-ல இருந்து start பண்ணி

'\0' (null character) வரைக்கும் characters-ஐ print பண்ணும்

👉 exactly correct ✅

🧠 இப்போ step-by-step real flow பார்க்கலாம்
Step 1️⃣: Declaration
char s[] = "hello";


Memory-ல எப்படி இருக்கும்?

Address →  Value
1000     'h'
1001     'e'
1002     'l'
1003     'l'
1004     'o'
1005     '\0'


👉 string-ன் end marker = '\0'

Step 2️⃣: printf("%s", s);
printf("%s", s);

இங்க என்ன நடக்குது?

s என்பது array name

function argument-ஆ போகும்போது:

array → decays to pointer


So actually pass ஆகுறது:

(char *) &s[0]   // first element address


👉 %s-க்கு போவது address, string இல்லை

Step 3️⃣: %s என்ன expect பண்ணுது?

%s expects → char * (pointer to char)

அதாவது:

ஒரு address

அந்த address-ல் இருந்து characters read பண்ண

Step 4️⃣: %s எப்படி print பண்ணுது?

%s logic:

given address p:
while (*p != '\0') {
    print *p;
    p++;
}


So:

1000 → 'h' → print
1001 → 'e' → print
1002 → 'l' → print
1003 → 'l' → print
1004 → 'o' → print
1005 → '\0' → STOP


Output:

hello

🔴 Important clarification (small correction)

❌ “%s first value-க்கு போய் print செய்கிறது”
✅ “%s address-ல இருந்து sequence-ஆ characters read பண்ணுகிறது”

🔍 Proof examples
Example 1: Address print
printf("%p\n", s);
printf("%p\n", &s[0]);


👉 both same address

Example 2: Dangerous case ⚠️
char s[5] = {'h','e','l','l','o'}; // ❌ no '\0'
printf("%s", s);


👉 %s stop condition கிடைக்காது
👉 garbage / crash / undefined behavior

🧠 Compare with other specifiers (clear contrast)
Specifier	What is passed	What it does
%c	int	one character print
%d	int	number print
%f	double	floating print
%s	char *	print till \0
🏁 Final one-line truth (lock this 🔒)

%s ஒரு string-ஐ print பண்ணல;
அது ஒரு address-ஐ வாங்கி
அந்த address-ல இருந்து '\0' வரைக்கும்
characters-ஐ print பண்ணுகிறது.
*/
//============x=============x================x===========x====

/*
🔑 Short answer (direct)

ஆம் — %c int தான் expect பண்ணுது.
char ch = 'z'; என்றாலும்,
printf()-க்கு argument போகும்போது அது default-ஆ int-ஆ convert (promote) ஆகி தான் போகுது.

அந்த int value = ASCII value 122.

👉 %c அந்த int (122)-ஐ character-ஆ interpret பண்ணி 'z'-ஆ print பண்ணுது.

🧠 இப்போ முழு flow-ஐ பார்க்கலாம்
Step 1️⃣: Variable declaration (memory level)
char ch = 'z';


Memory-ல ch = char

ASCII value of 'z' = 122

Size = 1 byte

Step 2️⃣: printf() call (function call time)
printf("%c", ch);


👉 printf() variadic function
👉 C rule: default argument promotion

இதனால்:

char  →  int


So function-க்கு போவது:

int value = 122


❗ %c-க்கு char போகல
👉 int தான் போகுது

Step 3️⃣: %c என்ன செய்கிறது?

%c spec says:
argument type = int
அந்த int-ன் lower byte-ஐ character-ஆ print பண்ணு

So:

int 122  → ASCII 122 → 'z'


👉 Screen-ல print ஆகுது:

z

🔍 அதே value-ஐ different specifier-கள் எப்படி interpret பண்ணுது?

Same argument:

int 122

Format	Output
%c	z
%d	122
%f	❌ (double இல்ல)
%f + cast	122.000000

Example:

printf("%c %d %f\n", ch, ch, (double)ch);


Output:

z 122 122.000000

⚠️ Important correction (very important)

❌ %c char expect பண்ணுது — ❌ தவறு
✅ %c int expect பண்ணுது — ✔️ சரி

📌 Reason:

printf()-க்கு char type never directly போகாது

அது always int-ஆ promote ஆகி தான் போகும்

🏁 Final one-line truth (lock this 🔒)

char memory-ல char தான்,
ஆனா printf()-க்கு போகும்போது
அது default-ஆ int-ஆ promote ஆகுது.
%c அந்த int-ஐ ASCII character-ஆ print பண்ணுது.

🔥 இது C language internals-ன் core concept.
நீங்க இதை புரிஞ்சுட்டீங்கன்னா, printf/scanf-ல 90% confusion முடிஞ்சது 💪
*/
//=========x===================x=====================x========

/*
🧠 First: golden rule (lock this in)

printf() format specifier = argument TYPE
இரண்டும் EXACT-ஆ match ஆகணும்.

Compiler (-Wall -Wextra -Werror)
👉 guess பண்ணாது
👉 forgive பண்ணாது 😄

🔴 Your code (relevant part)
char ch = 'z';
int i = 125;
float a = 12.55;
char s[] = "hello there !";

printf("%c %d %f\n", ch, ch, ch);
printf("%s %d %f\n", s, s, s);
printf("%c %d %f\n", i, i, i);
printf("%f %d\n", a, a);

❌ Error 1
printf("%c %d %f\n", ch, ch, ch);

What you told printf:
Specifier	Expected
%c	char
%d	int
%f	double ❗
What you passed:
ch, ch, ch   // all are char

🚨 Problem

%f ALWAYS expects double

but you gave char

👉 compiler error:

%f expects double, but argument has type int

✅ Fix (intent-based)

If you want:

char

its ASCII value

same ASCII as float

printf("%c %d %f\n", ch, ch, (double)ch);

❌ Error 2
printf("%s %d %f\n", s, s, s);

What you told:
Specifier	Expected
%s	char *
%d	int
%f	double
What you passed:
s, s, s   // s is char*

🚨 Problems

%d ← got char *

%f ← got char *

👉 Disastrous mismatch

✅ Fix (meaningful version)

If you want:

string

string length

length as float

printf("%s %d %f\n", s, (int)strlen(s), (double)strlen(s));


(remember #include <string.h>)

❌ Error 3
printf("%c %d %f\n", i, i, i);

What you passed:
i, i, i   // all int

🚨 Problem

%c expects char

%f expects double

✅ Fix (logical)
printf("%c %d %f\n", (char)i, i, (double)i);

❌ Error 4
printf("%f %d\n", a, a);

Important C rule ⚠️

float arguments → automatically promoted to double in printf

So:

a (float) → double   ✅ for %f


But second argument:

%d expects int
but got float (promoted to double)

✅ Fix
printf("%f %d\n", a, (int)a);

✅ FULL corrected program (clean & safe)
#include <stdio.h>
#include <string.h>

int main()
{
    char ch = 'z';
    int i = 125;
    float a = 12.55;
    char s[] = "hello there !";

    printf("%c %d %f\n", ch, ch, (double)ch);
    printf("%s %d %f\n", s, (int)strlen(s), (double)strlen(s));
    printf("%c %d %f\n", (char)i, i, (double)i);
    printf("%f %d\n", a, (int)a);

    return 0;
}

🧠 FINAL CORE LESSON (VERY IMPORTANT)
1️⃣ printf() does NO type checking at runtime
2️⃣ Compiler checks ONLY using format string
3️⃣ %f → ALWAYS double
4️⃣ %s → ALWAYS char*
5️⃣ Wrong specifier = Undefined Behavior
6️⃣ -Werror saved you 💪
🏁 One-line takeaway

printf() formats VALUES,
but OUTPUT is CHARACTERS —
specifier mismatch breaks the contract.
*/