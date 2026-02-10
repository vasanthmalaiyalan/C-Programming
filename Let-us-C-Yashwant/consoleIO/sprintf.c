#include<stdio.h>
#include<string.h>

int main()
{
int i=10;
char ch='A';
float a=3.14;
char str[20];

printf("Before sprintf:\n");
printf("%d %c %f\n",i,ch,(double)a);
sprintf(str,"%d %c %f",i,ch,(double)a);// sprintf only write in memory not screen ok
printf("\nString after sprintf:\n");
printf("%s\n",str);
// change values to prove sscanf works
    i = 0;
    ch = '?';
    a = 0.0;
    sscanf(str, "%d %c %f", &i, &ch, &a);

    printf("\nAfter sscanf (values read from string):\n");
    printf("i=%d ch=%c a=%f\n", i, ch, (double)a);

    return 0;
}

/*
🔵 sprintf() என்ன செய்கிறது?

sprintf() = printf() போல format பண்ணும்
ஆனால் screen-க்கு print பண்ணாது
memory-ல உள்ள char array-க்குள் எழுதும்

Syntax
sprintf(destination_string, "format", values);

🔹 Example code-ஐ step-by-step பார்ப்போம்
int i = 10;
char ch = 'A';
float a = 3.14;
char str[20];

1️⃣ printf()
printf("\n%d %c %f", i, ch, a);


👉 இது நேரடியாக screen-ல print ஆகும்

Output:

10 A 3.140000

2️⃣ sprintf()
sprintf(str, "%d %c %f", i, ch, a);


👉 இதே output
👉 screen-க்கு இல்ல
👉 str array-க்குள் characters-ஆ store ஆகும்

Memory-ல str எப்படி இருக்கும்?

'1' '0' ' ' 'A' ' ' '3' '.' '1' '4' '0' '0' '0' '0' '\0'


👉 எல்லாமே characters (char)
👉 numbers கூட text-ஆ convert ஆகி தான் store ஆகுது

3️⃣ Stored string-ஐ print பண்ண
printf("\n%s", str);


👉 இப்போ தான் screen-ல தெரியும்

Output:

10 A 3.140000

🔑 Important point (மிக முக்கியம்)

sprintf() output-ஐ மறைக்கல
அது screen-க்கு போகாமல்
memory-ல string-ஆ build பண்ணுது

⚠️ Practical warning (modern C knowledge)
char str[20];
sprintf(str, "%f", 123456.789);


❌ buffer overflow chance

✅ Safe version
snprintf(str, sizeof(str), "%f", 123456.789);
*/