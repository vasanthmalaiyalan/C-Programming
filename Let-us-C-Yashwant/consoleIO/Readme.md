🔴 Confusion point

printf("%d") characters-ஆ convert ஆகுது
அப்படின்னா sizeof(int) ஏன் 4 bytes காட்டுது?

🔑 Short answer (one line)

sizeof(int) memory-ல variable எவ்வளவு byte occupy பண்ணுது
printf("%d") output-ல என்ன characters print ஆகுது

👉 ரெண்டும் வேறு world 🌍

🔵 1️⃣ sizeof(int) — MEMORY concept
int weight = 63;
printf("%zu\n", sizeof(weight));


Output:

4


👉 இதன் அர்த்தம்:

weight variable

RAM-ல 4 bytes occupy பண்ணுது

Example memory (conceptually):

| 00 | 00 | 00 | 3F |   ← 63


📌 இது runtime output-க்கு சம்பந்தமே இல்லை

🔵 2️⃣ printf("%d", weight) — OUTPUT concept
printf("%d", weight);


What happens internally:

int 63 (4 bytes in RAM)
        ↓
converted to text
        ↓
'6' '3'


👉 Screen-க்கு போவது:

characters மட்டும்

Printed item	Type	Bytes
'6'	char	1
'3'	char	1

👉 Output = 2 bytes

🔴 IMPORTANT RULE (இதுதான் key)

sizeof measures MEMORY
printf produces OUTPUT (text)

👉 memory size ≠ output size

🧪 Proof with code (perfect clarity)
int x = 12345;

printf("sizeof(x) = %zu\n", sizeof(x));
printf("printed x = %d\n", x);


Output:

sizeof(x) = 4
printed x = 12345


👉 12345 = 5 characters
👉 But int still = 4 bytes in memory

🔵 Analogy (lock this in 🧠)
Think like this:

Memory = storage box 📦

printf = printer 🖨️

📦 Box size:

int = 4 bytes


🖨️ Printer prints:

characters only


Printer doesn’t care how big the box was.

🧠 Why this matters (systems thinking)

Network protocols

File formats

Binary vs text

Serialization / deserialization

This exact distinction saves bugs 🔥

🏁 Final answer (clean)

✔ sizeof(int) → memory size (4 bytes)
✔ printf("%d") → converts int to characters
✔ Characters are char → 1 byte each
✔ These two are not contradictory


==========x==================x=================x=============

🔵 Escape Sequenceன்னா என்ன?

Escape sequence =
👉 \ (backslash) + ஒரு character

Backslash பார்த்ததும்:

C compiler “இது normal character இல்லை,
special meaning இருக்கு”னு புரிஞ்சுக்குது.

🔹 Example: \n (newline)
printf("Hello\nWorld");


Output:

Hello
World


👉 \n

cursor-ஐ next line beginning-க்கு கொண்டு போகும்

🔹 \t (tab) என்ன செய்கிறது?
printf("You\tmust\tbe\tcrazy");


👉 \t = tab

Tab எப்படி வேலை செய்கிறது?

Screen = 80 columns

8 columns = 1 tab zone

Cursor next zone beginning-க்கு jump ஆகும்

Example:

Cursor at column 5

\t print பண்ணினா → column 8-க்கு போகும்

📌 \t = fixed number of spaces இல்லை
👉 position-ஐ பொறுத்து move ஆகும்

🔹 Given example program
printf("You\tmust\tbe\tcrazy\nto\thate\tthis\tbook");

What happens?

\t → words align ஆகுது

\n → “crazy”க்கு பிறகு new line

Output neat-ஆ column-ல split ஆகுது

🔵 Common Escape Sequences (IMPORTANT)
Escape	Meaning
\n	New line
\t	Tab
\b	Backspace
\r	Carriage return (line beginning)
\a	Alert (beep sound)
\f	Form feed (printer page)
\'	Single quote
\"	Double quote
\\	Backslash
🔹 Quotes & backslash print பண்ணணும்னா?

Normally:

" → string delimiter

' → char delimiter

\ → escape start

So escape பண்ணணும் 👇

printf("He said, \"Let's do it!\"");


Output:

He said, "Let's do it!"

🔴 VERY IMPORTANT CONCEPT (advanced but useful)

printf()-க்கு type strictness இல்லை

அது:

நீங்க சொன்ன format-ஐ try பண்ணும்

“best effort” output தரும்

Example (useful case)
printf("%d", 'A');


Output:

65


👉 'A' ASCII value = 65
👉 %d integer-ஆ print பண்ணுது

Example (nonsense case ❌)
printf("%d", "Hello");


👉 string address-ஐ integer-ஆ interpret பண்ணும்
👉 garbage value / crash கூட ஆகலாம்

⚠️ Dangerous case (program blow up)

Wrong format specifier

Wrong argument type

Memory misuse

👉 Undefined Behavior

🧠 One-line summary

Escape sequences = \ + special meaning character

\n, \t most commonly used

\t = tab stop, not fixed spaces

Quotes & backslash print பண்ண escape தேவை

printf() type mismatch sometimes useful, sometimes dangerous