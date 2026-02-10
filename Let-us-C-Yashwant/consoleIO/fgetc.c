#include<stdio.h>
int main(void)
{
    int ch;
    printf("Continue (y/n): ");
    ch=fgetc(stdin); //read from explicityly keyboard like fgetc(stdin) and file like just add fgetc()

    if(ch=='y'||ch=='y')
        printf("you chose yes\n");
        else
        printf("You chose No\n");
    
    return 0;
}

/*
✅ உங்க சொல்லியதை correct-ஆ polish பண்ணினா

getchar()
→ keyboard (stdin)-லிருந்து input read பண்ணும்.

fgetc(stdin)
→ stdin-க்கு connect ஆன keyboard-லிருந்து input read பண்ணும்.

fgetc(file_ptr)
→ அந்த file-லிருந்து characters read பண்ணும்.

✔ இது exactly correct.

🧠 One clear picture (mental model)
Keyboard  ─┐
           ├── stdin ── getchar()
           └── stdin ── fgetc(stdin)

File.txt ─────── fgetc(fp)

🔍 Code examples (quick proof)
Keyboard input
int ch1 = getchar();
int ch2 = fgetc(stdin);


👉 இரண்டும் keyboard-லிருந்து தான் read பண்ணும்.

File input
FILE *fp = fopen("data.txt", "r");
int ch = fgetc(fp);


👉 file-லிருந்து read.

⚠️ Important note (often missed)

getchar() stdin-க்கு மட்டும்

fgetc() stdin + files + any stream

🏁 Final one-line confirmation

ஆம் — getchar() keyboard input-க்கு,
fgetc(stdin) keyboard input-க்கு,
fgetc(file) file input-க்கு.
நீங்க சொன்னது சரி.
*/
//===========x==================x==============x===========
/*
ஆம் 👍 உங்கள் கேள்விக்கு short & accurate answer:
getchar() மற்றும் fgetc(stdin) — இரண்டும் ஒரே வேலை தான் செய்கிறது.

ஆனா ஏன் இரண்டு functions இருக்கிறது, எங்கு எது பயன்படுத்தணும்ன்னு தெளிவாகப் புரிய, கீழே clean-ஆ explain பண்றேன்.

🔵 1. getchar() என்ன?
int ch = getchar();


Standard C function / macro

stdin (keyboard)-லிருந்து ஒரு character read பண்ணும்

Enter (\n) press பண்ணினாலும் அதையும் character-ஆ read பண்ணும்

Simple, readable

👉 stdin-only shortcut

🔵 2. fgetc(stdin) என்ன?
int ch = fgetc(stdin);


Standard C function

எந்த FILE stream-லிருந்தும் character read பண்ணும்

stdin கொடுத்தால் keyboard-லிருந்து read பண்ணும்

👉 General-purpose version

✅ Core truth (important)

getchar() ≡ fgetc(stdin)

Conceptually:

getchar()  →  fgetc(stdin)


Behavior same

Buffer handling same

Enter (\n) handling same

🧠 Difference only in DESIGN, not behavior
Point	getchar()	fgetc(stdin)
Stream	stdin only	any FILE*
Simplicity	very simple	more explicit
Extensibility	low	high
Standard	yes	yes
🔍 Why both exist then?

getchar() → convenience

fgetc() → flexibility

Library designers thought:

“stdin-ல மட்டும் read வேண்டும்னா shortcut கொடுப்போம்,
any stream-க்கு generic function கொடுப்போம்.”

⚠️ Important note (type)

Always use int, not char:

int ch = getchar();   // correct


Why?

EOF (-1) detect பண்ணணும்

🏁 Final one-line answer (lock this 🔒)

ஆம் — getchar() மற்றும் fgetc(stdin) ஒரே வேலை தான் செய்கிறது.
Difference behavior-ல் இல்லை, design & flexibility-ல தான்.
*/