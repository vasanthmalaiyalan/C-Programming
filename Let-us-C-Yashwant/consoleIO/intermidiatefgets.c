#include<stdio.h>
#include<string.h>
int main()
{
    char name[20];

    printf("Enter name: ");
    fgets(name,sizeof(name),stdin);//fgets deafult newline '\n' added if you need to remove use 'strcspn'
    name[strcspn(name,"\n")]='\0';//search first new line character replace this one'\0'
    printf("Clean input: %s",name);
    return 0;

}

//=======xஅதாவது நாம் வேல்யூ என்டர் செய்யும் போது`fgets(name, sizeof(name), stdin);`sizeof(name) பயன்படுத்தும் போது நாம் எவ்வளவு டைப் செய்கிறோமோ அதற்கான இடத்தை இது ஒதுக்கி விடுமா புரோகிராம் running-ங்கில் இது `sizeof(name),`ஒதுக்கி விடுமா மேலும் stdin என்பது keyboard -டில் இருந்து இன்புட் வாங்கு என்று அர்த்தம் அதுதானே? x==========x==============x===========

/*
ரொம்ப நல்ல கேள்வி 👍
இங்க இரண்டு முக்கியமான misunderstandings இருக்கு — அதை clear பண்ணுறேன்.

🔑 First: sizeof(name) என்ன செய்கிறது?
Code:
char name[20];
fgets(name, sizeof(name), stdin);

❌ Important Correction

sizeof(name) runtime-ல் memory allocate பண்ணாது ❌

Memory already allocate ஆகி இருக்கும்:

char name[20];


👉 Program compile ஆகும்போது
👉 name-க்கு 20 bytes fixed-ஆ reserve ஆகும்

✅ sizeof(name) என்ன செய்கிறது?
sizeof(name)


👉 Compile-time-ல்
👉 அந்த array-ன் total size (20) return பண்ணும்

👉 fgets()-க்கு சொல்லுது:

“Maximum 20 bytes-க்கு மேல் read பண்ணாதே”

🔍 So what really happens?

Suppose user types:

Vasanth\n


Length = 8 bytes

fgets():

Maximum read = 19 characters + \0

Why 19?
Because last byte null terminator-க்கு

If user types 100 characters:

👉 Only first 19 characters store ஆகும்
👉 Rest input buffer-ல் இருக்கும்

🔑 So allocation எப்போது நடக்குது?
char name[20];


👉 இதே line-ல் memory allocate ஆகுது
👉 fgets() allocation செய்யாது
👉 Just existing memory-ல் store பண்ணும்

🔑 stdin என்ன?

Yes ✔ Correct

stdin = standard input stream

Default:

stdin → keyboard
stdout → screen
stderr → error output

🧠 Mental Model (very important)
char name[20];     → memory reserved (20 bytes)

fgets(name, 20, stdin);

→ keyboard-ல இருந்து read
→ max 19 chars + '\0'
→ name array-ல் store

🧪 Example
char name[5];
fgets(name, sizeof(name), stdin);


User types:

HELLO


Stored in memory:

H E L L \0


👉 O leftover buffer-ல் இருக்கும்

🔴 Very Important Rule

fgets() never reallocates memory
It never increases array size
It just respects the limit you give

🏁 Final Clear Answers

❌ sizeof(name) runtime-ல் memory allocate பண்ணாது.
✅ Memory already char name[20]-ல் allocate ஆகி இருக்கும்.
✅ sizeof(name) max read limit மட்டும் define பண்ணும்.
✅ stdin default-ஆ keyboard input stream.
*/

//===========xstrcspn ஒரு வேலையை நீக்குவதற்கு இதை பயன்படுத்துகிறோமாx============x==============x======

/*
நல்ல கேள்வி 👍
strcspn() “நீக்க” பயன்படுத்தப்படாது ❌
அது எந்த இடத்தில் நிறுத்தணும் என்பதை கண்டுபிடிக்க பயன்படுத்தப்படுகிறது.

நான் clean-ஆ explain பண்றேன்.

🔑 strcspn() என்ன?

Prototype:

size_t strcspn(const char *s1, const char *s2);


👉 Meaning:

s1-ல் இருந்து
s2-ல் உள்ள எந்த character first time match ஆகுது
அதற்கு முன் இருக்கும் length-ஐ return பண்ணும்.

🧠 Simple explanation
strcspn(string, "xyz")


👉 string-ல் 'x' அல்லது 'y' அல்லது 'z' first எங்கே வருகிறது?
👉 அந்த இடத்துக்கு முன் எத்தனை characters இருக்கிறது?

🧪 Example 1
char s[] = "hello world";
size_t n = strcspn(s, " ");


👉 space " " first index = 5
👉 so n = 5

🔑 Why we use it with fgets()?

fgets() newline store பண்ணும்:

User types:

Vasanth⏎


Memory:

V a s a n t h \n \0

Newline remove செய்ய:
name[strcspn(name, "\n")] = '\0';


Step-by-step:

strcspn(name, "\n")
→ newline first வரும் இடம் கண்டுபிடிக்கும்

அந்த index-ல்

'\n' → '\0'


👉 effectively newline remove ஆகும்

🔴 Important Point

strcspn() remove செய்யாது ❗
அது index மட்டும் return பண்ணும்.

Remove செய்வது:

name[index] = '\0';

🧠 Visual

Before:

V a s a n t h \n \0


After:

V a s a n t h \0

🏁 Final Answer

❌ strcspn() delete function இல்லை
✅ அது “எங்கே stop செய்யணும்” என்பதை கண்டுபிடிக்கும்
✅ நாம் அந்த இடத்தில் '\0' வைத்து effectively remove பண்ணுகிறோம்
*/

//===========xname[strcspn(name, "\n")] = '\0'; இதற்கு அர்த்தம் /n newline வரும்வரை return செய் என்று அர்த்தமா? வந்தவுடன் நின்று விடும் பிறகு எப்படி \0 add ஆகிறதுx===========x==================x=====

/*
அருமையான கேள்வி 👍
இது புரிந்தா string handling 100% clear ஆகிடும்.

🔑 First — இந்த line முழு meaning
name[strcspn(name, "\n")] = '\0';


இதன் அர்த்தம்:

name-ல் newline (\n) first வரும் index-ஐ கண்டுபிடி
அந்த index-ல இருக்கும் character-ஐ '\0'-ஆ மாற்று.

🧠 Step-by-step Example

Suppose user types:

Vasanth⏎


fgets() store பண்ணும் memory:

Index: 0 1 2 3 4 5 6 7 8
Value: V a s a n t h \n \0

🔹 Step 1 — strcspn(name, "\n")

Meaning:

“name-ல் newline first எங்கே வருகிறது?”

Return value = 7
(ஏனெனில் index 7-ல் \n இருக்கிறது)

🔹 Step 2 — Replace
name[7] = '\0';


Before:

V a s a n t h \n \0


After:

V a s a n t h \0


👉 newline overwrite ஆகுது
👉 extra \0 add ஆகவில்லை
👉 existing \n replace ஆகுது

🔴 Important Clarification

“\n வரும்வரை return செய்”
❌ இல்லை

Correct meaning:

“\n first match ஆகும் இடத்தின் index-ஐ return செய்”

🔍 Why no crash if newline இல்லையா?

Suppose input small:

abc


Memory:

a b c \0


strcspn(name, "\n")
→ newline கிடைக்காது
→ full length return = 3

Then:

name[3] = '\0';


Already \0 தான்
👉 No problem

🧠 Visual Summary
strcspn(name, "\n")
↓
Returns index of '\n'
↓
We manually replace that position with '\0'
↓
Effectively newline removed

🏁 Final One-Line Truth

strcspn() newline வரும்வரை count பண்ணி
அந்த newline இருக்கும் index-ஐ return செய்கிறது.
நாம் அந்த இடத்தில் '\0' வைத்து
newline-ஐ overwrite செய்கிறோம்.
*/

//========xhey அப்படி என்றால் `V a s a n t h \n \0`already \0 ஒன்று அந்த இடத்தில் உள்ளது தானே மீண்டும் இதை நாம் \0 replace செய்தால் இரண்டு இருக்குமேx==========x==========x=============

/*
🔥 ரொம்ப sharp observation! நல்ல கேள்வி.

நீங்க சொல்றது:

V a s a n t h \n \0


ஏற்கனவே ஒரு \0 இருக்குது.
நாம் \n-ஐ \0-ஆ மாற்றினா
இரண்டு \0 ஆகிடுமே?

👉 ஆம் — இரண்டு \0 memory-ல் இருக்கும்.
👉 ஆனால் அதில் எந்த problem-மும் இல்லை.

இப்போ calm-ஆ explain பண்ணுறேன்.

🧠 Before Replace

Memory:

Index: 0 1 2 3 4 5 6 7 8
Value: V a s a n t h \n \0

🔄 After This Line
name[strcspn(name, "\n")] = '\0';


New memory:

Index: 0 1 2 3 4 5 6 7 8
Value: V a s a n t h \0 \0


ஆம் ✔
இரண்டு \0 இருக்கிறது.

🔑 But Why No Problem?

C-ல் string rule:

String ends at FIRST \0

Compiler / printf / puts:

V a s a n t h \0


அதற்குப் பிறகு உள்ள data ignore செய்யப்படும்.

🧠 Very Important Concept

String என்பது:

char array + first null terminator


After first \0:

அது string-க்கு வெளியே

irrelevant data

🧪 Proof Example
char s[] = {'H','i','\0','X','Y','Z','\0'};
puts(s);


Output:

Hi


👉 'X','Y','Z' print ஆகாது.

🔍 So What Happened?

Before:

V a s a n t h \n \0


After:

V a s a n t h \0 \0


Second \0 just unused byte.

🏁 Final Answer

ஆம், இரண்டு \0 இருக்கும்.
ஆனால் C string first \0-ல் முடிந்துவிடும்.
அதற்குப் பிறகு உள்ள data ignore செய்யப்படும்.
அதனால் எந்த issue-மும் இல்லை.
*/