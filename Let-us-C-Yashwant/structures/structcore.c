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

    printf("%p\n", (void *)&b1);//Address of L
    printf("%p\n", (void *)&b1.name);//Address of L
    printf("%p\n", (void *)b1.name);//Address of L
}
/*
🔴 Short answer (crystal clear)

👉 அது 'L' (first character) இருக்கிற memory address தான்
👉 “Let Us C” என்ற முழு string-க்கு separate address கிடையாது

இப்ப WHY என்பதை step-by-step 👇
Structure member:
char name[10] = "Let Us C";


Memory-ல இது எப்படி இருக்கும்?

Address     Value
1000        'L'
1001        'e'
1002        't'
1003        ' '
1004        'U'
1005        's'
1006        ' '
1007        'C'
1008        '\0'


📌 String = characters array
📌 String-க்கு தனியா address கிடையாது

இப்ப உங்க மூன்று expressions-ஐ பார்ப்போம்
1️⃣ &b1
&b1


👉 Structure ஆரம்ப address
👉 Structure first member = name
👉 name[0] = 'L'

So:

&b1 == address of 'L'

2️⃣ &b1.name
&b1.name


👉 name array-ன் address
👉 Array start = name[0]

So:

&b1.name == address of 'L'


(Type different, address same)

3️⃣ b1.name
b1.name


👉 Array expression
👉 decays to &b1.name[0]

So:

b1.name == address of 'L'

🧠 Important truth (THIS is the key)

C-ல “string address”ன்னு தனியா எதுவும் இல்லை
String-னு சொல்வது
👉 first character-ன் address தான்

❓ “Let Us C” முழு name-க்கு address இல்லையா?

👉 இல்லை ❌
C-ல string =

address of first char + continuous memory


So:

'L' address = string address

Rest chars = +1, +2, …

🔑 Why all three print SAME value?

Because all three ultimately point to:

&b1.name[0]  → 'L'

🧠 One golden sentence (remember forever)

In C, the address of a string is the address of its first character.

✍️ Exam-ready answer (Tamil)

இந்த print ஆகும் address என்பது 'L' என்ற முதல் character இருக்கும் memory address தான்; C மொழியில் string-க்கு தனியான address இல்லாமல், முதல் character-ன் address-ஐ string address-ஆக பயன்படுத்துகிறது.
*/