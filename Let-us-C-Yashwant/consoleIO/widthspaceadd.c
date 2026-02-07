#include<stdio.h>
int main()
    {
        int weight = 63;

        printf("weight is |%dkg|\n",weight);
        printf("weight is |%2dkg|\n",weight);//already 2 digit didn't add space
        printf("weight is |%3dkg|\n",weight);//already 2 digit add 1 digit
        printf("weight is |%4dkg|\n",weight);//already 2 digit add 2 digit
        printf("weight is |%5dkd|\n",weight);//already 2 digit add 3 didgit space 
    }
/*
🔵 Field Width Specifier – உண்மையான அர்த்தம்
%6d


இதன் அர்த்தம்:

“இந்த integer-ஐ print பண்ணும்போது
குறைந்தது 6 columns இடம் ஒதுக்கு”

👉 exact-ஆ 6 columns print பண்ணுன்னு இல்ல
👉 minimum width = 6

🔹 ஏன் output எல்லாம் same மாதிரி தெரியுது?

உங்க example:

int weight = 63;


👉 63 = 2 digits மட்டும்

Case-by-case பார்ப்போம் 👇
🔸 %d
weight is 63 kg


👉 எந்த restriction-உம் இல்ல
👉 just 63 print

🔸 %2d
weight is 63 kg


👉 63 already 2 digits
👉 minimum width = 2
👉 extra space தேவையில்லை

🔸 %4d
weight is   63 kg


👉 minimum width = 4
👉 63 = 2 digit
👉 left-ல 2 space சேர்க்கும்

⚠️ ஆனா text-உம் சேர்ந்து print ஆகுறதால
visually same மாதிரி தெரியும்

🔸 %6d
weight is     63 kg


👉 minimum width = 6
👉 left-ல 4 spaces

🔸 %-6d (Left justified)
weight is 63     kg


👉 value left-ல
👉 right-ல spaces

🔴 ஏன் book-ல output எல்லாம் same மாதிரி காட்டுது?

📌 காரணம்:

space-கள் கண்ணுக்கு தெரியாது

proportional font / formatting issue

textbook alignment limitation

👉 actual-ஆ spaces differ ஆகுது

🧪 REAL difference பார்க்க BEST trick 💡

இந்த code try பண்ணுங்க:

printf("|%2d|\n", weight);
printf("|%4d|\n", weight);
printf("|%6d|\n", weight);
printf("|%-6d|\n", weight);

Output:
|63|
|  63|
|    63|
|63    |


🔥 இப்போ difference clear-ஆ தெரியும்

🔑 Important Rule (Exam + Interview)

Field width = minimum width

value பெரியதா இருந்தா → truncate ஆகாது

value சிறியதா இருந்தா → spaces add ஆகும்

Example:

printf("%2d", 1234);


Output:

1234


❌ cut ஆகாது

🧠 ஏன் இது use ஆகுது?

Field width use case:

Tables print பண்ண

Reports

Columns align பண்ண

Example:

printf("%-10s %5d\n", "Ram", 85);
printf("%-10s %5d\n", "Kumar", 120);

🟢 Final Answer (உங்க question-க்கு)

Output same மாதிரி தெரியுறது
space-கள் invisible ஆ இருப்பதால.
Field width உண்மையிலேயே work ஆகுது.
Borders (| |) போட்டா தான் difference தெரியும்.
*/