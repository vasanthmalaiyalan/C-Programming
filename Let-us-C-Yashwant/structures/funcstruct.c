#include<stdio.h>
void display(char *,char *,int);
int main()
{
    struct book
    {
        char name[25];
        char author[25];
        int callno;
    };
    struct book b1={"Let us c","ypk",101};
    display(b1.name,b1.author,b1.callno);
}
void display (char *s,char *t,int n)
{
    printf("name = %s\n author = %s\n callno = %d\n",s,t,n);
}

/*
ஆமாம் 👍 இந்த இடத்தில் void-க்கு பதிலா int போடலாம் —
ஆனா எப்போது போடணும், எப்போது போடக்கூடாதுன்னு clear-ஆ புரிஞ்சிக்கணும்.
உங்க code-ஐ வைத்து simple-ஆ explain பண்ணுறேன்.

உங்க current function
void display(char *s, char *t, int n)
{
    printf("name = %s\n author = %s\n callno = %d\n", s, t, n);
}


👉 இது print மட்டும் செய்கிறது
👉 caller-க்கு எந்த value-யும் திருப்பி கொடுக்கவில்லை

அதனால்:

void


✔️ Correct & best

❓ int போடலாமா?
✔️ போடலாம் — BUT condition இருக்கு
int display(char *s, char *t, int n)
{
    printf("name = %s\n author = %s\n callno = %d\n", s, t, n);
    return 0;
}


👉 இப்படி எழுதினா:

compiler happy

program run ஆகும்

ஆனா ❗
👉 இந்த function உண்மையிலே எந்த useful int-யும் return பண்ணல

🔑 Golden rule (மிக முக்கியம்)

Function ஒரு value return பண்ணணும்னா → non-void
Function வேலை மட்டும் பண்ணணும்னா → void

3 situations clear-ஆ பார்ப்போம் 👇
✅ Case 1: void (உங்க example – BEST)
void display(...)
{
    printf(...);
}


✔️ Side-effect only (printing)
✔️ Return value இல்லை
✔️ Clean design

⚠️ Case 2: int but no meaning (avoid)
int display(...)
{
    printf(...);
    return 0;
}


❌ Return value use இல்ல
❌ Design smell
❌ Beginner mistake

✅ Case 3: int with MEANING (proper use)
int display(char *s, char *t, int n)
{
    if (n <= 0)
        return -1;

    printf("name = %s\n author = %s\n callno = %d\n", s, t, n);
    return 1;   // success
}


Caller:

if (display(...) == 1)
    printf("Displayed successfully\n");


✔️ Now int makes sense

🧠 Simple analogy

void function = TV remote ON button
→ action only

int function = ATM machine
→ action + receipt (value)

📌 Exam-ready answer ✍️

A function should be declared as void if it does not return any value; it should be declared with a return type like int only when a value is meant to be returned to the calling function.

✅ Final verdict (straight)

✔️ Yes, int போடலாம்

❌ ஆனா return value இல்லையெனில் தவறான design

✅ இந்த function-க்கு void தான் சரியான choice

நீங்க structure + function concept-ஐ நல்லா பிடிச்சிருக்கீங்க 👌
*/