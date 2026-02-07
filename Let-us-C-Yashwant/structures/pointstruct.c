#include<stdio.h>

int main()
{
    struct book
    {
        char name[10];
        char author[10];
        int callno;
    };
    struct book b1={"Let Us C","YPK",101};
    struct book *ptr;//ptr ஒரு pointer அது struct book type object-ஐ point பண்ணும் like (*ptr)
    ptr=&b1;//holds address of b1
    printf("%s %s %d\n",b1.name,b1.author,b1.callno);//Normal structure variable
    printf("%s %s %d\n",(*ptr).name,ptr->author,ptr->callno);//Structure pointer,-> = pointer + dot shortcut like ptr->name both or same because compailer view is this (*ptr).name
}

/*
முதலில் short answer 🔴

❌ &b1 array decay ஆகாது
❌ *ptr “L”-ன் address கொடுக்காது
✔️ Array decay நடப்பது ARRAY-க்கு மட்டும்
✔️ Structure = array அல்ல

இப்ப detail-ஆ 👇

1️⃣ ptr உள்ளே என்ன இருக்கு?
struct book b1 = {"Let Us C", "YPK", 101};
struct book *ptr = &b1;


👉 இங்க:

ptr = &b1


&b1 = entire structure b1-ன் address

NOT b1.name

NOT 'L'

📌 முக்கியம்
b1 ஒரு structure object
அது array அல்ல

2️⃣ Array decay rule – EXACT RULE 🧠

Array expression use ஆகும் போது மட்டும் decay நடக்கும்
Structure-க்கு decay concept இல்லை

Type	Decay?
char a[10]	✅ yes
int x[5]	✅ yes
struct book b1	❌ NO
3️⃣ b1 vs b1.name
b1
struct book b1;


type = struct book

NOT an array

NO decay

b1.name
char name[10];


type = char[10]

IS an array

decays to char *

👉 'L' address only comes here

4️⃣ So ptr dereference எப்படி வேலை செய்கிறது?
*ptr


Step-by-step:

ptr → address of b1

*ptr → value at that address

Value type = struct book

✔️ Whole structure object

*ptr == b1   // conceptually

5️⃣ Why NOT first element 'L'?

Because:

'L' belongs to b1.name

ptr does NOT point to b1.name

ptr points to b1 as a whole

Memory view:

b1
 ├── name[0] = 'L'
 ├── name[1] = 'e'
 ├── ...
 ├── author
 └── callno

ptr ───► b1   (start of structure)


👉 ptr is not:

ptr ─► b1.name[0]

6️⃣ Where does 'L' address actually come?

Here 👇

ptr->name


Breakdown:

ptr->name
== (*ptr).name
== b1.name


Now:

b1.name   // char[10]


👉 array expression
👉 decays to &b1.name[0]
👉 which is 'L' address

7️⃣ Final comparison table (THIS is the key)
Expression	Result
ptr	address of whole b1
*ptr	whole struct book
ptr->name	address of name[0]
ptr->name[0]	'L'
&b1	address of structure
b1.name	array → decays to char*
8️⃣ One-line golden truth 🧠🔥

Decay happens to arrays, not to structures.
ptr points to the structure, not to its first member.

9️⃣ Your sentence — corrected slightly ✅

நீங்க சொன்னது:

“ptr உள்ளே இருப்பது &b1 இதுடைய அட்ரஸ் என்பது decay ஆகி முதல் வேல்யூ L-ன் அட்ரஸை கொடுக்கும் அல்லவா?”

✔️ Corrected version:

ptr-ல் இருப்பது &b1
அது decay ஆகாது
'L' address வருவது ptr->name use பண்ணும்போது மட்டும்
*/