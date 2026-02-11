#include<stdio.h>
int main(void)
{
    char name[20];

    printf("Enter the name : ");
    fgets(name,sizeof(name),stdin);

    printf("you enter: %s",name);
    return 0;
}

//=======xஅதாவது நாம் வேல்யூ என்டர் செய்யும் போதுfgets(name, sizeof(name), stdin);sizeof(name) பயன்படுத்தும் போது நாம் எவ்வளவு டைப் செய்கிறோமோ அதற்கான இடத்தை இது ஒதுக்கி விடுமா புரோகிராம் running-ங்கில் இது sizeof(name),ஒதுக்கி விடுமா மேலும் stdin என்பது keyboard -டில் இருந்து இன்புட் வாங்கு என்று அர்த்தம் அதுதானே?x=========x=========x=========x=========x=

/*
ரொம்ப நல்ல கேள்வி 👍
இங்க இரண்டு முக்கியமான misunderstandings இருக்கு — அதை clear பண்ணுறேன்.

🔑 First: sizeof(name) என்ன செய்கிறது?
Code:
char name[20];
fgets(name, sizeof(name), stdin);

❌ Important Correction

sizeof(name) runtime-ல் memory allocate பண்ணாது ❌

Memory already allocate ஆகி இருக்கும்:

char name[20];


👉 Program compile ஆகும்போது
👉 name-க்கு 20 bytes fixed-ஆ reserve ஆகும்

✅ sizeof(name) என்ன செய்கிறது?
sizeof(name)


👉 Compile-time-ல்
👉 அந்த array-ன் total size (20) return பண்ணும்

👉 fgets()-க்கு சொல்லுது:

“Maximum 20 bytes-க்கு மேல் read பண்ணாதே”

🔍 So what really happens?

Suppose user types:

Vasanth\n


Length = 8 bytes

fgets():

Maximum read = 19 characters + \0

Why 19?
Because last byte null terminator-க்கு

If user types 100 characters:

👉 Only first 19 characters store ஆகும்
👉 Rest input buffer-ல் இருக்கும்

🔑 So allocation எப்போது நடக்குது?
char name[20];


👉 இதே line-ல் memory allocate ஆகுது
👉 fgets() allocation செய்யாது
👉 Just existing memory-ல் store பண்ணும்

🔑 stdin என்ன?

Yes ✔ Correct

stdin = standard input stream

Default:

stdin → keyboard
stdout → screen
stderr → error output

🧠 Mental Model (very important)
char name[20];     → memory reserved (20 bytes)

fgets(name, 20, stdin);

→ keyboard-ல இருந்து read
→ max 19 chars + '\0'
→ name array-ல் store

🧪 Example
char name[5];
fgets(name, sizeof(name), stdin);


User types:

HELLO


Stored in memory:

H E L L \0


👉 O leftover buffer-ல் இருக்கும்

🔴 Very Important Rule

fgets() never reallocates memory
It never increases array size
It just respects the limit you give

🏁 Final Clear Answers

❌ sizeof(name) runtime-ல் memory allocate பண்ணாது.
✅ Memory already char name[20]-ல் allocate ஆகி இருக்கும்.
✅ sizeof(name) max read limit மட்டும் define பண்ணும்.
✅ stdin default-ஆ keyboard input stream.
*/