#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[30];
    int roll;
    int marks[5];
    int total;
    float percentage;
};

int main() 
{
    struct Student s[50];
    int n = 0, choice, i, j;
    
    while(1) 
    {
        printf("\n--- Student Result Management System ---\n");
        printf("1. Add Student Marks\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
           {
            case 1:
                printf("Enter student roll number: ");
                scanf("%d", &s[n].roll);
                printf("Enter student name: ");
                scanf("%s", s[n].name);

                s[n].total = 0;
                for(j = 0; j < 5; j++) 
                {
                    printf("Enter marks for subject %d: ", j+1);
                    scanf("%d", &s[n].marks[j]);
                    s[n].total += s[n].marks[j];
                }
                s[n].percentage = s[n].total / 5.0;
                n++;
                printf("Student marks added successfully!\n");
                break;

            case 2:
                if(n == 0) 
                {
                    printf("No student records found.\n");
                } 
                else 
                {
                    printf("\nResults:\n");
                    for(i = 0; i < n; i++) 
                    {
                        printf("\nRoll: %d, Name: %s\n", s[i].roll, s[i].name);
                        printf("Marks: ");
                        for(j = 0; j < 5; j++)
                            printf("%d ", s[i].marks[j]);
                        printf("\nTotal: %d, Percentage: %.2f%%", s[i].total, s[i].percentage);
                        if (s[i].percentage >= 40)
                        {
                         printf("\nStatus: Pass\n");
                        }
                        else
                        {
                         printf("\nStatus: Fail\n");
                        }
                    }
                }
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

