#include<stdio.h>
struct book 
{
    char name[25];
    char author[24];
    int callno;
};
void display(struct book *);
int main()
{
    struct book b1={"Let Us C","YPK",102};
    display(&b1);
}
void display(struct book *b)
{
    printf("%s %s %d %p\n",b->name,(*b).author,b->callno,b->name);
}