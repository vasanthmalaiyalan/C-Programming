#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,y;
    char choice;
    while(1){
        printf("\n1=> addition\n2=>subtraction\n3=>Exit");
        printf("\nEnter your choice(+ or -): ");
        scanf("%d",&choice);
        if(choice<3)
        {
            printf("Enter values for x & y: ");
            scanf("%d%d",&x,&y);
        }
        switch(choice)
        {
            case 1:
                printf("Add x & y = %d\n",x+y);
                break;
            case 2:
                printf("diff x & y = %d\n",x-y);
                break;
            case 3:
                exit(1);    
            default:
                 printf("Error: choice can be + or -\n");
                 break;        
        }
    }
}