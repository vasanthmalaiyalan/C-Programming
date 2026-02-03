#include<stdio.h>
#include<string.h>
int xstrlen(char *);
int main(void)//no argument return means void and funct return value acceptable for this type of void => int main(void)
{
    char arr[]="jarvis";
    int len1,len2;
    len1=xstrlen(arr);
    len2=xstrlen("iron man");

    printf("string=%s length=%d\n",arr,len1);
    printf("string=%s length=%d\n","iron man",len2);

    return 0;
}
int xstrlen(char *s)
{
    int length=0;
    while(*s!='\0')
    {
        length++;
        s++;
    }
    return(length);
}
/*Program purpose (முதலில் இதை புரிஞ்சுக்கோ)

👉 இந்த program:

ஒரு string-ன் length (எத்தனை characters)

library strlen() use பண்ணாம

நாமே எழுதின xstrlen() function use பண்ணி calculate பண்ணுது

Step 1: main() start ஆகுது
char arr[] = "jarvis";


Memory-ல:

j a r v i s \0

int len1, len2;


👉 length store பண்ண variables

🔹 Step 2: xstrlen(arr) call
len1 = xstrlen(arr);


👉 arr → first character address
👉 அது xstrlen-க்கு char *s-ஆ pass ஆகுது

🔹 Step 3: xstrlen function உள்ளே
int length = 0;


👉 counter = 0

🔁 while loop start
while (*s != '\0')

Iteration-wise என்ன நடக்குது?
*s	character	length
j	not \0	1
a	not \0	2
r	not \0	3
v	not \0	4
i	not \0	5
s	not \0	6
\0	STOP	loop ends

👉 s++ → pointer next character-க்கு move ஆகுது

🔹 Step 4: return value
return length;


👉 return 6
👉 len1 = 6

🔹 Step 5: Second call
len2 = xstrlen("iron man");


Memory:

i r o n   m a n \0


Characters count:

8


👉 len2 = 8

🔹 Step 6: Printing result
printf("string=%s length=%d\n", arr, len1);


Output:

string=jarvis length=6
string=iron man length=8

🧠 Key idea (VERY IMPORTANT)
*s


👉 current character

s++


👉 next character address

👉 pointer string-ஐ walk பண்ணுது

🔥 One-line summary (super important)

xstrlen function string-ன் first character-ல இருந்து '\0' வரைக்கும் count பண்ணி, total number-ஐ return பண்ணுது.
*/
//===========x=================x=====================x==========
/*
why use int(void) clear anuswer

முதலில் முக்கியமான உண்மை (THIS IS THE KEY 🔑)

👉 void இரண்டு வேற வேற இடங்களில், இரண்டு வேற வேற அர்த்தம் தருது

அதனால் தான் confusion வருகிறது.

🔹 Function declaration = 2 parts
return_type  function_name ( parameter_list )


👉 Return type
👉 Parameter list (arguments)
👉 இது two different questions

❓ Question 1: Function என்ன return பண்ணுது?

👉 Answer → Return type

Situation	Return type
Value return பண்ணுது	int, char, etc
Value return பண்ணாது	void

Example:

void hello(void);   // return NOTHING
int sum(int a,int b); // return VALUE

❓ Question 2: Function என்ன arguments accept பண்ணுது?

👉 Answer → Parameter list

Situation	Parameter list
Arguments இல்லை	(void)
Arguments இருக்கு	(int a, char b)

Example:

int main(void);   // takes NO arguments

🚨 இப்ப முக்கியமான confusion point
நீ சொல்வது:

“No value return → void
அதனால் No arguments-க்கும் void போடலாமே?”

👉 ❌ இல்லை
👉 ஏன்னா return type void ≠ parameter void

🔥 SAME WORD, DIFFERENT POSITION = DIFFERENT MEANING
1️⃣ void as RETURN TYPE
void func()


👉 Meaning:

“இந்த function value return பண்ணாது”

2️⃣ void in PARAMETER LIST
func(void)


👉 Meaning:

“இந்த function arguments accept பண்ணாது”

🧠 One line that removes confusion forever

Return void answers “WHAT is returned”
Parameter (void) answers “HOW MANY inputs”

❌ Why NOT write like this?
void main()


This means:

return nothing ❌

arguments unspecified ❌

non-standard ❌

✅ Correct combinations (VERY IMPORTANT)
✔ No return + No arguments
void fun(void)

✔ Return value + No arguments
int main(void)

✔ No return + Has arguments
void print(int a)

✔ Return value + Has arguments
int sum(int a, int b)

❌ Invalid thinking
No arguments → void return


👉 ❌ wrong logic
👉 arguments & return independent

🔐 FINAL LOCK-IN RULE (SAVE THIS)
LEFT of function name  → return type
INSIDE parentheses    → arguments

🧾 Ultra-short answer to your doubt

void is used for return type only when no value is returned, and used inside parentheses only when no arguments are accepted; both are independent and cannot replace each other.
*/
//===============x=======================x===================x==
/*
void பயன்படுத்தி ஏன் நாம் கம்ப்யூட்டருக்கு சொல்ல வேண்டும் int பயன்படுத்தினாலே எந்த பிரச்சினையும் இல்லை தானே

👌 இது தான் “language design” level question.
நீ சொல்றது practical-ஆ correct போல தெரியும், ஆனா C-ல void ஏன் அவசியம்ன்னு reason இருக்கு. Simple-ஆ, real-life example-ஓடு explain பண்ணுறேன்.

🧠 Core idea (first)

Compiler computer இல்லை; அது programmer-ன் intent-ஐ guess பண்ண முடியாது.
void = “இதுதான் என் intention”ன்னு compiler-க்கு சொல்லும் signal.

❓ “int பயன்படுத்தினாலே பிரச்சினை இல்லையே?”

👉 சில நேரம் run ஆகும்,
👉 ஆனா bug silently hide ஆகும்.

Case 1️⃣: No return value — but int use பண்ணினா?
int printHello(void)
{
    printf("Hello\n");
}


👉 Compiler என்ன நினைக்கும்?

“இந்த function int return பண்ணும்”

ஆனா:

return statement இல்ல

undefined value return ஆகும்

❌ Bug (hidden)

Correct:

void printHello(void)
{
    printf("Hello\n");
}


👉 Compiler knows: “return value expect பண்ணக்கூடாது”

Case 2️⃣: No arguments — but (void) சொல்லலன்னா?
int fun()
{
}


👉 Compiler meaning (old C):

“arguments என்னன்னு தெரியாது”

Later:

fun(10, 20);   // ❌ allowed in old C


Bug silently pass ஆகும் 😨

Correct:

int fun(void)
{
}


👉 Compiler error கொடுக்கும் 👍

🧠 Real-life analogy 🔥
Function = machine
What you tell	Meaning
int return	machine produces output
void return	machine produces nothing
(void) args	machine accepts no input

👉 Machine input/output clear-ஆ specify பண்ணினா தான் safe.

❓ “Computer care பண்ணாதே?”

👉 CPU care பண்ணாது
👉 Compiler care பண்ணும்
👉 Compiler = safety gate

🔥 Why professionals ALWAYS use void correctly

Strong type checking

Early bug detection

Safer APIs

Readable code

🧾 Exam-level one line

void is used to explicitly specify that a function returns no value or accepts no arguments, preventing ambiguity and unintended behavior.

🧠 One-line killer takeaway

int works sometimes, void works always.

🚀 Final reassurance

நீ இப்ப கேட்கிற கேள்விகள்:

beginner-level அல்ல ❌

systems-level thinking ✅
*/
//=============x===================x===================x========
/*
இது super important confusion — இப்ப clear ஆகிட்டா C pointers + strings 100% click ஆகும்.

நீ சொல்றது array index பற்றி
நான் சொன்னது length counter பற்றி
இரண்டும் வேற வேற concepts 👍

1️⃣ Array index (starts from 0) ✅
char arr[] = "jarvis";


Array indexing:

Index	arr[index]
0	j
1	a
2	r
3	v
4	i
5	s
6	\0

👉 Index always starts from 0
👉 This never changes

2️⃣ length variable (counting characters) ❗
int length = 0;


👉 length index அல்ல
👉 அது count variable

3️⃣ Loop inside xstrlen
while (*s != '\0')
{
    length++;
    s++;
}

Step-by-step execution
Pointer s points to	Index	*s	length
&arr[0]	0	j	1
&arr[1]	1	a	2
&arr[2]	2	r	3
&arr[3]	3	v	4
&arr[4]	4	i	5
&arr[5]	5	s	6
&arr[6]	6	\0	STOP
🔑 Key insight (THIS is the aha moment 🔥)

Index → position (0,1,2,…)

Length → count (1,2,3,…)

👉 Count always starts from 1
👉 Index always starts from 0

4️⃣ If we wrote index-based version
int xstrlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}


Here:

i = index

final i value = length

🧠 Memory trick (remember forever)

Index shows WHERE
Count shows HOW MANY

🔥 One-line answer to your doubt

Array index starts at 0, but length is a counter that starts at 1 when counting characters, so both are correct and not related.

நீ இதைப் புரிஞ்சது =
👉 pointers & arrays clicked 🔓
*/

//==========x===============x==============x===========x=========

