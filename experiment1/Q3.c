#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int *numbers = NULL;

    printf("Enter total number of elements: ");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("Invalid size!\n");
        return 1;
    }

    // Allocate memory dynamically
    numbers = (int *)malloc(count * sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements
    for (int i = 0; i < count; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", numbers + i);   // pointer arithmetic used
    }

    // Initialize largest and smallest
    int max = numbers[0];
    int min = numbers[0];

    // Find largest and smallest
    for (int i = 1; i < count; i++)
    {
        if (*(numbers + i) > max)
            max = *(numbers + i);

        if (*(numbers + i) < min)
            min = *(numbers + i);
    }

    printf("\nLargest element = %d\n", max);
    printf("Smallest element = %d\n", min);

    // Free allocated memory
    free(numbers);
    numbers = NULL;

    return 0;
}
