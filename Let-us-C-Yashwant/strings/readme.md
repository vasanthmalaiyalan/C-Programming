String என்றால் என்ன?

Integer values-ஐ store பண்ண int array use பண்ணுறோம்.

அதே மாதிரி characters (letters) store பண்ண char array use பண்ணுறோம்.

இந்த character array-ஐ தான் Stringன்னு சொல்றோம்.

👉 Example:

char name[] = { 'H','A','E','S','L','E','R','\0' };

🔹 '\0' (Null character) என்ன?

'\0' = Null character

ASCII value = 0

இது string முடிவை காட்டும் symbol

⚠️ Important:

'\0' ❌ '0' அல்ல

'0' ASCII = 48

'\0' ASCII = 0

🔹 ஏன் '\0' அவசியம்?

C-ல string functions (printf, strlen, strcpy)
👉 string எங்க முடிகிறதுன்னு தெரிஞ்சுக்க '\0'-ஐ தான் நம்பும்.

அதனால்:

'\0' இல்லாத char array → ❌ string கிடையாது

அது சும்மா characters collection தான்

🔹 Memory-ல string எப்படி store ஆகும்?
char name[] = "HAESLER";


Memory:

H  A  E  S  L  E  R  \0


ஒவ்வொரு character → 1 byte

எல்லாம் continuous memory-ல store ஆகும்

கடைசியில் automatic-ஆ '\0' சேர்க்கப்படும்

🔹 Shortcut way (C special feature)

இதைக் கவனிச்சிருப்பீங்க 👇

char name[] = "HAESLER";


👉 இதில் நீ '\0' எழுதவே வேண்டாம்
👉 C compiler automatic-ஆ add பண்ணும்

Equivalent to:

char name[] = { 'H','A','E','S','L','E','R','\0' };

🔹 Simple definition (exam-ready 💡)

A string is a one-dimensional array of characters terminated by a null character ('\0').

🔹 Quick recap 🔁

String = char array

Last character must be '\0'

'\0' ≠ '0'

Without '\0' → not a string

"text" → compiler adds '\0'



ஏன் string elements-ஐ direct-ஆ access பண்ண மாட்டோம்?

C-ல string characters-ஐ access பண்ண பல வழிகள் இருக்கு:

name[i]

*(name+i)

pointer tricks …

ஆனா real programs-ல இதை எல்லாம் rarely use பண்ணுவாங்க.

👉 காரணம்:
printf() & scanf() already easy way கொடுத்திருக்கு 😄

🔹 printf("%s", name) எப்படி வேலை செய்கிறது?
char name[] = "Klinsman";
printf("%s", name);

%s என்ன?

%s = string format specifier

name → array base address

printf:

first character-ல இருந்து start பண்ணும்

'\0' வரைக்கும் print பண்ணும்

❌ '\0'-ஐ print பண்ணாது

Output:

Klinsman

🔹 '\0' print ஆகாததுக்கு காரணம்?

'\0' = string end marker

அது data இல்லை, control character

அதனால் printf அதை skip பண்ணும்

🔹 scanf("%s", name) எப்படி வேலை செய்கிறது?
char name[25];
scanf("%s", name);

Step-by-step:

Keyboard-ல characters type பண்ணுறோம்

scanf:

character by character array-க்குள் store பண்ணும்

Enter key press பண்ணும்போது:

automatically '\0' add பண்ணும்

Example input:

Debashish


Memory:

D e b a s h i s h \0

🔹 ஏன் &name போடல?
scanf("%s", name);   // ✅ correct


👉 காரணம்:

Array name (name) itself = base address

அதனால் & தேவையில்லை

❌ Wrong:

scanf("%s", &name);

🔹 char name[25] என்றால் என்ன?

25 bytes memory reserve ஆகும்

Max 24 characters + 1 '\0'

⚠️ Input 25 characters-ஐ தாண்டினா → buffer overflow (danger)

🔹 Sample program explained
char name[25];
printf("Enter your name ");
scanf("%s", name);
printf("Hello %s!", name);


Input:

Debashish


Output:

Hello Debashish!

🔹 Important limitation (VERY IMPORTANT ⚠️)
scanf("%s", name);


👉 space வந்ததும் stop ஆகும்

Input:

Debashish Kumar


Stored:

Debashish

🔹 Exam-ready summary 💡

%s → string format specifier

printf("%s", name) → prints till '\0'

scanf("%s", name) → reads till space / enter

'\0' auto-added by scanf

Array name itself = base address

🔥 One-line takeaway

%s makes string handling simple by automatically working till the null character ('\0').