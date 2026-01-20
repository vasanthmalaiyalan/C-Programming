#include <stdio.h>
int main()
{
    int a[] = {10,20};
    char c = 'v';
    int i;
    int *p;
    char *cp;

    p = a;      // p points to first element of int array
    cp = &c;    // cp points to char variable

    printf("Data in int pointer p : %d in address %p", *p, p);

    for(i=0; i<2; i++)
    {
        printf("\nData in int array via p: %d in address %p\n", *(p+i), (p+i));
    }

    printf("\nData in char pointer cp : %c in address %p\n", *cp, cp);

    return 0;
}