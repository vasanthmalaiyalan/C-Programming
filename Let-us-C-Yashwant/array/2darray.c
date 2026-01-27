#include<stdio.h>

int main()
{
    int stud[4][2]; // 4 students, each has (roll, marks)
    int i,j;

    for(i=0;i<=3;i++)
    {
        printf("Enter roll number and marks for student %d:",i+1);
        scanf("%d %d",&stud[i][0],&stud[i][1]);
    }
        printf("\n--- Student Data ---\n");
    for(i=0;i<=3;i++)
        printf("Student %d -> Roll: %d , Marks: %d\n",i+1,stud[i][0],stud[i][1]);
}