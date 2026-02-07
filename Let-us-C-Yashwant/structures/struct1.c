 #include<stdio.h>
 
 int main()
 {
    struct book //declaration of structure
    {
        char name;//only work in one charater like A,B,C
        float price;
        int pages;
    };
    struct book b1,b2,b3;//structure variable create

    printf("Enter names ,price & no.of pages of books\n");
    scanf(" %c %f %d",&b1.name,&b1.price,&b1.pages);
    scanf(" %c %f %d",&b2.name,&b2.price,&b2.pages);
    scanf(" %c %f %d",&b3.name,&b3.price,&b3.pages);

    printf("And you this is what you entered");
    printf(" %c %f %d\n",b1.name,b1.price,b1.pages);
    printf(" %c %f %d\n",b2.name,b2.price,b2.pages);
    printf(" %c %f %d\n",b3.name,b3.price,b3.pages);
 }