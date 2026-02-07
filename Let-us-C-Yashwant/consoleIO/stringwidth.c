#include<stdio.h>
int main()
{
    char firstname1[] = "sandy";
    char surename1[]="master";
    char firstname2[]="virat";
    char surename2[]="kohil";

    printf("|%20s| |%20s|\n",firstname1,surename1);
    printf("|%20s| |%20s|\n",firstname2,surename2);//if print string minimum 20 column space mandatory
}

/*
🔵 %20s format specifier – stringக்கு என்ன அர்த்தம்?
%20s


இதன் அர்த்தம்:

String-ஐ print பண்ணும்போது
minimum-ஆ 20 columns இடம் ஒதுக்கு
(default = right justified)

🔹 Program என்ன செய்கிறது?
printf("\n%20s%20s", firstname1, surname1);
printf("\n%20s%20s", firstname2, surname2);


👉 ஒவ்வொரு name-க்கும்
👉 20 columns reserve பண்ணுது
👉 short name-ஆ இருந்தா → left-ல spaces add
👉 long name-ஆ இருந்தா → spaces குறையும்

🔍 Output ஏன் book-ல குழப்பமாக தெரிகிறது?

Book output (spaces invisible):

  Sandy                          
 AjayKumar                 
    Malya 
     Gurubaxani 


👉 Spaces கண்ணுக்கு தெரியாது
👉 அதனால “line break” மாதிரி தோணும்
👉 உண்மையில same line-ல தான் print ஆகுது

🧪 REAL clarity – boundary trick (BEST 👌)

இதை பாருங்க 👇

printf("|%20s|%20s|\n", firstname1, surname1);
printf("|%20s|%20s|\n", firstname2, surname2);

Actual output:
|               Sandy|               Malya|
|           AjayKumar|          Gurubaxani|


🔥 இப்போ crystal clear:

Sandy → 5 chars → left-ல 15 spaces

AjayKumar → 9 chars → left-ல 11 spaces

எல்லாமே 20 column box-க்குள்ள neatly align

🔑 %20s vs %-20s
Right justified (default)
%20s


Output:

|               Sandy|

Left justified
%-20s


Output:

|Sandy               |

🧠 Important rules (exam + real use)

1️⃣ Field width = minimum width
2️⃣ String long-ஆ இருந்தா → truncate ஆகாது
3️⃣ %20s → right aligned
4️⃣ %-20s → left aligned

💡 Why this is useful?

Names list

Reports

Tables

Professional formatted output

Example:

printf("%-20s %5d\n", "AjayKumar", 95);
printf("%-20s %5d\n", "Sandy", 88);

🏁 One-line summary

%20s string-க்கு fixed column width கொடுத்து
names-ஐ neat-ஆ align பண்ண உதவும்.
Spaces invisible என்பதால boundary (| |) வைச்சா தான் difference clear.
*/