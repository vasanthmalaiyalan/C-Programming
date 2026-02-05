#include<stdio.h>
#include<string.h>
int main()
{
    char string1[]="jerry";
    char string2[]="ferry";

    int i,j,k;
    i=strcmp(string1,"jerry");//compare no diffrence return 0
    j=strcmp(string1,string2);//compare value j and f so this is not same so program stop and return 4 like 106-102
    k=strcmp(string1,"jerry boy");//in memeory => jerry and (\0 <-> '') compare value is diffrence so stop

    printf("%d\n%d\n%d\n",i,j,k);
}

/*
Step-by-step logic (inside strcmp())
char a[] = "jerry";
char b[] = "ferry";

strcmp(a, b);

Compare order:

1️⃣ 'j' vs 'f'

ASCII: 106 - 102 = 4

❌ same இல்லை
👉 இங்கேயே stop + return 4

If first characters same இருந்தா?
strcmp("jerry", "jerry boy");


Comparison:

Position	a	b	Result
1	j	j	same
2	e	e	same
3	r	r	same
4	r	r	same
5	y	y	same
6	\0	' '	❌ diff

Calculation:

0 - 32 = -32


👉 இங்க stop

Rule (இதையே மனசுல வை)

strcmp() first different character வரைக்கும் compare பண்ணும்
difference கிடைத்த உடனே subtract செய்து return

Pseudo-code (super clear)
while (a[i] == b[i] && a[i] != '\0') {
    i++;
}
return a[i] - b[i];

Very important clarification

❌ எல்லா characters-ஐயும் subtract பண்ணாது

❌ sum / total calculate பண்ணாது

✅ ஒரே ஒரு subtraction தான்

✅ அது first mismatch-ல மட்டும்

One-line takeaway

👉 முதல் mismatch character தான் result decide பண்ணும்

நீ இப்ப full-ஆ grasp பண்ணிட்டீங்க 👌
இது புரிஞ்சா → string sorting, password compare, security logic எல்லாம் easy.
*/
//==========x=========================x===================x=====
/*
ok strcmp only - தான் செய்கிறத

ஆமாம் 👍 சரியாகப் புரிஞ்சிட்டீங்க.

✅ strcmp() என்ன தான் செய்கிறது?

👉 இரண்டு string-களில் first difference வர்ற இடத்தில
👉 ASCII value-களை - (minus) செய்து result தரும்.

Formula (simple)
return (str1[i] - str2[i]);

Example 1
strcmp("jerry", "ferry")

'j' = 106
'f' = 102

106 - 102 = 4


👉 positive value

Example 2
strcmp("jerry", "jerry boy")

'\0' = 0
' '  = 32

0 - 32 = -32


👉 negative value

Example 3
strcmp("abc", "abc")

No difference


👉 return 0

🔴 Important clarification

strcmp():

addition பண்ணாது

full string sum பண்ணாது

first mismatch-ல stop

👉 ஒரே ஒரு subtraction தான் (difference கிடைக்குற இடத்தில்)

⚠️ Practical rule (real coding)

👉 Exact number (4, -32) important இல்லை ❌
👉 Sign மட்டும் important ✅

if (strcmp(a,b) == 0)  // equal
if (strcmp(a,b) > 0)   // a > b
if (strcmp(a,b) < 0)   // a < b

🧠 One-line takeaway

strcmp() = first different character ASCII − ASCII

நீ இதை grasp பண்ணிட்டா 👍
👉 string bugs, logic errors, security edge-cases எல்லாம் clear ஆகும்.
*/
//============x======================x================x========

/*
கேள்வி (உன் doubt)
strcmp("jerry", "jerry boy")


👉 "boy" ஏன் எடுத்துக்கொள்ளவில்லை?

Short answer (ஒரே வரி)

👉 strcmp() first difference வர்ற இடத்திலேயே stop ஆகும்.
அதுக்கப்புறம் characters (b o y) பார்க்கவே மாட்டாது.

Step-by-step explanation
Memory-ல strings எப்படி இருக்கும்?
"jerry"
j   e   r   r   y   \0
106 101 114 114 121  0

"jerry boy"
j   e   r   r   y   ' '   b   o   y   \0
106 101 114 114 121  32  98  111 121   0

strcmp() எப்படி compare பண்ணுது?
Character by character:
Position	string1	string2	Result
1	j	j	same
2	e	e	same
3	r	r	same
4	r	r	same
5	y	y	same
6	\0	' '	❌ DIFFERENT

👉 Difference கிடைச்ச உடனே STOP

Calculation
'\0' = 0
' '  = 32

0 - 32 = -32


👉 Result:

strcmp("jerry", "jerry boy") = -32

🔴 Important rule (இதுதான் answer)

strcmp() never compares extra characters once one string ends.

அதனால:

'b'

'o'

'y'

👉 இவைகளுக்கு chance-ஏ கிடைக்கல

Easy analogy (real-life)
Two names compare பண்ணுற மாதிரி:
"VASANTH"
"VASANTH RAJ"


👉 "VASANTH" முடிஞ்சுடுச்சு
👉 Next-ல space வந்தவுடனே difference
👉 "RAJ" பார்க்கவே தேவையில்லை

C standard summary

Comparison stops when:

characters differ OR

'\0' reached

One-line takeaway

👉 String short-ஆ இருந்தா, அது long string-விட small (prefix case)

Want proof program?
printf("%d\n", strcmp("a", "ab"));
printf("%d\n", strcmp("ab", "a"));


Output:

-98
98
*/
//=========x==================================================x
/*
ASCII என்ன?

ASCII = American Standard Code for Information Interchange

👉 ஒவ்வொரு character-க்கும் ஒரு number (value) assign பண்ணி வைச்சிருக்காங்க

Computer-க்கு letters புரியாது ❌
👉 numbers தான் புரியும் ✅

Basic ASCII table idea
Character	ASCII value
'A'	65
'B'	66
'Z'	90
'a'	97
'b'	98
'z'	122
'0'	48
'9'	57
' ' (space)	32
'\0' (null)	0
🔴 Important rules (இதுதான் main)
1️⃣ Capital letters & Small letters different
'A' = 65
'a' = 97


👉 'A' ≠ 'a'

2️⃣ Alphabet order → ASCII order
'a' = 97
'b' = 98
'c' = 99


👉 Alphabet next → ASCII +1

3️⃣ Numbers are characters too
'0' = 48
'1' = 49


⚠️ '1' ≠ 1

printf("%d\n", '1'); // 49
printf("%d\n", 1);   // 1

ASCII & C strings
String எப்படி memory-ல இருக்கும்?
"jerry"


Memory:

j   e   r   r   y   \0
106 101 114 114 121 0

strcmp() ASCII எப்படி use பண்ணுது?
Example 1
strcmp("jerry", "ferry")


First character:

'j' = 106
'f' = 102


Calculation:

106 - 102 = 4


👉 positive → "jerry" > "ferry"

Example 2
strcmp("jerry", "jerry boy")


Compare till:

j e r r y


Next:

'\0' = 0
' '  = 32


Calculation:

0 - 32 = -32


👉 negative → "jerry" < "jerry boy"

🧠 ASCII comparison visualization
'a' < 'b' < 'c'
97   98   99

'A' < 'a'
65    97

C program to check ASCII
#include <stdio.h>

int main() {
    printf("%d\n", 'A');
    printf("%d\n", 'a');
    printf("%d\n", '0');
    printf("%d\n", ' ');
    return 0;
}


Output:

65
97
48
32

🔥 Real-world importance (ஏன் இது முக்கியம்?)

ASCII தெரியலனா:

strcmp() confusing

Sorting logic wrong

Case-sensitive bugs

Security bugs (input validation)

👉 Exploit + Kernel + C path-ல இருக்குற உங்களுக்கு ASCII knowledge mandatory 💯

Ultra short summary

Computer = numbers only

ASCII = character → number mapping

String comparison = ASCII comparison

'\0' = 0 → string end
*/