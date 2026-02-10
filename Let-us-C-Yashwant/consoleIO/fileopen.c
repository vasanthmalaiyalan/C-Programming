#include<stdio.h>

int main()
{
    FILE *fp=fopen("ascii.c","r");//fp inside file structure address
    int ch;

    if(!fp) return 1;///just chack fp=0 like if(!0)

    while((ch=fgetc(fp)) != EOF) //fgetc() fetch character to change int value
       putchar(ch);//putchar() int value to change ASCII charcater print one by one

    fclose(fp);
    return 0;   
}

/*
🎯 Program என்ன செய்கிறது? (Big picture)

👉 data.txt என்ற file-ல உள்ள content-ஐ
character by character read பண்ணி
screen-ல print பண்ணுகிறது.

📄 Code (reference)
#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("data.txt", "r");
    int ch;

    if (!fp) return 1;

    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
    return 0;
}

1️⃣ #include <stdio.h>

👉 Input / Output functions declare பண்ணிய header

FILE

fopen

fgetc

putchar

fclose

EOF

இவை எல்லாம் stdio.h-ல தான் இருக்குது.

2️⃣ FILE *fp; — இது என்ன?
FILE *fp;


👉 FILE = C-யில் file-ஐ represent பண்ணும் special structure
👉 fp = அந்த file-க்கு handle (reference)

📌 FILE * = file-ஐ point பண்ணும் pointer

3️⃣ fopen("data.txt", "r")
FILE *fp = fopen("data.txt", "r");


👉 "data.txt" → file name
👉 "r" → read mode

fopen என்ன செய்கிறது?

OS-கிட்ட file open பண்ண சொல்லும்

success ஆனா → file handle return

failure ஆனா → NULL return

4️⃣ if (!fp) return 1;
if (!fp) return 1;


👉 fp == NULLன்னா:

file இல்லை

permission இல்லை

open பண்ண முடியல

👉 Program exit பண்ணிடும் (safe exit)

📌 இது மிக முக்கியமான check ❗

5️⃣ int ch; — ஏன் int, char இல்ல?
int ch;


👉 fgetc() return பண்ணுவது:

character (0–255)

அல்லது EOF (-1)

📌 char-ல் EOF store ஆகாது
👉 அதனால int mandatory

6️⃣ Main loop — heart of program ❤️
while ((ch = fgetc(fp)) != EOF)
    putchar(ch);

Step-by-step:
🔹 fgetc(fp)

file-லிருந்து ஒரு character read பண்ணும்

end of file வந்தா → EOF

🔹 ch = fgetc(fp)

read செய்த character-ஐ ch-ல் store

🔹 (ch != EOF)

இன்னும் file முடிவடையலையா?

🔹 putchar(ch)

அந்த character-ஐ screen-ல print

👉 Loop repeats until file ends

🔍 Example (visualize)
data.txt
Hello
World

Loop execution:
fgetc(fp)	ch	putchar
'H'	72	H
'e'	101	e
'l'	108	l
...	...	...
'\n'	10	new line
EOF	-1	stop
7️⃣ fclose(fp);
fclose(fp);


👉 File close பண்ணும்
👉 OS resources free
👉 Good practice (mandatory)

8️⃣ return 0;

👉 Program success-ஆ finish ஆனது

🧠 Complete mental model (lock this 🔒)
File → fgetc() → int ch → putchar() → Screen

🔑 Important takeaways

1️⃣ FILE * = file handle
2️⃣ fopen() = file open
3️⃣ fs 4️⃣ fgetc()= one char at a time 5️⃣putchar()= print one char 6️⃣EOF= end of file marker 7️⃣ Always useintforfgetc`

🏁 One-line summary

இந்த program ஒரு file-ஐ open பண்ணி,
character by character read பண்ணி,
அதே characters-ஐ screen-ல print செய்கிறது.
*/