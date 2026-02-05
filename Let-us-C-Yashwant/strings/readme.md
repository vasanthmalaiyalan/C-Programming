String என்றால் என்ன?

Integer values-ஐ store பண்ண int array use பண்ணுறோம்.

அதே மாதிரி characters (letters) store பண்ண char array use பண்ணுறோம்.

இந்த character array-ஐ தான் Stringன்னு சொல்றோம்.

👉 Example:

char name[] = { 'H','A','E','S','L','E','R','\0' };

🔹 '\0' (Null character) என்ன?

'\0' = Null character

ASCII value = 0

இது string முடிவை காட்டும் symbol

⚠️ Important:

'\0' ❌ '0' அல்ல

'0' ASCII = 48

'\0' ASCII = 0

🔹 ஏன் '\0' அவசியம்?

C-ல string functions (printf, strlen, strcpy)
👉 string எங்க முடிகிறதுன்னு தெரிஞ்சுக்க '\0'-ஐ தான் நம்பும்.

அதனால்:

'\0' இல்லாத char array → ❌ string கிடையாது

அது சும்மா characters collection தான்

🔹 Memory-ல string எப்படி store ஆகும்?
char name[] = "HAESLER";


Memory:

H  A  E  S  L  E  R  \0


ஒவ்வொரு character → 1 byte

எல்லாம் continuous memory-ல store ஆகும்

கடைசியில் automatic-ஆ '\0' சேர்க்கப்படும்

🔹 Shortcut way (C special feature)

இதைக் கவனிச்சிருப்பீங்க 👇

char name[] = "HAESLER";


👉 இதில் நீ '\0' எழுதவே வேண்டாம்
👉 C compiler automatic-ஆ add பண்ணும்

Equivalent to:

char name[] = { 'H','A','E','S','L','E','R','\0' };

🔹 Simple definition (exam-ready 💡)

A string is a one-dimensional array of characters terminated by a null character ('\0').

🔹 Quick recap 🔁

String = char array

Last character must be '\0'

'\0' ≠ '0'

Without '\0' → not a string

"text" → compiler adds '\0'



ஏன் string elements-ஐ direct-ஆ access பண்ண மாட்டோம்?

C-ல string characters-ஐ access பண்ண பல வழிகள் இருக்கு:

name[i]

*(name+i)

pointer tricks …

ஆனா real programs-ல இதை எல்லாம் rarely use பண்ணுவாங்க.

👉 காரணம்:
printf() & scanf() already easy way கொடுத்திருக்கு 😄

🔹 printf("%s", name) எப்படி வேலை செய்கிறது?
char name[] = "Klinsman";
printf("%s", name);

%s என்ன?

%s = string format specifier

name → array base address

printf:

first character-ல இருந்து start பண்ணும்

'\0' வரைக்கும் print பண்ணும்

❌ '\0'-ஐ print பண்ணாது

Output:

Klinsman

🔹 '\0' print ஆகாததுக்கு காரணம்?

'\0' = string end marker

அது data இல்லை, control character

அதனால் printf அதை skip பண்ணும்

🔹 scanf("%s", name) எப்படி வேலை செய்கிறது?
char name[25];
scanf("%s", name);

Step-by-step:

Keyboard-ல characters type பண்ணுறோம்

scanf:

character by character array-க்குள் store பண்ணும்

Enter key press பண்ணும்போது:

automatically '\0' add பண்ணும்

Example input:

Debashish


Memory:

D e b a s h i s h \0

🔹 ஏன் &name போடல?
scanf("%s", name);   // ✅ correct


👉 காரணம்:

Array name (name) itself = base address

அதனால் & தேவையில்லை

❌ Wrong:

scanf("%s", &name);

🔹 char name[25] என்றால் என்ன?

25 bytes memory reserve ஆகும்

Max 24 characters + 1 '\0'

⚠️ Input 25 characters-ஐ தாண்டினா → buffer overflow (danger)

🔹 Sample program explained
char name[25];
printf("Enter your name ");
scanf("%s", name);
printf("Hello %s!", name);


Input:

Debashish


Output:

Hello Debashish!

🔹 Important limitation (VERY IMPORTANT ⚠️)
scanf("%s", name);


👉 space வந்ததும் stop ஆகும்

Input:

Debashish Kumar


Stored:

Debashish

🔹 Exam-ready summary 💡

%s → string format specifier

printf("%s", name) → prints till '\0'

scanf("%s", name) → reads till space / enter

'\0' auto-added by scanf

Array name itself = base address

🔥 One-line takeaway

%s makes string handling simple by automatically working till the null character ('\0').


ஆமாம், *t = '\0'; கண்டிப்பா போடணும் ✅
(இந்த மாதிரி string copy function-ல)

இப்ப ஏன் அவசியம்ன்னு உள்ளே என்ன நடக்குதுன்னு very clear-ஆ explain பண்ணுறேன் 👇

1️⃣ String-ன் அடையாளமே '\0'

C-ல:

String என்றால் = characters + last-ல '\0'

[h][e][l][l][o][\0]   // ✅ string
[h][e][l][l][o]       // ❌ string இல்லை


👉 '\0' இல்லாதா:

%sக்கு string எங்க முடிகிறது தெரியாது

print loop எங்க நிறுத்துவது தெரியாது

2️⃣ Copy loop என்ன செய்கிறது?
while (*s != '\0')
{
    *t = *s;
    s++;
    t++;
}


👉 இந்த loop:

characters மட்டும் copy பண்ணுது

'\0' copy பண்ணவே இல்ல ❌
(ஏன்னா *s != '\0' condition)

அதனால் loop முடிந்தப்புறம்:

target : [h][e][l][l][o][ ? ][ ? ]...


👉 இப்ப target string கிடையாது

3️⃣ அதனால்தான் இந்த line தேவை 🔥
*t = '\0';


👉 இது:

string-க்கு end mark போடுது

target-ஐ proper string ஆக மாற்றுது

Result:

target : [h][e][l][l][o][\0]

4️⃣ *t = '\0'; போடலன்னா என்ன ஆகும்?
❌ Without it:
printf("%s", target);


👉 %s:

target[0] → h

target[1] → e

...

\0 கிடைக்காத வரை print பண்ணும்

garbage memory-ல போய்

crash / weird output

Example output:

hello����@��


👉 Undefined Behavior 💣

5️⃣ Small experiment (mentally)
char target[10];


Before:

[?][?][?][?][?][?][?][?][?][?]


After copy without \0:

[h][e][l][l][o][?][?][?][?][?]


%sக்கு stop sign இல்ல

🔑 Golden rule (LOCK THIS 🔥)

Every string operation MUST ensure '\0' at the end.

6️⃣ When is *t = '\0' NOT needed?

👉 Library strcpy use பண்ணும்போது
ஏன்னா அது internally இதையே பண்ணும்

But custom xstrcpy எழுதும்போது → MUST

🧾 Exam-ready one line

The statement *t = '\0'; is necessary to terminate the destination string properly; without it, the result is not a valid string.

🔥 Final confidence answer

ஆமாம், *t = '\0'; கட்டாயம்; இல்லையென்றால் target string அல்ல, garbage data collection தான்.

==============x=================x================x===============

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

Heap → கேட்டு வாங்கும் நினைவகம் (நீ free பண்ணணும்)

========x=================x================x=====================

சரியான கேள்வி 👍
Short answer: ❌ malloc மட்டும் தான் heap உருவாக்கும் என்று இல்லை.
Heap memory ஏற்கனவே OS கொடுத்திருக்கும்; malloc அதை பயன்படுத்தும் ஒரு வழி மட்டும்.

இப்போ clear-ஆ, step-by-step Tamil-ல சொல்லறேன்.

முதலில் முக்கியமான correction 🔴

❌ malloc heap-ஐ “உருவாக்காது”
✅ Heap memory ஏற்கனவே OS-ல இருக்கும்
✅ malloc அந்த heap-ல இருந்து ஒரு பகுதியை allocate பண்ணும்

Heap memory யார் உருவாக்குறாங்க?

👉 Operating System (OS)
Program start ஆகும்போதே:

Program memory:
CODE | GLOBAL | STACK | HEAP


👉 Heap already ready ✔
👉 Programmer create பண்ண வேண்டியதில்லை

Heap-ல memory பெறும் வழிகள் (C-ல்)
✅ 1️⃣ malloc()
p = malloc(100);


Heap-ல 100 bytes

Garbage values

✅ 2️⃣ calloc()
p = calloc(10, sizeof(int));


Heap-ல memory

Zero-initialized

✅ 3️⃣ realloc()
p = realloc(p, 200);


Existing heap block-ஐ resize பண்ணும்

👉 மூன்றும் heap-ல தான் memory கொடுக்கும்

❓ malloc இல்லாம heap-ஐ use பண்ண முடியுமா?
User-level C program-ல ❌

malloc / calloc / realloc இல்லாம

Heap memory safe-ஆ manage பண்ண முடியாது

Low-level (advanced)

brk(), sbrk() (old)

mmap() (modern)

👉 OS / libc internal use
👉 Normal C programmer use பண்ண கூடாது

Example (compare)
Stack (no heap)
char a[50];   // stack

Heap (with malloc)
char *p = malloc(50);

Very important rule 🔒

Heap memory = long life
Stack memory = short life

Common misunderstanding (clear it now)
Thought	Reality
malloc heap உருவாக்கும்	❌
heap OS உருவாக்கும்	✅
malloc heap-ஐ manage பண்ணும்	✅
Simple analogy 🧠

OS = land owner 🏞️

Heap = empty land

malloc = land-ல plot book பண்ணுவது

free = plot-ஐ return பண்ணுவது

One-line takeaway (lock this)

Heap OS-ல இருந்தே இருக்கும்; malloc அதை allocate மட்டும் செய்கிறது.