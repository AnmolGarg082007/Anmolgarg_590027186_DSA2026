#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int totalNumbers;
    int *dataBlock = NULL;

    printf("Enter how many elements you want: ");
    scanf("%d", &totalNumbers);

    // Allocating memory dynamically
    dataBlock = (int *)malloc(totalNumbers * sizeof(int));

    if (dataBlock == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter %d integers:\n", totalNumbers);

    for (int i = 0; i < totalNumbers; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &dataBlock[i]);
    }

    printf("\nYou entered the following elements:\n");

    for (int i = 0; i < totalNumbers; i++)
    {
        printf("%d ", dataBlock[i]);
    }

    // Freeing allocated memory
    free(dataBlock);
    dataBlock = NULL;   // Avoid dangling pointer

    printf("\n\nMemory successfully released.\n");

    return 0;
}
