#include<stdio.h>

int main()
{
    int n[3][3]={
        2,4,3,
        6,8,0,
        3,5,7
    };
    int i,*ptr;
    ptr=&n[0][0];//*ptr=n; => why this one i didn't work because this is int (*)[3] 
    for(i=0;i<=8;i++)
       printf("%d\n",*(ptr+i));
}

/*
❌ Problem என்ன?
int i, *ptr;
*ptr = n;


👉 இதுதான் main mistake

ஏன் error / warning வருது?
1️⃣ ptr என்ன?
int *ptr;


👉 ptr = int value-க்கு pointer

2️⃣ n என்ன?
int n[3][3];


👉 n = 3 integers கொண்ட array-க்கு pointer
👉 type: int (*)[3]

3️⃣ *ptr = n; இதன் அர்த்தம்?

*ptr → int value

n → address (pointer)

👉 address-ஐ integer-க்குள் போடுறது ❌
அதனால தான் compiler சொல்றது:

assignment to 'int' from 'int (*)[3]'

✅ Correct approach (simple)

2D array-ஐ 1D pointer போல traverse பண்ணணும்னா:

✔️ Correct code:
int i;
int *ptr;

ptr = &n[0][0];   // first element address

for(i = 0; i < 9; i++)
    printf("%d\t", *(ptr + i));

🧠 ஏன் இது correct?

&n[0][0] → first element address

Memory-ல 2D array continuous-ஆ இருக்கும்

ptr+i → next element

Output:

2 4 3 6 8 0 3 5 7

❌ நீ பண்ணின mistake summary:

*ptr = n; ❌ (value-க்கு address assign)

Pointer-க்கு assign பண்ணணும் → ptr = ...

✅ Golden rule (remember this 🔥):

ptr = address; ✔️

*ptr = value; ✔️

*ptr = address; ❌
*/