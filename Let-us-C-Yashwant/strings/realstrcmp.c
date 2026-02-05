#include<stdio.h>
#include<string.h>

//#define FOUND 1
//#define NOTFOUND 0 // thos are manual one this is not best practice
enum {NOTFOUND,FOUND}; //#define is a preprocessor text substitution; enum is a compiler-known typed constant with automatic numbering. and Custom value possible like=> enum status { NOTFOUND = 10, FOUND = 20 };

int main()
{
    char masterlist[6][15]={
                              "akshay",
                              "vasanth raj",
                              "srinivas",
                              "vasanth",
                              "rajesh",
                              "gopal"
    };
    int i,flag,a;
    char yourname[10];
    printf("Enter your name: ");
    scanf("%s",yourname);

    flag=NOTFOUND;
    for(i=0;i<=5;i++)
    {
        a=strcmp(&masterlist[i][0],yourname);//both are same strcmp(masterlist[i], yourname);
        if(a==0)
        {
            printf("Welcome, you can enter the palace\n");
            flag = FOUND;
            break;
        }
    }
    if(flag==NOTFOUND)
       printf("Sorry,you are a not allowed\n");
}


///===========x==============x==============x==============x===

/*
இது C language-ல “symbol vs type” difference புரிஞ்சுக்க உதவும்.
Simple + deep Tamil-ல explain பண்றேன்.

Short answer (முதலில்)
விஷயம்	#define	enum
Compiler பார்க்குமா?	❌ இல்லை (preprocessor)	✅ ஆம்
Type safety	❌ இல்லை	✅ கொஞ்சம்
Debugging	❌ கஷ்டம்	✅ easy
0 / 1 auto?	❌ நீ தான் கொடுக்கணும்	✅ auto assign
Best practice	❌ avoid	✅ prefer
1️⃣ #define எப்படி வேலை செய்கிறது?
#define NOTFOUND 0
#define FOUND 1


👉 இது text replacement மட்டுமே

Compiler-க்கு போகுமுன்னாடி:

flag = NOTFOUND;


⬇ preprocessor replace பண்ணும்

flag = 0;


👉 Compiler-க்கு NOTFOUND என்றே தெரியாது ❌

⚠️ Problem with #define
#define FOUND "yes"


👉 Compiler error இல்ல ❌
👉 Runtime-ல தான் பிரச்சினை வரும்

Type check கிடையாது.

2️⃣ enum எப்படி வேலை செய்கிறது?
enum status { NOTFOUND, FOUND };


Compiler internally assign பண்ணும்:

NOTFOUND = 0
FOUND    = 1


👉 Compiler-க்கு full knowledge இருக்கு
👉 Debugger-ல கூட name தெரியும்

You can also do:
enum status { NOTFOUND = 10, FOUND = 20 };


👉 Custom values possible

3️⃣ “Compiler 0 / 1 எடுத்துக்கொள்ளுமா?” — exact answer
#define

❌ Compiler எதையும் assign செய்யாது
👉 நீ define பண்ணினதை மட்டுமே எடுத்துக்கொள்ளும்

#define FOUND 999


Compiler uses 999

enum

✅ Compiler automatically assign பண்ணும்

enum { NOTFOUND, FOUND };


👉 Internally:

NOTFOUND = 0
FOUND = 1

4️⃣ Memory / Assembly view (conceptual)
enum { NOTFOUND, FOUND };
int flag = FOUND;


Memory-ல:

flag = 1


👉 enum name compile-time-ல number-ஆ மாறிடும்

5️⃣ Real-world usage (which to use?)
❌ Avoid (#define)
#define TRUE 1
#define FALSE 0

✅ Prefer (enum)
enum { FALSE, TRUE };

6️⃣ Security + kernel mindset (important for you)

#define → silent bugs

enum → compiler warnings help

kernel code → enum preferred

Linux kernel full-ஆ enums use பண்ணும் 👌

One-line takeaway (interview answer)

#define is a preprocessor text substitution; enum is a compiler-known typed constant with automatic numbering.

Ultra short summary

#define → blind replacement

enum → compiler smart

enum auto → 0,1,2...

Use enum whenever possible
*/