#include <stdio.h>
#include <stdlib.h>

// Define structure
struct StudentInfo
{
    int rollNo;
    char fullName[50];
    float marks;
};

int main()
{
    int totalStudents;
    
    printf("Enter number of students: ");
    scanf("%d", &totalStudents);

    if (totalStudents <= 0)
    {
        printf("Invalid number of students!\n");
        return 1;
    }

    // Dynamic allocation for structure array
    struct StudentInfo *records;
    records = (struct StudentInfo *)malloc(totalStudents * sizeof(struct StudentInfo));

    if (records == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input student details
    for (int i = 0; i < totalStudents; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);
        
        printf("Roll Number: ");
        scanf("%d", &records[i].rollNo);

        printf("Name: ");
        scanf(" %[^\n]", records[i].fullName);  // read full name with spaces

        printf("Marks: ");
        scanf("%f", &records[i].marks);
    }

    // Display student details
    printf("\n===== Student Records =====\n");

    for (int i = 0; i < totalStudents; i++)
    {
        printf("\nStudent %d Details:\n", i + 1);
        printf("Roll No  : %d\n", records[i].rollNo);
        printf("Name     : %s\n", records[i].fullName);
        printf("Marks    : %.2f\n", records[i].marks);
    }

    // Free allocated memory
    free(records);
    records = NULL;

    printf("\nMemory released successfully.\n");

    return 0;
}
