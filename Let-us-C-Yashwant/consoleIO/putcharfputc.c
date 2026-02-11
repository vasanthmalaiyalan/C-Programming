#include<stdio.h>

int main(void)
{
    char ch='A';

    printf("%zu\n",sizeof('A'));//compailer treat if character alway treat int
    putchar(ch);//int value change ascii char print
    putchar(ch);
    putchar(ch);

    fputc('z',stdout);//stdout means streaming output of screen
    fputc('z',stdout);//fputc() integer value-ஐ character code-ஆ interpret பண்ணி stream-க்கு ஒரு byte-ஆ write செய்கிறது.'z' கொடுத்தாலும், 122 கொடுத்தாலும் result same.
    fputc('z',stdout);

    return 0;
}

//=====xfputc இதுவும் 'z' என்கின்ற int value interpret AsCii char value?x=========x===========x=============

/*
ஆம் 👍 மிகவும் சரியான கேள்வி.

🔑 Short Answer

fputc()-க்கும் putchar()-க்கும் ஒரே logic தான்.
அது argument-ஆ வரும் integer value-ஐ
character code-ஆ interpret பண்ணி output stream-க்கு எழுதும்.

📌 Function Prototype
int fputc(int c, FILE *stream);


c → integer (0–255 range expected)

stream → எங்கே எழுதணும் (stdout, file, etc.)

🧠 Example 1
fputc('Z', stdout);


'Z' → ASCII 90 (int)

fputc(90, stdout)

Output: Z

🧠 Example 2
fputc(122, stdout);


122 → ASCII

Output: z

🧠 Example 3 (file-க்கு எழுதுவது)
FILE *fp = fopen("data.txt", "w");
fputc('A', fp);
fclose(fp);


'A' → 65

data.txt-ல் store ஆகும் byte = 65

🔍 Important Clarification

fputc() “ASCII-ஆ convert” பண்ணாது.
அது simply:

integer value-ஐ

unsigned char-ஆ convert பண்ணி

அந்த byte-ஐ stream-க்கு write பண்ணும்

C standard behavior:

fputc(int c, stream)
→ write (unsigned char)c

🔁 fgetc + fputc full chain
int ch;
while ((ch = fgetc(fp1)) != EOF)
    fputc(ch, fp2);


Flow:

File1 byte → fgetc → int → fputc → File2 byte


No conversion magic.
Just numeric byte transfer.

🏁 Final One-Line Truth

ஆம் — fputc() integer value-ஐ character code-ஆ interpret பண்ணி
stream-க்கு ஒரு byte-ஆ write செய்கிறது.
'z' கொடுத்தாலும், 122 கொடுத்தாலும் result same.
*/

/*
1️⃣ #include <stdio.h>

👉 Input / Output functions-க்கு தேவையான header
👉 putchar() மற்றும் fputc() இங்கே declare பண்ணப்பட்டிருக்கும்

🔹 2️⃣ char ch = 'A';

👉 ch variable-ல் 'A' store ஆகிறது
👉 ASCII value = 65
👉 Size = 1 byte

🔹 3️⃣ putchar(ch);
putchar(ch);


putchar() → stdout-க்கு ஒரு character print பண்ணும்

ch = 'A'

Screen-ல் print: A

இதை 3 தடவை call பண்ணியிருக்கோம்:

putchar(ch);
putchar(ch);
putchar(ch);


👉 Output:

AAA

🔹 4️⃣ fputc('Z', stdout);
fputc('Z', stdout);

What is fputc()?
int fputc(int c, FILE *stream);


c → print செய்ய வேண்டிய character

stream → எங்கே print செய்யணும்

இங்கே:

'Z'

stdout → standard output (screen)

👉 Screen-ல் print: Z

இதை 3 தடவை call பண்ணியிருக்கோம்:

fputc('Z', stdout);
fputc('Z', stdout);
fputc('Z', stdout);


👉 Output:

ZZZ

🔹 Final Output
AAAZZZ

🧠 Important Concept
putchar(ch) என்பது internally இதே மாதிரி தான்:
fputc(ch, stdout);


👉 putchar() = shortcut
👉 fputc() = general version

🔍 Difference between putchar & fputc
Function	Prints to
putchar(c)	stdout மட்டும்
fputc(c, stream)	எந்த stream-க்கும்

Example:

fputc('A', file_ptr);   // file-க்கு எழுதும்

🏁 Final One-Line Summary

இந்த program 'A'-ஐ மூன்று முறை
மற்றும் 'Z'-ஐ மூன்று முறை
screen-ல் print செய்கிறது.
putchar() மற்றும் fputc() இரண்டும் single character output functions.
*/

//======xநாம் முன்பு பார்த்திருந்தோம் அல்லவா fgetc() தான் கேரக்டரை ascii value -வாக மாற்றி putchar -க்கு கொடுக்கிறது putchar அந்த நம்பரில் இருக்கும் value யை print செய்கிறது ஆனால் இங்கு putchar என்ன செய்கிறதுx===========x===========x============

/*
🔥 ரொம்ப நல்ல கேள்வி. இப்போ தான் முழு படம் clear ஆகும்.

நீங்க சொன்னது:

fgetc() ASCII value-ஆ return பண்ணும்
putchar() அந்த number-ஐ character-ஆ print பண்ணும்

✔️ இது சரி.

ஆனா இப்போ code-ல்:

char ch = 'A';
putchar(ch);


👉 இங்க fgetc() இல்லையே?
அப்போ putchar() என்ன செய்கிறது?

🔑 முக்கிய உண்மை

putchar()-க்கு எங்கிருந்து value வந்தாலும் பரவாயில்லை.
அது simply அந்த integer value-ஐ character-ஆ interpret பண்ணி print பண்ணும்.

🧠 இரண்டு cases compare பண்ணலாம்
🟢 Case 1: File reading
ch = fgetc(fp);
putchar(ch);


Flow:

file byte → fgetc() → int (65) → putchar() → 'A'

🟢 Case 2: Direct variable
char ch = 'A';
putchar(ch);


Flow:

'A' → ASCII 65 → putchar() → 'A'


👉 fgetc() இங்கே தேவையில்லை
👉 ஏனென்றால் 'A' already character literal

🔍 Important detail

putchar() prototype:

int putchar(int c);


அது int accept பண்ணும்

0–255 range-ல value இருந்தா

அதற்கான character-ஐ print பண்ணும்

🧪 Example
putchar(65);   // prints A
putchar('A');  // prints A


👉 இரண்டும் same
👉 'A' internally 65 தான்

🧠 Key Insight

fgetc() “ASCII-ஆ மாற்றவில்லை”.
அது file-ல இருந்த byte-ஐ integer-ஆ return பண்ணுது.

putchar() “number-ஐ character-ஆ மாற்றவில்லை”.
அது simply அந்த number-ஐ character code-ஆ interpret பண்ணுது.

🏁 Final one-line answer

இங்கு putchar()
fgetc()-லிருந்து value வாங்கவில்லை.
ch-ல் இருக்கும் ASCII value-ஐ
character-ஆ interpret பண்ணி print பண்ணுகிறது.
*/

//======xputchar('A');  ஆனால் இங்கு டைரக்டாக கேரக்டர் தானே வருகிறது அதனால் கேரக்டரை அப்படியே பிரிண்ட் செய்து விடுகிறதாx==========x==========x============

/*
அருமையான கேள்வி 👍
இது தான் character vs integer representation-ன் final clarity point.

🔑 Short answer

putchar('A');
இங்க “character” வந்தது போல தெரியும்.
ஆனால் C-க்கு அது character இல்லை — integer value (65) தான்.
அதனால் putchar() அந்த value-ஐ character-ஆ print பண்ணுகிறது.

🧠 முக்கிய உண்மை (very important)

C-ல்:

'A'


👉 இது char type இல்லை ❗
👉 இது int type constant

Yes 😄
Character literal 'A' actually int ஆக treat ஆகும்.

🔍 Example proof
printf("%zu\n", sizeof('A'));


Output:

4   (most systems-ல்)


👉 அதாவது 'A' = int (usually 4 bytes)

🧠 What really happens here?
putchar('A');


Internal view:

'A'  →  65 (int)
putchar(65)
→ ASCII 65 → prints 'A'


👉 “character direct-ஆ வந்தது”ன்னு தோன்றும்
👉 ஆனால் அது already numeric value தான்

🔄 Compare both cases
Case 1
putchar(65);

Case 2
putchar('A');


👉 இரண்டும் identical

🔴 Important mental shift

C-ல்:

“character” என்ற தனி runtime entity இல்லை

எல்லாம் numbers தான்

interpretation மட்டும் different

🧠 Super clear model (lock this 🔒)
'A'  →  integer 65
65   →  putchar()
       → ASCII table lookup
       → prints 'A'

🏁 Final answer

putchar('A');
“character-ஐ அப்படியே print செய்கிறது” இல்லை.
'A' already integer 65 ஆக இருப்பதால்,
அந்த numeric value-ஐ character-ஆ interpret பண்ணி print செய்கிறது.
*/