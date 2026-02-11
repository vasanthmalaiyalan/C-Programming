#include<stdio.h>
int main(void)
{
    char name[]="vasanth";
    puts(name);//array decay of first element address and end read '\0'
}

//=========xchar name[] = "Vasanth";puts(name); இப்படி இருக்கும்போது array decay ஆகி v உடைய அட்ரஸ் puts போகும் அல்லவா?x=============x============x=========

/*
ஆம் 👍 உங்கள் observation correct — array decay concept இங்க apply ஆகுது.
இதை precise-ஆ explain பண்ணுறேன்.

📌 Code
char name[] = "Vasanth";
puts(name);

🔑 Step 1 — name என்ன?
char name[] = "Vasanth";


Memory layout:

| V | a | s | a | n | t | h | \0 |


👉 இது char array
👉 Size = 8 bytes (7 letters + null terminator)

🔑 Step 2 — Array Decay என்ன நடக்குது?

Function call-ல:

puts(name);


👉 name (array)
→ automatically decay ஆகி
→ char * (pointer to first element) ஆகும்

அதாவது:

name  →  &name[0]


👉 Address of 'V' தான் function-க்கு போகுது ✔

🔑 Step 3 — puts() prototype
int puts(const char *s);


👉 Argument type: const char *

அதாவது:

Pointer to first character

\0 வரைக்கும் read பண்ணும்

🔑 Step 4 — puts() என்ன செய்கிறது?

Inside:

s → points to 'V'

Characters read one by one

\0 வரைக்கும் print

Automatically newline add

🧠 Visual Flow
name (array)
   ↓
decays to
   ↓
pointer → 'V'
           'a'
           's'
           'a'
           'n'
           't'
           'h'
           '\0'

🔴 Important Clarification

Array decay நடக்காத situation:

sizeof(name);   // 8 (array size)


Function argument-ஆ போகும்போது மட்டும் decay.

🏁 Final Answer

ஆம் ✔
puts(name); call செய்யும்போது
array decay ஆகி
முதல் character 'V'-ன் address
puts()-க்கு pass ஆகும்.
puts() அந்த address-ல இருந்து
\0 வரைக்கும் characters print பண்ணும்.
*/