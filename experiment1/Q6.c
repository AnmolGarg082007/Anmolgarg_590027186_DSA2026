#include <stdio.h>
#include <stdlib.h>

// Structure definition
typedef struct
{
    int empId;
    char empName[60];
    float salary;
} Employee;

int main()
{
    int n;
    Employee *empList = NULL;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number!\n");
        return 1;
    }

    // Dynamic allocation for array of structures
    empList = (Employee *)malloc(n * sizeof(Employee));

    if (empList == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 1;
    }

    // Input employee details
    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &empList[i].empId);

        printf("Name: ");
        scanf(" %[^\n]", empList[i].empName);

        printf("Salary: ");
        scanf("%f", &empList[i].salary);
    }

    // Assume first employee has highest salary initially
    int highestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (empList[i].salary > empList[highestIndex].salary)
        {
            highestIndex = i;
        }
    }

    // Display all employees
    printf("\n===== Employee Details =====\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nID     : %d", empList[i].empId);
        printf("\nName   : %s", empList[i].empName);
        printf("\nSalary : %.2f\n", empList[i].salary);
    }

    // Display highest salary employee
    printf("\n===== Employee with Highest Salary =====\n");
    printf("ID     : %d\n", empList[highestIndex].empId);
    printf("Name   : %s\n", empList[highestIndex].empName);
    printf("Salary : %.2f\n", empList[highestIndex].salary);

    // Free memory
    free(empList);
    empList = NULL;

    return 0;
}
