#include<stdio.h>
int main()
{
    //integer types
    short int s_signed = -10;
    unsigned short int s_unsigned = 10;
    long int l_signed = -123456;
    unsigned long int l_unsigned = 123456;
    int num = 100;

    //real numbers
    float f = 3.132422f;
    double d = 2.33456321456890;

    //character 
    char ch_signed = 'A';
    unsigned char ch_unsigned = 'B';

    printf("Integer format specifiers\n");
    printf("short signed   (%%d / %%i) : %d / %i\n",s_signed,s_signed);
    printf("short unsigned (%%u)       : %u\n",s_unsigned);
    printf("long signed    (%%ld)      : %ld\n",l_signed);
    printf("long unsigned  (%%lu)      : %lu\n",l_unsigned);
    printf("hexadecimal     (%%x)      : %x\n",num);
    printf("octal           (%%o)      : %o\n",num);

    printf("\nReal numbers (floating points)\n");
    printf("float           (%%f)      : %f\n",f);
    printf("double          (%%lf)     : %lf\n",d);

    printf("\n character\n");
    printf("signed char      (%%c)     : %c\n",ch_signed);
    printf("unsigned char    (%%c)     : %c\n",ch_unsigned);

    return 0;

}