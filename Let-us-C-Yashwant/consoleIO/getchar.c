#include <stdio.h>

int main(void)
{
    int ch;
    printf("continue (y/n): ");
    ch = getchar(); //read one char from keyboard
    if(ch=='y' || ch =='y')
       printf("you chose YES\n");
    else 
       printf("You chose NO\n");
       
    return 0;   

}