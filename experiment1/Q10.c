#include <stdio.h>
#include <stdlib.h>

// Structure for student data
typedef struct
{
    int roll;
    char name[50];
    float marks;
} Student;

// Function to sort students by marks (ascending order)
void sortByMarks(Student *arr, int n)
{
    Student temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].marks > arr[j].marks)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    Student *list = NULL;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Dynamic allocation
    list = (Student *)malloc(n * sizeof(Student));

    if (list == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input details
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &list[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", list[i].name);

        printf("Marks: ");
        scanf("%f", &list[i].marks);
    }

    // Sort records
    sortByMarks(list, n);

    // Display sorted data
    printf("\n--- Students Sorted by Marks (Ascending) ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nRoll  : %d", list[i].roll);
        printf("\nName  : %s", list[i].name);
        printf("\nMarks : %.2f\n", list[i].marks);
    }

    // Free memory
    free(list);
    list = NULL;

    return 0;
}
