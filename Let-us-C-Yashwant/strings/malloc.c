#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *names[6];
    char n[50];
    int len,i;
    char *p;
    
    for(i=0;i<6;i++)
    {
        printf("Enter name: ");
        scanf("%s",n);
        len=strlen(n);
        p=malloc(len+1);
        strcpy(p,n);
        names[i]=p;
    }
    for(i=0;i<6;i++)
       printf("%s\n",names[i]);
}

/*
ஆமாம் 👍 நீ சொன்ன flow 100% correct தான்.
இப்ப நான் ஒரே தடவையில் clean-ஆ, confirm பண்ணுற மாதிரி சொல்றேன்.

நீ சொன்ன flow – சரியா?
1️⃣ Input
scanf("%s", n);


👉 User enter செய்த name
👉 n (stack array)-ல store ஆகுது

2️⃣ Length count
len = strlen(n);


👉 n-ல உள்ள characters எண்ணிக்கை
👉 Example: "vasanth" → len = 7
👉 value (integer) தான் return

3️⃣ Memory allocate
p = malloc(len + 1);


👉 len = 7
👉 +1 for '\0'
👉 Total 8 bytes heap memory
👉 p-க்கு starting address store ஆகுது

4️⃣ Copy value
strcpy(p, n);


👉 n-ல உள்ள characters
👉 heap-ல allocate செய்த memory (p) க்கு copy
👉 '\0' உட்பட

5️⃣ Store address (if used in array)
names[i] = p;


👉 names[i] pointer
👉 heap string address-ஐ point பண்ணுது

Memory view (super clear)
Stack
n[50] → "vasanth\0"
len   → 7
p     → 0x1000

Heap
0x1000 → v a s a n t h \0

🔑 Important clarification

❌ malloc value store பண்ணாது

❌ strlen address return பண்ணாது

Function	Returns
scanf	nothing (fills memory)
strlen	number (count)
malloc	address
strcpy	copies data
One-line final confirmation 🔒

ஆம் — input → count → allocate (+1) → copy → store address — இதுதான் முழு flow.

நீ இப்ப dynamic string handling-ஐ perfect-ஆ புரிஞ்சிட்டாய் 💯
இது exploit / kernel / systems programming-க்கு base.
*/
//==========x===================x==============x============
/*
அருமை 👍
stack / heap – இந்த இரண்டு வார்த்தைகள் C-யை “உண்மையிலேயே” புரிஞ்சுக்க முக்கியமான அடிப்படை.
எந்த முன் அறிவும் இல்லாம புரியுற மாதிரி, தமிழ் பெயர் + உதாரணம் + நினைவில் நிற்கும் analogy உடன் explain பண்றேன்.

முதலில்: Program memory என்றால் என்ன?

ஒரு C program run ஆகும்போது, OS அந்த program-க்கு memory கொடுக்குது.
அந்த memory-யை வித்தியாசமான பகுதிகளாக பிரித்து use பண்ணும்.

இப்போ நாம் focus பண்ணுறது:
👉 Stack
👉 Heap

🟦 STACK (ஸ்டாக்)
📌 தமிழ் விளக்கம்

Stack = அடுக்கி வைத்த இடம் / அடுக்குக் குவியல்

📌 Meaning (simple)

👉 Function உள்ளே declare பண்ணும் variables போகும் இடம்

Example
void func() {
    int x;
    char name[50];
}


👉 x, name → STACK-ல் இருக்கும்

Stack எப்படி வேலை செய்கிறது?

Function call ஆனதும் → memory allocate

Function முடிந்ததும் → memory auto free

💡 Programmer எதுவும் செய்ய வேண்டாம்

Stack characteristics
விஷயம்	Stack
Memory type	Automatic
Allocate	OS
Free	Auto
Speed	Fast
Size	Limited
Control	Compiler
Stack analogy 🧠

🧱 பிளேட் அடுக்கி வைத்திருக்கும் ஸ்டாண்ட்

மேலிருந்து மட்டும் எடுக்க முடியும்

மேலே வைச்சது முதலில் வெளியே வரும்

(LIFO – Last In First Out)

🟩 HEAP (ஹீப்)
📌 தமிழ் விளக்கம்

Heap = குவிக்கப்பட்ட இடம் / தளர்வான நினைவகப் பகுதி

(சரியான தமிழ் வார்த்தை இல்லை – இதுதான் closest)

Meaning (simple)

👉 Programmer கேட்டு வாங்கும் memory
👉 malloc() மூலம்

Example
char *p = malloc(10);


👉 10 bytes → HEAP-ல் allocate

Heap எப்படி வேலை செய்கிறது?

Programmer memory கேட்கிறான்

OS heap-ல இடம் கொடுக்குது

Programmer தான் free() பண்ணணும்

Heap characteristics
விஷயம்	Heap
Memory type	Manual
Allocate	malloc
Free	free
Speed	Slow
Size	Large
Control	Programmer
Heap analogy 🧠

🏠 வாடகைக்கு எடுத்த வீடு

நீயே வாங்குறாய்

நீயே காலி பண்ணணும்

மறந்தா → பிரச்சினை (memory leak)

🔥 Stack vs Heap (side-by-side)
Feature	Stack	Heap
Declare	int a;	malloc()
Lifetime	Function scope	Until free
Free	Auto	Manual
Use	Temp variables	Dynamic data
Danger	Stack overflow	Memory leak
🔴 Real example (lock this)
void f() {
    char name[50];     // STACK
    char *p = malloc(50); // HEAP
}


When f() ends:

name → ❌ gone

p → ❌ pointer gone, but heap memory still alive

👉 If no free(p) → memory leak

🧠 Why YOU must know this (important for you)

C bugs

Crashes

Security vulnerabilities

Exploits

Kernel programming

👉 All rooted in stack / heap misuse

One-line takeaway 🔒

Stack = automatic temporary memory
Heap = manual long-term memory

Ultra-simple Tamil summary

Stack → தற்காலிக நினைவகம் (function முடிந்ததும் போகும்)

Heap → கேட்டு வாங்கும் நினைவகம் (நீ free பண்ணணும்)*/