#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("mycsv.csv","w");
    int no=123;
    char name[] = "vasanth";
    int exp = 18;
    fprintf(fp,"NO., NAME, EXP\n");
    fprintf(fp,"%d, %s, %d\n",no,name,exp);
    fclose(fp);
}