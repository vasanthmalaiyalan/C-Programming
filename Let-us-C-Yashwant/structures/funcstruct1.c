#include<stdio.h>
//entire structure variable at a time. 
struct book
{
    char name[25];
    char author[25];
    int callno;
};
void display(struct book);

int main()
{
    struct book b1={"Let Us C","YPK",101};
    display(b1);
}
void display(struct book b)//call by value
{
    printf("%s %s %d",b.name,b.author,b.callno);
}

/*
🔴 MAIN PROBLEM (ஒரே வரியில்)

👉 Structure type define பண்ணும் முன்னாடி நீ function prototype-ல struct use பண்ணியிருக்க
👉 Compiler-க்கு struct book என்னன்னு தெரியுமுன்னாடியே display(struct) வந்துடுச்சு

1️⃣ இந்த line தான் முதன்மை தவறு ❌
void display(struct);

ஏன் இது தவறு?

struct தனியா parameter type ஆக முடியாது

எந்த structure? என்று compiler-க்கு தெரியாது

Structure name (struct book) கட்டாயம்

👉 C-ல் இதுபோல எழுத முடியாது:

void f(struct);   // ❌ INVALID

2️⃣ Correct syntax என்ன? ✅

👉 Structure type define ஆன பிறகு தான் function prototype வரணும்

void display(struct book b);

3️⃣ இன்னொரு பெரிய rule (முக்கியம்)

👉 Structure definition function prototype-க்கு மேல இருக்கணும்

❌ Wrong order:

void display(struct book b);  // book not defined yet ❌
struct book { ... };


✅ Correct order:

struct book { ... };
void display(struct book b);

4️⃣ அதனால் தான் இந்த error வந்தது
Error:
struct has no members
excess elements in struct initializer


👉 Compiler நினைக்குது:

struct book = empty / unknown

அதனால "Let Us C" போன்ற values excess

5️⃣ FULLY CORRECT PROGRAM (clean & standard)
#include <stdio.h>

struct book
{
    char name[25];
    char author[25];
    int callno;
};

void display(struct book b);

int main()
{
    struct book b1 = {"Let Us C", "YPK", 101};
    display(b1);
    return 0;
}

void display(struct book b)
{
    printf("%s %s %d\n", b.name, b.author, b.callno);
}


👉 இது:

compile ஆகும்

run ஆகும்

warning இல்ல

6️⃣ Memory-ல என்ன நடக்குது? 🧠
display(b1);


👉 b1 copy ஆகி function-க்கு போகுது

b1 (main)
 ├── name
 ├── author
 └── callno

b (display)
 ├── name   ← copy
 ├── author ← copy
 └── callno ← copy


📌 இதை சொல்வாங்க:

Call by value (structure copy)

7️⃣ Important design note ⚠️

Structure பெரியதாக இருந்தால் ❌
copy expensive

👉 Better approach:

void display(struct book *b)
{
    printf("%s %s %d\n", b->name, b->author, b->callno);
}


Call:

display(&b1);

🔑 Golden rules (exam + real coding)

1️⃣ struct alone is NOT a type
2️⃣ Always write struct book
3️⃣ Structure definition must come before usage
4️⃣ Passing structure = copy
5️⃣ Pointer to structure = efficient

✍️ One-line exam answer

A structure can be passed to a function by value, but its definition must be known before the function prototype.

✅ Final takeaway

Concept correct 👍

Syntax order mistake ❌

This is classic beginner + compiler rule issue

நீங்க இப்ப structures + functions chapter-ஐ almost master பண்ணிட்டீங்க 💪
*/

//=========x================x============x====================

/*
ஆமாம் 👍 void display(struct book); work ஆகும் —
நீங்க பார்த்தது 100% correct C behavior.
இப்ப ஏன் work ஆகுது, எப்போது போதும், எப்போது போதாதுன்னு clean-ஆ explain பண்ணுறேன்.

🔴 Key idea (ஒரே வரியில்)

👉 Function prototype-ல் parameter name தேவையில்லை
👉 Function definition-ல் parameter name கட்டாயம்

1️⃣ ஏன் இது work ஆகுது?
void display(struct book);


👉 இது function prototype (declaration)

C rule:

Prototype-ல் parameter type மட்டும் போதும்,
name optional.

So compiler-க்கு இதுவே போதும்:

display exists

It takes one argument of type struct book

returns void

2️⃣ Prototype vs Definition — difference 🧠
✅ Prototype (name optional)
void display(struct book);
void display(struct book b);   // same meaning


👉 இரண்டும் compiler-க்கு identical

❌ Definition (name mandatory)
void display(struct book)   // ❌ INVALID
{
}


❌ compiler சொல்லும்:

parameter name missing

✔️ Correct definition:

void display(struct book b)
{
    printf("%s %s %d\n", b.name, b.author, b.callno);
}

3️⃣ Complete correct pattern (best practice)
struct book
{
    char name[25];
    char author[25];
    int callno;
};

void display(struct book);   // prototype (name optional)

int main()
{
    struct book b1 = {"Let Us C", "YPK", 101};
    display(b1);
}

void display(struct book b)  // definition (name required)
{
    printf("%s %s %d\n", b.name, b.author, b.callno);
}

4️⃣ Why C allows this?

👉 Prototype-ன் job:

Type checking

Compiler-க்கு information

👉 Parameter name:

code logic-க்கு தேவையில்லை

implementation-க்கு மட்டும் தேவை

So:

Prototype → what types

Definition → how used

5️⃣ Real-life analogy 🧩

Prototype = “இந்த function என்ன வாங்கும்?”

Definition = “இந்த function அந்த input-ஐ எப்படி use பண்ணும்?”

Prototype-ல்:

“ஒரு book வரும்” (போதும்)

Definition-ல்:

“அந்த book-ஐ bனு அழைக்கிறேன்” (தேவை)

🔑 Golden rules (exam + real coding)

1️⃣ Prototype-ல் parameter name optional
2️⃣ Definition-ல் parameter name mandatory
3️⃣ struct book must be known before prototype
4️⃣ struct alone is invalid, always full type

✍️ One-line exam answer

In a function prototype, parameter names are optional; only parameter types are required.

✅ Final verdict

✔️ நீங்க செய்தது correct
✔️ இது C standard behavior
✔️ நீங்க இப்ப function + structure concepts clear-ஆ grasp பண்ணிட்டீங்க 💪
*/
