#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
typedef struct
{
    int id;
    char name[50];
    float score;
} Record;

int main()
{
    Record *data = NULL;
    int count = 0;
    int choice;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record (by ID)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Increase memory using realloc
            Record *temp = realloc(data, (count + 1) * sizeof(Record));

            if (temp == NULL)
            {
                printf("Memory allocation failed!\n");
                continue;
            }

            data = temp;

            printf("\nEnter ID: ");
            scanf("%d", &data[count].id);

            printf("Enter Name: ");
            scanf(" %[^\n]", data[count].name);

            printf("Enter Score: ");
            scanf("%f", &data[count].score);

            count++;
            printf("Record added successfully!\n");
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No records available.\n");
            }
            else
            {
                printf("\n--- Stored Records ---\n");
                for (int i = 0; i < count; i++)
                {
                    printf("\nID: %d", data[i].id);
                    printf("\nName: %s", data[i].name);
                    printf("\nScore: %.2f\n", data[i].score);
                }
            }
        }

        else if (choice == 3)
        {
            if (count == 0)
            {
                printf("No records to delete.\n");
                continue;
            }

            int searchId, found = -1;
            printf("Enter ID to delete: ");
            scanf("%d", &searchId);

            for (int i = 0; i < count; i++)
            {
                if (data[i].id == searchId)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("Record not found.\n");
            }
            else
            {
                // Shift elements left
                for (int i = found; i < count - 1; i++)
                {
                    data[i] = data[i + 1];
                }

                count--;

                // Resize memory
                data = realloc(data, count * sizeof(Record));
                printf("Record deleted successfully!\n");
            }
        }

        else if (choice == 4)
        {
            printf("Exiting program...\n");
        }

        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    // Free memory before exit
    free(data);
    data = NULL;

    printf("Memory freed successfully.\n");

    return 0;
}
