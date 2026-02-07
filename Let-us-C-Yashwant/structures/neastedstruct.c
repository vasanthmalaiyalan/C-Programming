#include <stdio.h>

int main()
{
    struct address
    {
        char phone[15];
        char city[25];
        int pin;
    };

    struct emp
    {
        char name[25];
        struct address a;
    };

    struct emp e = {
        "jarvis", //Structure-க்குள் structure இருந்தால் inner structure-க்கு separate braces {} கட்டாயம்
        {
            "7643567234",
            "chennai",
            63
        }
    };

    printf(
        "name = %s\nphone = %s\ncity = %s\npin = %d\n",
        e.name,
        e.a.phone,
        e.a.city,
        e.a.pin
    );

    return 0;
}


/*
சரி 👍
இந்த line-ஐ line by line, memory angle-ல, beginner friendly-ஆ explain பண்ணுறேன்.

struct emp e = {
    "jarvis",
    {
        "7643567234",
        "chennai",
        63
    }
};

1️⃣ முதலில் structure definitions நினைவுக்கு கொண்டுவரலாம்
struct address
{
    char phone[15];
    char city[25];
    int pin;
};

struct emp
{
    char name[25];
    struct address a;
};


👉 struct emp-க்குள்ள 2 members இருக்கு:

name → char name[25]

a → struct address

2️⃣ இப்ப struct emp e என்றால் என்ன?
struct emp e;


👉 Memory-ல e இப்படித் தான் இருக்கும்:

e
 ├── name[25]
 └── a
      ├── phone[15]
      ├── city[25]
      └── pin

3️⃣ Initializer list { ... } என்ன சொல்றது?
struct emp e = { ... };


👉 { } உள்ள values
👉 structure-ன் member order-க்கு match ஆக assign ஆகும்

4️⃣ First value: "jarvis"
struct emp e = {
    "jarvis",
    ...
};


👉 இது assign ஆகுவது:

e.name = "jarvis";


Memory-ல:

e.name = ['j','a','r','v','i','s','\0', ...]

5️⃣ Second value: { ... } (nested braces)
{
    "7643567234",
    "chennai",
    63
}


👉 இது assign ஆகுவது:

e.a   // struct address


📌 Important rule

Structure-க்குள் structure இருந்தால்
inner structure-க்கு separate braces {} கட்டாயம்

6️⃣ Inner structure mapping (very important)
struct address a =
{
    "7643567234",
    "chennai",
    63
};


Meaning:

e.a.phone = "7643567234";
e.a.city  = "chennai";
e.a.pin   = 63;

7️⃣ Complete assignment expanded form (mentally)

Compiler இதை இப்படியே நினைக்கும்:

e.name        = "jarvis";
e.a.phone     = "7643567234";
e.a.city      = "chennai";
e.a.pin       = 63;

8️⃣ Memory-ல final state 🧠
e
 ├── name  → "jarvis"
 └── a
      ├── phone → "7643567234"
      ├── city  → "chennai"
      └── pin   → 63

9️⃣ Nested braces ஏன் mandatory?

❌ இது தவறு:

struct emp e = {"jarvis","7643567234","chennai",63};


👉 Compiler confuse ஆகும்:

"7643567234" → struct address-க்கு belong ஆகுது

But braces இல்லை → error

✔️ Correct rule:

Each structure level = one {} pair

🔑 Golden rule (exam + real life)

When initializing a structure containing another structure, the inner structure must be enclosed within its own braces.

10️⃣ One-line exam answer ✍️

The initializer assigns values to structure members in order, and nested braces are used to initialize members of an inner structure.
*/