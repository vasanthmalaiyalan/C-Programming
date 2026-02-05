#include<stdio.h>
#include<string.h>

int main()
{
    char names[][10]={
        "alshay",//string means like "" this is end appear this one '\0'
        "parag",
        "kumar",
        "vasanth",
        "gopal",
        "sethu"
    };
    int i;
    char t;
    printf("Original:%s %s\n",&names[2][0],&names[3][0]);//names[2] both are same and %s means print starting address to ending address '\0' 
    for(i=0;i<=9;i++)
    {
        t=names[2][i];
        names[2][i]=names[3][i];
        names[3][i]=t;
    }
    printf("New %s %s\n",&names[2][0],&names[3][0]);
}

/*
நீ நினைக்குற logic (natural thought)
&names[2][0]


👉 “இது first character address தானே?”
👉 “அப்படின்னா %s use பண்ணும்போது k மட்டும் வரணுமே?”

இது தான் confusion point.

🔑 Key answer (one line)

%s ஒரு character-ஐ print பண்ணாது
%s அந்த address-ல இருந்து '\0' வரைக்கும் முழு string-ஐ print பண்ணும்

Memory view (most important)
names[2] = "kumar"


Memory:

Address →  k   u   m   a   r   \0
           ↑
       &names[2][0]


👉 &names[2][0] points to 'k'
👉 BUT %s means:

“இந்த address-ல இருந்து start பண்ணி,
\0 வரைக்கும் characters print பண்ணு”

Why k மட்டும் print ஆகல?
Because:
printf("%s", &names[2][0]);


printf internally does:

while(*ptr != '\0') {
   print(*ptr);
   ptr++;
}


So output:

k u m a r

If k மட்டும் print பண்ணணும்னா?

👉 %c use பண்ணணும்:

printf("%c\n", names[2][0]);


Output:

k

Compare these (VERY IMPORTANT)
Case 1 – %s
printf("%s\n", &names[2][0]);


Output:

kumar

Case 2 – %c
printf("%c\n", names[2][0]);


Output:

k

Why names[2] and &names[2][0] both work?
names[2]        → address of first char
&names[2][0]    → address of first char


👉 Both SAME address ✔

That’s why:

printf("%s", names[2]);
printf("%s", &names[2][0]);


Both print same output

One dangerous example (to lock the concept)
printf("%s\n", &names[2][1]);


Output:

umar


Why?

names[2][1] → 'u'


%s starts from 'u' till \0

🧠 Final mental model (stick this in head)

%c → single character

%s → start address of string

&names[i][0] → address of first character

%s NEVER prints just one char

One-line takeaway

%s doesn’t care about “first character”, it cares about “starting address”.

நீ இந்த doubt கேள்வி கேட்டதே —
👉 நீ pointers + strings சரியான direction-ல புரிஞ்சுக்கிட்டு இருக்கேன்னு meaning 💯
*/