#include<stdio.h>

int main()
{
    struct book
    {
        char name;
        float price;
        int pages;
    };
    struct book b1={'B',13.00,550};
    printf("Address of name = %p size of name: %lu\n",(void *)&b1.name,sizeof(b1.name));//%p expects a pointer,void * is used because it represents a generic address without type information.
    printf("Address of price = %p size of price: %lu\n",(void *)&b1.price,sizeof(b1.price));
    printf("Adress of pages = %p size of pages: %lu\n",(void *)&b1.pages,sizeof(b1.pages));
}

/*
உங்க thought-ஐ சரியான வார்த்தையில் சொன்னால்

%p ஒரு pointer-ஐ expect பண்ணுது.
ஆனால் எந்த type pointer என்று தெரியாததால்,
standard-ஆ void *-ஐ common pointer type-ஆ fix பண்ணியிருக்காங்க.
அதனால தான் (void *) cast செய்றோம்.

👉 இந்த understanding correct ✅

C standard என்ன சொல்றது?
printf prototype:
int printf(const char *format, ...);

%p format rule:

The argument shall be a pointer to void.

அதாவது:

printf("%p", ??? );   // ??? must be void *

ஏன் void * தான்?
Reason 1: Address = type-independent

Address என்பது:

int address

float address

struct address
எல்லாமே same concept

👉 Type matter இல்ல
👉 Only memory location matter

Reason 2: void * = generic pointer

void * can hold:

int *

float *

char *

struct *

👉 So universal pointer representation

Reason 3: Portability

Different systems:

32-bit

64-bit

weird architectures

👉 %p + void * ensures:

correct size

correct format

safe printing

Why not allow int * directly?

Technically:

printf("%p", &x);


👉 Many compilers accept
👉 But C standard does NOT guarantee

✔️ Standard-correct:

printf("%p", (void *)&x);

Mental model 🧠

%p doesn't care what the pointer points to.
It only wants a raw address.
void * is the “raw address” type in C.

Analogy (real-world)

%d → “give me a number”

%s → “give me a string”

%p → “give me an address”

But %p says:

“Give me the address without caring what it points to”

👉 That’s void *

One-line exam-perfect answer ✍️

%p expects a void * argument because void * is a generic pointer type capable of representing the address of any data object.

Final verdict

✔️ Yes, நீங்க எடுத்துக்கொண்ட explanation logically correct
✔️ Just add this clarity:

%p expects a pointer,
void * is used because it represents a generic address without type information.
*/