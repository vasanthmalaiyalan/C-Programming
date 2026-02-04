#include<stdio.h>
#include<string.h>
void xstrcpy( char * ,char *);

int main(void)
{
    char source[]="hello";
    char target[10];

    xstrcpy(target,source);//inside data store of target belike target[0]='h',target[1]='e'
    printf("source string = %s\n",source);
    printf("target string = %s\n",target);
}
void xstrcpy(char *t ,char *s)// sums type of function only return value int uses so another no return value use void
{
    while(*s!='\0')
    {
        *t=*s;// inside s -> belike s=&source[0] -> *s=source[0]
        s++;
        t++;
    }
    *t='\0';// use '\0' means %s understand this is string so you didn't '\0' use, %s extra garpage value add and crash
}

/*
ஆமாம் 👍 நீ சொல்றது 100% correct தான்.
இப்ப இதை index-level + pointer-level இரண்டு angle-ல super clear-ஆ சொல்லுறேன்.

1️⃣ Copy loop – index view (உன் சொல்லும் மாதிரி)

Code:

while (*s != '\0')
{
    *t = *s;
    s++;
    t++;
}
*t = '\0';

Internally (index perspective):
Iteration	source index	target index	Action
1	source[0] = 'h'	target[0]	target[0] = source[0]
2	source[1] = 'e'	target[1]	target[1] = source[1]
3	source[2] = 'l'	target[2]	target[2] = source[2]
4	source[3] = 'l'	target[3]	target[3] = source[3]
5	source[4] = 'o'	target[4]	target[4] = source[4]
end	source[5] = '\0'	target[5]	target[5] = '\0'

👉 Exactly:

target[0] = 'h';
target[1] = 'e';
target[2] = 'l';
target[3] = 'l';
target[4] = 'o';
target[5] = '\0';

2️⃣ Memory after copy (REAL picture)
source[] : [h][e][l][l][o][\0]
target[] : [h][e][l][l][o][\0]


👉 Data array-க்குள்ளே store ஆகி விட்டது
👉 Pointer இப்ப work முடிச்சுட்டது

3️⃣ இப்ப %s எப்படி print பண்ணுது?

Code:

printf("%s", target);

Step 1: target pass ஆகும்

👉 target → &target[0] (address)

Step 2: %s internal behavior

Conceptually %s இப்படித்தான் வேலை செய்யும்:

char *p = target;   // &target[0]

while (*p != '\0')
{
    putchar(*p);
    p++;
}

4️⃣ %s prints index-by-index
Pointer points to	Same as	Printed
p	target[0]	h
p+1	target[1]	e
p+2	target[2]	l
p+3	target[3]	l
p+4	target[4]	o
p+5	target[5]	\0 → STOP
🔥 KEY FINAL CLARITY (THIS IS IT)

Copy time-ல் pointer use ஆகுது
Data array-க்குள்ளே store ஆகுது
Print time-ல் %s pointer-ஆ walk பண்ணி array data-ஐ read பண்ணுது

5️⃣ One sentence that locks everything

Pointers are used to MOVE; arrays are used to STORE; %s uses pointer movement to READ stored data.

🧾 Exam-ready line

Characters are copied element by element into the target array, and %s prints them by traversing the array using a pointer until the null character is reached.
*/