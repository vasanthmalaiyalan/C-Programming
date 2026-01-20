#include<stdio.h>
//with logical operators
// && => operator only allow 2nrumay true va erruntha tha true mathathu ellam false
// || => operator ethavathu true va errunthalay true tha
int main()
{
    char sex,ms;
    int age;
    printf("Enter age, sex, martial status: ");
    scanf("%d %c %c",&age,&sex,&ms);

    if((ms=='M') || (ms=='U'&&sex=='M'&&age>30) || (ms=='U'&&sex=='F'&&age>25))
    printf("Driver is insured");
    else{
        printf("Driver is not insured");
    }
}