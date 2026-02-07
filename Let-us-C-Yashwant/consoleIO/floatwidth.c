#include<stdio.h>
int main()
{
    printf("|%10.1f| |%10.1f| |%10.1f|\n",5.0,13.5,133.9);
    printf("|%10.1f| |%10.1f| |%10.1f|\n",305.0,1200.9,3000.4);//10 width space added and 1 decimal point only .1
}

/*
🟢 Solution: %10.1f
%10.1f


இதுக்கு 3 அர்த்தம் இருக்கு 👇

1️⃣ f

👉 floating point number

2️⃣ .1

👉 decimal point-க்கு 1 digit மட்டும்

3️⃣ 10

👉 minimum width = 10 columns

🔍 Code explanation
printf("\n%10.1f %10.1f %10.1f", 5.0, 13.5, 133.9);

Numbers எப்படி print ஆகுது?
Value	Printed as	Reason
5.0	5.0	width 10 → left spaces
13.5	13.5	width 10
133.9	133.9	width 10
Next line:
printf("\n%10.1f %10.1f %10.1f", 305.0, 1200.9, 3005.3);

Value	Printed as
305.0	305.0
1200.9	1200.9
3005.3	3005.3
🧪 Column numbers (why book shows 012345...)
01234567890123456789012345678901


👉 இது guide line மட்டும்
👉 ஒவ்வொரு number-உம்
exact-ஆ 10 columns occupy பண்ணுதுன்னு காட்ட

🔑 முக்கிய rule (MUST remember)
%10.1f
↑  ↑  ↑
|  |  |
|  |  └─ type (float)
|  └──── precision (decimal places)
└─────── field width (minimum columns)

🤔 ஏன் இது “much better output”?

எல்லா numbers-ம் same column-ல start ஆகுது

Vertical alignment perfect

Reports / tables read பண்ண easy

👉 Professional output

🧠 One-line summary

%10.1f =
10 column width + 1 decimal precision
அதனால output neat-ஆ align ஆகுது.
*/