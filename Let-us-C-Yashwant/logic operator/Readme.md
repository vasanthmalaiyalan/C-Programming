🔹 C-இல் உள்ள Logic Operators
1️⃣ AND operator (&&)

👉 இரண்டும் true ஆக இருந்தால் மட்டும் result true.

#include <stdio.h>

int main() {
    int a = 5, b = 10;

    if (a > 0 && b > 0) {
        printf("Both are positive\n");
    }
    return 0;
}


✔ a > 0 → true
✔ b > 0 → true
➡ Result: true

2️⃣ OR operator (||)

👉 ஒரு condition true இருந்தாலே போதும்.

int a = -5, b = 10;

if (a > 0 || b > 0) {
    printf("At least one is positive\n");
}


✔ a > 0 → false
✔ b > 0 → true
➡ Result: true

3️⃣ NOT operator (!)

👉 true → false, false → true (reverse பண்ணும்)

int a = 0;

if (!a) {
    printf("a is zero or false\n");
}


👉 C-ல

0 = false

non-zero = true

!0 → true

🔹 Truth Table (சுருக்கமாக)

| A | B | A && B | A || B | !A |
|---|---|--------|--------|----|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

🔹 Real-world Example
int age = 20;
int hasID = 1;

if (age >= 18 && hasID) {
    printf("Allowed to enter\n");
}


👉 Age ≥ 18 AND ID இருக்கணும்
👉 Security / Validation logic-ல ரொம்ப முக்கியம்

🔥 Interview Tip

&&, || → short-circuit evaluation

&&-ல முதல் condition falseனா, அடுத்தது check பண்ணாது

||-ல முதல் condition trueனா, அடுத்தது check பண்ணாது

==========x=================x===========x=================

ஆமாம் — C-ல if condition-க்கு
👉 non-zero (positive அல்லது negative) = true
👉 0 மட்டும் = false.

👉 “only positive means true” ❌ (சரியில்லை)
👉 “only zero means false” ✅ (இதுதான் சரி)

C Truth Rule (Golden Rule)
if (expression)


expression == 0 → false

expression != 0 → true ( +ve / −ve இரண்டும் )

உன் code-ல் என்ன நடக்குது?
int i = 4, z = 12;

if (i = 5 && z > 5)


Step by step 👇

z > 5 → 12 > 5 → true (1)

5 && 1 → true (1)

i = 1 ← ⚠️ assignment

if(1) → true

👉 அதனால் Let us C print ஆகுது

Negative number example (important!)
int x = -10;

if (x)
    printf("TRUE\n");
else
    printf("FALSE\n");


🟢 Output:

TRUE


👉 Negative number கூட true தான்

Correct comparison (safe version)
if (i == 5 && z > 5)

Interview / Bug-Hunting Tip 🔥
if (i = 0)   // always false
if (i = 5)   // always true


👉 assignment bug
👉 Real-world vulnerabilities & logic bypass இதிலிருந்து தான் வரும்

நினைவில் வை (1 line)

C-ல் TRUE = non-zero, FALSE = zero